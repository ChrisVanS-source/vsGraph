#include "qgraph_remap.h"
#include <algorithm>

graph_remap::graph_remap(const std::vector<lifecycle>& lc, const std::vector<bool>& arg_hit) : 
	
	m_var_counter(lc.size()),
	m_n_nonparam(0),
	m_n_nonparam_hit(0)
{
	for (uint64_t i = 0; i < lc.size(); ++i)
	{
		if (!lc[i].is_param())
		{

			++m_n_nonparam;
			if (arg_hit.size() == 0 || arg_hit[i])
				++m_n_nonparam_hit;

		}

	}

	m_param_remap.resize(m_var_counter);

	uint64_t offset_nonparam_hit = 0;
	uint64_t offset_nonparam = m_n_nonparam_hit;
	uint64_t offset_param = m_n_nonparam;

	uint64_t new_idx, n_unused = 0;

	m_param_remap.resize(m_var_counter);

	for (uint64_t i = 0; i < m_var_counter; ++i) if (lc[i].first_used() != (uint64_t)-1) {

		if (lc[i].is_param())
			new_idx = offset_param++;
		else
		{
			if (arg_hit.size() == 0 || arg_hit[i])
				new_idx = offset_nonparam_hit++;
			else
				new_idx = offset_nonparam++;
		}

		m_param_remap[i] = new_idx;

	}
	else
	{
		++n_unused;
		m_param_remap[i] = (uint64_t)-1;
	}

	m_var_counter -= n_unused;
}

graph_remap::~graph_remap()
{
}

void graph_remap::process_func1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(m_param_remap[r_i]);

//	x_i = m_param_remap[x_i];
//	r_i = m_param_remap[r_i];
}

void graph_remap::process_func2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(m_param_remap[y_i]);
	m_ops_arg_index.push_back(m_param_remap[r_i]);

//	x_i = m_param_remap[x_i];
//	y_i = m_param_remap[y_i];
//	r_i = m_param_remap[r_i];
}

void graph_remap::process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(m_param_remap[y_i]);
	m_ops_arg_index.push_back(r_i);

	//	x_i = m_param_remap[x_i];
	//	y_i = m_param_remap[y_i];
	//	r_i = m_param_remap[r_i];
}


void graph_remap::process_func2_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(m_param_remap[y_i]);
	m_ops_arg_index.push_back(m_param_remap[r_i]);

//	y_i = m_param_remap[y_i];
//	r_i = m_param_remap[r_i];
}


void graph_remap::process_func2_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(m_param_remap[r_i]);

//	x_i = m_param_remap[x_i];
//	r_i = m_param_remap[r_i];
}

void graph_remap::process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);

//	x_i = m_param_remap[x_i];
}

void graph_remap::process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(m_param_remap[y_i]);
	m_ops_arg_index.push_back(m_param_remap[r_i]);
}

void graph_remap::process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(m_param_remap[x_i]);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(m_param_remap[r_i]);
}

void graph_remap::process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(m_param_remap[r_i]);
}

void graph_remap::process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);

}

void graph_remap::process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}


void graph_remap::process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}


void graph_remap::process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) 
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) 
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}

void graph_remap::process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
}


void graph_remap::remap(boost::bimap<uint64_t, uint64_t>& src)
{
	boost::bimap<uint64_t, uint64_t> dst;
	for (auto it = src.left.begin(); it != src.left.end(); ++it)
		if (m_param_remap[it->second] != (uint64_t)-1)
			dst.insert({ it->first, m_param_remap[it->second] });
	src.swap(dst);

}

void graph_remap::remap(boost::bimap<uint64_t, uint64_t>& src, bool value_only, const std::vector<uint64_t>& param_remap)
{
	boost::bimap<uint64_t, uint64_t> dst;
	for (auto it = src.left.begin(); it != src.left.end(); ++it)
		if (param_remap[it->second] != (uint64_t)-1)
			dst.insert({ value_only ? it->first : param_remap[it->first], param_remap[it->second]});
	src.swap(dst);
}

