#pragma once

#include <set>
#include <vector>
#include <cstdint>
#include "qgraph_enum.h"
#include "qgraph_proto.h"
#include "qgraph_visitor.h"
#include <boost/bimap.hpp>

class graph_prune_base : public graph_visitor {

	std::vector<bool> m_hit;
	std::vector<std::vector<bool>> m_arg_hit;
	std::vector<std::set<uint64_t>> m_used_input;
	std::vector<std::vector<lifecycle>> m_lifecycle;
	std::vector<std::map<uint64_t, uint64_t>> m_assign_map;


	const std::vector<Operation>& m_ops_orig;
	const std::vector<std::vector<lifecycle>>& m_lifecycle_orig;

	std::vector<unsigned short> get_signature(const lifecycle& lc) const;

	void generic_record_data(DataType dt, uint64_t x_i);

	void record_generic_input(DataType dt, uint64_t x_i);
	void record_generic_output(DataType dt, uint64_t r_i, uint64_t n);

	void record_scalar(uint64_t x_i);
	void record_scalar_input(uint64_t x_i);
	void record_scalar_output(uint64_t r_i, uint64_t n);

	void record_boolean(uint64_t x_i);
	void record_boolean_input(uint64_t x_i);
	void record_boolean_output(uint64_t r_i, uint64_t n);

	void record_integer(uint64_t x_i);
	void record_integer_input(uint64_t x_i);
	void record_integer_output(uint64_t r_i, uint64_t n);

	void record_operation(Operation op);


	uint64_t now() const;
	uint64_t index() const;

	virtual uint64_t scalar_index(DataType dt, uint64_t i) { return i; }

protected:

	std::vector<Operation> m_ops;
	std::vector<uint64_t> m_ops_arg_index;
	std::vector<uint64_t> m_checkpoint_ops_index;
	std::vector<uint64_t> m_checkpoint_ops_arg_index;

	void init_assign_map(const std::vector<std::map<uint64_t, uint64_t>>& assign_map);

public:

	graph_prune_base(const std::vector<Operation>& ops,
		const std::vector<uint64_t>& ops_arg_index,
		const boost::bimap<uint64_t, uint64_t>& output_map,
		const std::vector<std::vector<lifecycle>>& lifecycle,
		const std::vector<uint64_t>& checkpoint_ops_index);

	~graph_prune_base() {}

	void process_func1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_func2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_func2_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void process_func2_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	void process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i);

	void process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i);
	void process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i);
	void process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

	void process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i);
	void process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

	void swap(
		std::vector<Operation>& ops, 
		std::vector<uint64_t>& ops_arg_index, 
		std::vector<std::vector<lifecycle>>& lifecycle,
		std::map<uint64_t, uint64_t>& assign_map,
		std::vector<uint64_t>& checkpoint_ops_index,
		std::vector<uint64_t>& checkpoint_ops_arg_index,
		std::vector<std::map<uint64_t, uint64_t>>& variable_map
	);

	const std::vector<std::vector<bool>>& get_arg_hit() const { return m_arg_hit; }

	void checkpoint(uint64_t clock, Operation op);

};

#include "qgraph_i.h"

template<class T>
class graph_prune : public graph_prune_base
{
	const std::vector<typename graph_traits<T>::scalar_type>& m_scalar;
	std::map<typename graph_traits<T>::scalar_type_map, uint64_t> m_scalar_map;

	const std::vector<typename graph_traits<T>::integer_type>& m_integer;
	std::map<typename graph_traits<T>::integer_type, uint64_t, integer_type_predicate<T>> m_integer_map;

	const std::vector<typename graph_traits<T>::boolean_type>& m_boolean;
	std::map<typename graph_traits<T>::boolean_type, uint64_t> m_boolean_map;

	uint64_t scalar_index(DataType dt, uint64_t i)
	{
		switch (dt)
		{
			case QFLOATING_POINT:
			{
				const typename graph_traits<T>::scalar_type& x = m_scalar[i];
				auto it = m_scalar_map.find(x);
				size_t idx;
				if (it == m_scalar_map.end())
					m_scalar_map.insert({ x , idx = m_scalar_map.size() });
				else
					idx = it->second;
				return idx;
			}
			case QINTEGER:
			{
				const typename graph_traits<T>::integer_type& x = m_integer[i];
				auto it = m_integer_map.find(x);
				size_t idx;
				if (it == m_integer_map.end())
					m_integer_map.insert({ x , idx = m_integer_map.size() });
				else
					idx = it->second;
				return idx;
			}
			case QBOOLEAN:
			{
				const typename graph_traits<T>::boolean_type& x = m_boolean[i];
				auto it = m_boolean_map.find(x);
				size_t idx;
				if (it == m_boolean_map.end())
					m_boolean_map.insert({ x , idx = m_boolean_map.size() });
				else
					idx = it->second;
				return idx;
			}
		}
		return (uint64_t)-1;
	}

public:

	graph_prune(const qgraph_i<T>& g) :
		graph_prune_base(g.get_ops(), g.get_ops_arg_index(), g.get_output_map()[0], g.get_lifecycle(), g.get_checkpoint_ops_index()),
		m_scalar(g.get_scalar()),
		m_integer(g.get_integer()),
		m_boolean(g.get_boolean())
	{
		init_assign_map(g.get_assign_map());
		g.sweep_forward(*this);

		m_checkpoint_ops_index.insert(m_checkpoint_ops_index.begin(), 0);
		m_checkpoint_ops_arg_index.insert(m_checkpoint_ops_arg_index.begin(), 0);

		if (m_ops[m_ops.size() - 1] != CHECKPOINT)
		{
			m_checkpoint_ops_index.push_back(m_ops.size());
			m_checkpoint_ops_arg_index.push_back(m_ops_arg_index.size());
		}

	}

	~graph_prune() {}

	void swap(qgraph_i<T>& g)
	{
		graph_prune_base::swap(g.get_ops(), g.get_ops_arg_index(), g.get_lifecycle(), g.get_assign_map()[0], g.get_checkpoint_ops_index(), g.get_checkpoint_ops_arg_index(), g.get_all_variable_map());

		auto& scalar = g.get_scalar();
		scalar.clear();
		scalar.resize(m_scalar_map.size());
		for (auto it = m_scalar_map.begin(); it != m_scalar_map.end(); ++it)
			scalar[it->second] = it->first;
		g.get_scalar_map().swap(m_scalar_map);

		auto& integer = g.get_integer();
		integer.clear();
		integer.resize(m_integer_map.size());
		for (auto it = m_integer_map.begin(); it != m_integer_map.end(); ++it)
			integer[it->second] = it->first;
		g.get_integer_map().swap(m_integer_map);

		auto& boolean = g.get_boolean();
		boolean.clear();
		boolean.resize(m_boolean_map.size());
		for (auto it = m_boolean_map.begin(); it != m_boolean_map.end(); ++it)
			boolean[it->second] = it->first;
		g.get_boolean_map().swap(m_boolean_map);

	}

};

