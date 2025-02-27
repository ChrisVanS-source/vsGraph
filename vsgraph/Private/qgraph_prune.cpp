#pragma once

#include "qgraph_prune.h"

graph_prune_base::graph_prune_base(

	const std::vector<Operation>& ops,
	const std::vector<uint64_t>& ops_arg_index,
	const boost::bimap<uint64_t, uint64_t>& output_map,
	const std::vector<std::vector<lifecycle>>& lifecycle,
	const std::vector<uint64_t>& checkpoint_ops_index

) : m_ops_orig(ops), m_lifecycle_orig(lifecycle), m_lifecycle(NUMBER_OF_TYPES), m_arg_hit(NUMBER_OF_TYPES), m_used_input(NUMBER_OF_TYPES), m_assign_map(NUMBER_OF_TYPES)
{
	m_hit.resize(ops.size());

	for (uint64_t j = 0; j < checkpoint_ops_index.size(); ++j)
	{
		const uint64_t& ci = checkpoint_ops_index[j];
		if (ci < m_ops.size() && m_ops[ci] == CHECKPOINT)
			m_hit[ci] = true;
	}

	for (uint64_t j = 0; j < m_arg_hit.size(); ++j)
		m_arg_hit[j].resize(m_lifecycle_orig[j].size(), false);
	
	for (auto it = output_map.left.begin(); it != output_map.left.end(); ++it)
	{
		// Find number of children of output, now assumed to be a qscalar<T> so indexed 0

		std::vector<size_t> i, n;

		std::vector<std::vector<unsigned short>> signature;

		if (m_lifecycle_orig[0][it->second].last_index() == (size_t)-1)
		{
			i.resize(1, 0);
			n.resize(1, 0);
		}
		else
		{
			// Assume output is qscalar<T>, could relax later

			const auto& lc = m_lifecycle_orig[0][it->second];

			m_arg_hit[0][it->second] = true;

			m_hit[lc.created()] = true;

			signature.resize(1, get_signature(lc));
			i.resize(1, lc.last_index() + 1 - signature[0].size());
			n.resize(1, lc.last_index() - signature[0].back());
		}

		size_t depth = 0;

		while (true)
		{
			while (i[depth] < n[depth]) {

				// Initially, as per above n[depth] - i[depth] = signature[depth].size()-1-signature[depth].back()
				// Therefore signature[depth].size() + i[depth] - n[depth] - 1 - signature[depth].back() = 0 and as i[depth] increases, we start at 0 and go through the inputs

				size_t ii = signature[depth].size() + i[depth] - n[depth] - 1 - signature[depth].back();

				while (signature[depth][ii] > 2 && i[depth] < n[depth]) // Skip scalar, int, bool
				{
					++i[depth];
					++ii;
				}

				if (i[depth] == n[depth])
					break;

				uint64_t index = m_lifecycle_orig[signature[depth][ii]][ops_arg_index[i[depth]]].last_index();

				if (index == (size_t)-1)
				{
					uint64_t arg_idx = ops_arg_index[i[depth]++];
					m_used_input[signature[depth][ii]].insert(arg_idx); // Input terminal - go to next input
					m_arg_hit[signature[depth][ii]][arg_idx] = true;
				}
				else
					while (index != (size_t)-1)
					{
						uint64_t arg_idx = ops_arg_index[i[depth]];
						const auto& lc = m_lifecycle_orig[signature[depth][ii]][arg_idx];
						m_arg_hit[signature[depth][ii]][arg_idx] = true;
						size_t created = lc.created();

						auto fs = get_signature(lc);

						if (fs.size() == fs.back() + 1 || m_hit[created]) // No input, can be assign
						{
							m_hit[created] = true;
							++i[depth];
							break;
						}

						// Input is not terminal - go deeper in valuation tree

						m_hit[created] = true;

						if (++depth >= i.size())
						{
							signature.push_back(fs);
							i.push_back(index + 1 - signature.back().size());
							n.push_back(index - signature.back().back());
						}

						ii = signature[depth].size() + i[depth] - n[depth] - 1 - signature[depth].back();

						while (signature[depth][ii] > 2 && i[depth] < n[depth]) // Skip scalar, int, bool
						{
							++i[depth];
							++ii;
						}

						if (i[depth] == n[depth])
							break;

						index = m_lifecycle_orig[signature[depth][ii]][ops_arg_index[i[depth]]].last_index();

					}
			}
			if (depth == 0)
				break;
			if (i[depth] == n[depth])
			{
				i.pop_back();
				n.pop_back();
				signature.pop_back();
				++i[--depth];
			}
			else
				--depth;
		}

	}

}