void graph_remap::remap(std::map<uint64_t, uint64_t>& src, bool value_only, const std::vector<uint64_t>& param_remap)
{
	std::map<uint64_t, uint64_t> dst;
	for (auto it = src.begin(); it != src.end(); ++it)
		if (param_remap[it->second] != (uint64_t)-1 && (value_only || param_remap[it->first] != (uint64_t)-1))
			dst.insert({ value_only ? it->first : param_remap[it->first], param_remap[it->second] });
	src.swap(dst);
}

void graph_remap::remap(std::map<uint64_t, uint64_t>& src, bool value_only)
{
	std::map<uint64_t, uint64_t> dst;
	for (auto it = src.begin(); it != src.end(); ++it) 
		if (m_param_remap[it->second] != (uint64_t)-1 && (value_only || m_param_remap[it->first] != (uint64_t)-1))
			dst.insert({ value_only ? it->first : m_param_remap[it->first], m_param_remap[it->second] });
	src.swap(dst);
}

void graph_remap::remap(std::map<uint64_t, uint64_t>& src, const std::vector<uint64_t>& param_remap)
{
	std::map<uint64_t, uint64_t> dst;
	for (auto it = src.begin(); it != src.end(); ++it)
		if (param_remap[it->first] != (uint64_t)-1)
			dst.insert({ param_remap[it->first], it->second });
	src.swap(dst);
}

void graph_remap::remap(std::map<uint64_t, uint64_t>& src)
{
	remap(src, m_param_remap);
}

void graph_remap::remap(std::vector<lifecycle>& src, const uint64_t& var_counter, const std::vector<uint64_t>& param_remap)
{
	std::vector<lifecycle> dst(var_counter);
	for (uint64_t i = 0; i < src.size(); ++i)
		if (param_remap[i] != (uint64_t)-1)
			dst[param_remap[i]] = src[i];
	src.swap(dst);
}

void graph_remap::remap(std::vector<lifecycle>& src)
{
	remap(src, m_var_counter, m_param_remap);
}


void graph_remap::remap(boost::bimap<std::string, uint64_t>& src, const std::vector<uint64_t>& param_remap)
{
	boost::bimap<std::string, uint64_t> dst;
	for (auto it = src.left.begin(); it != src.left.end(); ++it)
		if (param_remap[it->second] != (uint64_t)-1)
			dst.insert({ it->first, param_remap[it->second] });
	src.swap(dst);
}

void graph_remap::remap(boost::bimap<std::string, uint64_t>& src)
{
	remap(src, m_param_remap);
}

#include "qexception.h"
using namespace vstech;

void graph_remap::swap(std::vector<uint64_t>& ops_arg_index)
{
	ops_arg_index.swap(m_ops_arg_index);
}


void graph_remap::swap(

	std::vector<uint64_t>& ops_arg_index,
	uint64_t& var_counter,
	uint64_t& n_nonparam,
	std::vector<lifecycle>& lc,
	std::map<uint64_t, uint64_t>& assign_map,
	boost::bimap<uint64_t, uint64_t>& input_map,
	boost::bimap<uint64_t, uint64_t>& output_map,
	std::map<uint64_t, uint64_t>& input_output_map,
	std::map<uint64_t, uint64_t>& variable_map,
	boost::bimap<std::string, uint64_t>& m_variable_name_map,
	std::vector<uint64_t>& checkpoint_input

)
{
	ops_arg_index.swap(m_ops_arg_index);
	var_counter = m_var_counter;
	n_nonparam = m_n_nonparam;

	remap(lc);
	remap(assign_map);
	remap(input_map);
	remap(output_map);
	remap(input_output_map, false);
	remap(variable_map, true);
	remap(m_variable_name_map);

	for (uint64_t i = 0; i < checkpoint_input.size(); ++i)
		checkpoint_input[i] = m_param_remap[checkpoint_input[i]];

}

