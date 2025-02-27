#pragma once
#include "qgraph_visitor.h"
#include "qgraph_proto.h"
#include <boost/bimap.hpp>
#include <vector>

class graph_remap : public graph_visitor {

	std::vector<uint64_t> m_ops_arg_index;

	std::vector<uint64_t> m_param_remap;
	uint64_t m_var_counter;
	uint64_t m_n_nonparam;
	uint64_t m_n_nonparam_hit;

	void remap(boost::bimap<uint64_t, uint64_t>& src);
	void remap(boost::bimap<std::string, uint64_t>& src);
	void remap(std::map<uint64_t, uint64_t>& src, bool value_only);
	void remap(std::map<uint64_t, uint64_t>& src); // used for assign_map
	void remap(std::vector<lifecycle>& src);

public:

	graph_remap(const std::vector<lifecycle>& lifecycle, const std::vector<bool>& arg_hit = std::vector<bool>());
	~graph_remap();

	const std::vector<uint64_t>& get_param_remap() const { return m_param_remap; }

	const uint64_t& get_n_nonparam() const { return m_n_nonparam; }


	static void remap(std::map<uint64_t, uint64_t>& src, const std::vector<uint64_t>& param_remap);
	static void remap(std::map<uint64_t, uint64_t>& src, bool value_only, const std::vector<uint64_t>& param_remap);
	static void remap(boost::bimap<uint64_t, uint64_t>& src, bool value_only, const std::vector<uint64_t>& param_remap);
	static void remap(boost::bimap<std::string, uint64_t>& src, const std::vector<uint64_t>& param_remap);
	static void remap(std::vector<lifecycle>& src, const uint64_t& var_counter, const std::vector<uint64_t>& param_remap);


	void process_func1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_func2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_func2_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void process_func2_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

	void process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
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
		std::vector<uint64_t>& checkpoint_inputs
	
	);

	void swap(std::vector<uint64_t>& ops_arg_index);

};