void graph_prune_base::init_assign_map(const std::vector<std::map<uint64_t, uint64_t>>& assign_map)
{
	for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
		for (auto it = assign_map[dt].begin(); it != assign_map[dt].end(); ++it)
			if (m_used_input[dt].find(it->first) != m_used_input[dt].end())
				m_assign_map[dt][it->first] = scalar_index(dt, it->second);
}

uint64_t graph_prune_base::now() const
{
	return m_ops.size();
}

uint64_t graph_prune_base::index() const
{
	return m_ops_arg_index.size();
}

void graph_prune_base::record_generic_input(DataType dt, uint64_t x_i)
{
	m_ops_arg_index.push_back(x_i);
	if (m_lifecycle[dt].size() <= x_i)
		m_lifecycle[dt].resize(x_i + 1);
	lifecycle& lc = m_lifecycle[dt][x_i];
	if (dt == QFLOATING_POINT)
		lc.is_param() = m_lifecycle_orig[dt][x_i].is_param();
	uint64_t clock = now();
	if (lc.first_used() == (uint64_t)-1)
		lc.first_used() = clock;
	lc.last_used() = clock;
}

void graph_prune_base::record_scalar_input(uint64_t x_i)
{
	record_generic_input(QFLOATING_POINT, x_i);
}

void graph_prune_base::record_integer_input(uint64_t x_i)
{
	record_generic_input(QINTEGER, x_i);
}

void graph_prune_base::record_boolean_input(uint64_t x_i)
{
	record_generic_input(QBOOLEAN, x_i);
}

void graph_prune_base::record_generic_output(DataType dt, uint64_t r_i, uint64_t n)
{
	m_ops_arg_index.push_back(r_i);
	if (m_lifecycle[dt].size() <= r_i)
		m_lifecycle[dt].resize(r_i + 1);
	lifecycle& lc = m_lifecycle[dt][r_i];
	if (dt == QFLOATING_POINT)
		lc.is_param() = m_lifecycle_orig[dt][r_i].is_param();
	lc.created() = now();
	lc.first_index() = (lc.last_index() = index()) - n;
}


void graph_prune_base::record_scalar_output(uint64_t r_i, uint64_t n)
{
	record_generic_output(QFLOATING_POINT, r_i, n);
}

void graph_prune_base::record_integer_output(uint64_t r_i, uint64_t n)
{
	record_generic_output(QINTEGER, r_i, n);
}


void graph_prune_base::record_boolean_output(uint64_t r_i, uint64_t n)
{
	record_generic_output(QBOOLEAN, r_i, n);
}

void graph_prune_base::record_operation(Operation op)
{
	m_ops.push_back(op);
}

void graph_prune_base::generic_record_data(DataType dt, uint64_t i)
{
	m_ops_arg_index.push_back(scalar_index(dt, i));
}


void graph_prune_base::record_scalar(uint64_t i)
{
	generic_record_data(QFLOATING_POINT, i);
}

void graph_prune_base::record_integer(uint64_t i)
{
	generic_record_data(QINTEGER, i);
}

void graph_prune_base::record_boolean(uint64_t i)
{
	generic_record_data(QBOOLEAN, i);
}

void graph_prune_base::checkpoint(uint64_t clock, Operation op)
{
	if (m_ops.size() == 0 || m_ops.back() == CHECKPOINT)
		return;

	record_operation(op);
	m_checkpoint_ops_index.push_back(m_ops.size());
	m_checkpoint_ops_arg_index.push_back(m_ops_arg_index.size());
}

void graph_prune_base::process_func1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (!m_hit[clock]) return;

	record_scalar_input(x_i);
	record_scalar_output(r_i, 2);
	record_operation(op);
}

void graph_prune_base::process_func2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_scalar_input(x_i);
	record_scalar_input(y_i);
	record_scalar_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_func2_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_scalar(x_i);
	record_scalar_input(y_i);
	record_scalar_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_func2_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_scalar_input(x_i);
	record_scalar(y_i);
	record_scalar_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_scalar_input(x_i);
	record_scalar_input(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_scalar_input(x_i);
	record_scalar(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_scalar_input(x_i);
	record_scalar_input(y_i);
	record_scalar_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_scalar_input(x_i);
	record_scalar(y_i);
	record_scalar_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_scalar(x_i);
	record_scalar(y_i);
	record_scalar_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) 
{
	if (!m_hit[clock]) return;

	record_integer_input(x_i);
	record_integer_output(r_i, 2);
	record_operation(op);
}

void graph_prune_base::process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_integer_input(x_i);
	record_integer_input(y_i);
	record_integer_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_integer(x_i);
	record_integer_input(y_i);
	record_integer_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_integer_input(x_i);
	record_integer(y_i);
	record_integer_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_integer_input(x_i);
	record_integer_input(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_integer_input(x_i);
	record_integer(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_integer_input(x_i);
	record_integer_input(y_i);
	record_integer_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_integer_input(x_i);
	record_integer(y_i);
	record_integer_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_integer(x_i);
	record_integer(y_i);
	record_integer_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(x_i);
	record_boolean_output(r_i, 2);
	record_operation(op);
}

void graph_prune_base::process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_boolean_input(x_i);
	record_boolean_input(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(x_i);
	record_boolean(y_i);
	record_boolean_output(r_i, 3);
	record_operation(op);
}

void graph_prune_base::process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_boolean_input(x_i);
	record_boolean_input(y_i);
	record_boolean_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_boolean_input(x_i);
	record_boolean(y_i);
	record_boolean_output(r_i, 4);
	record_operation(op);
}

void graph_prune_base::process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (!m_hit[clock]) return;

	record_boolean_input(c_i);
	record_boolean(x_i);
	record_boolean(y_i);
	record_boolean_output(r_i, 4);
	record_operation(op);
}


void graph_prune_base::swap(

	std::vector<Operation>& ops,
	std::vector<uint64_t>& ops_arg_index,
	std::vector<std::vector<lifecycle>>& lifecycle,
	std::map<uint64_t, uint64_t>& assign_map,
	std::vector<uint64_t>& checkpoint_ops_index,
	std::vector<uint64_t>& checkpoint_ops_arg_index,
	std::vector<std::map<uint64_t, uint64_t>>& variable_map

)
{
	ops.swap(m_ops);
	ops_arg_index.swap(m_ops_arg_index);
	lifecycle.swap(m_lifecycle);
	assign_map.swap(m_assign_map[0]);
	checkpoint_ops_index.swap(m_checkpoint_ops_index);
	checkpoint_ops_arg_index.swap(m_checkpoint_ops_arg_index);

	std::vector<std::map<uint64_t, uint64_t>> vmap(NUMBER_OF_TYPES);

	for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
		for (auto it = variable_map[dt].begin(); it != variable_map[dt].end(); ++it)
			if (m_arg_hit[dt][it->second])
				vmap[dt].insert({it->first,it->second});

	variable_map.swap(vmap);
}


