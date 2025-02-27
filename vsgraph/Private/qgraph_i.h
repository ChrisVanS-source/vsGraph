#pragma once

#include <vector>
#include "qgraph_traits.h"
#include "qgraph_enum.h"
#include "qgraph_proto.h"
#include "qboolean_i.h"
#include "qinteger_i.h"
#include <boost/bimap.hpp>

class qgraph_i_base {

protected:

	bool m_lifecycle_input;

	std::vector<ADType> m_adtype;
	std::vector<Operation> m_ops;
	std::vector<uint64_t> m_ops_arg_index;
	std::vector<uint64_t> m_checkpoint_ops_index;
	std::vector<uint64_t> m_checkpoint_ops_arg_index;

	// 0 for scalar, 1 for logical, 2 for integer
	std::vector<std::vector<lifecycle>> m_lifecycle;	
	std::vector<std::vector<bool>> m_processed;
	std::vector<std::vector<uint64_t>> m_checkpoint_input;
	std::vector<uint64_t> m_var_counter;
	std::vector<uint64_t> m_wksp_size;					
	std::vector<std::vector<uint64_t>> m_wksp_index;	
	std::vector<std::map<uint64_t, uint64_t>> m_variable_map; 
	std::vector<std::map<uint64_t, uint64_t>> m_assign_map;

	// Floating point specific
	std::vector<std::vector<boost::bimap<uint64_t, uint64_t>>> m_input_map;
	std::vector<boost::bimap<uint64_t, uint64_t>> m_output_map;
	std::map<uint64_t, uint64_t> m_input_output_map;

	uint64_t m_n_nonparam;
	boost::bimap<std::string, uint64_t> m_variable_name_map;
//	std::map<uint64_t, uint64_t> m_boolean_assign_map;
//	std::map<uint64_t, uint64_t> m_integer_assign_map;
	std::vector<uint64_t> m_skip_ops_init;
	std::vector<uint64_t> m_skip_ops_arg_init;

	uint64_t index() const;

	bool& is_param(uint64_t x_i);
	const bool& is_param(uint64_t x_i) const;

	bool was_used(uint64_t x_i) const;
	uint64_t& first_used(uint64_t x_i);
	uint64_t& last_used(uint64_t x_i);
	uint64_t& first_index(uint64_t x_i);
	uint64_t& last_index(uint64_t x_i);
	uint64_t& created(uint64_t x_i);

	bool was_boolean_used(uint64_t x_i) const;
	uint64_t& first_boolean_index(uint64_t x_i);
	uint64_t& last_boolean_index(uint64_t x_i);
	uint64_t& first_boolean_used(uint64_t x_i);
	uint64_t& last_boolean_used(uint64_t x_i);

	bool was_integer_used(uint64_t x_i) const;
	uint64_t& first_integer_index(uint64_t x_i);
	uint64_t& last_integer_index(uint64_t x_i);
	uint64_t& first_integer_used(uint64_t x_i);
	uint64_t& last_integer_used(uint64_t x_i);

	void update_use(uint64_t x, uint64_t x_i, const scalar_value& xv);
	void update_use(uint64_t x, uint64_t x_i, const boolean_value& xv);
	void update_use(uint64_t x, uint64_t x_i, const integer_value& xv);

	uint64_t add_variable();
	uint64_t add_boolean_variable();
	uint64_t add_integer_variable();

	uint64_t generic_add_variable(DataType dt);

	void process_input(uint64_t x);
	void process_boolean_input(uint64_t x);
	void process_integer_input(uint64_t x);
	
	void generic_process_input(DataType dt, uint64_t x);

	void process_output(uint64_t x);
	void process_boolean_output(uint64_t x);
	void process_integer_output(uint64_t x);

	void generic_process_output(DataType dt, uint64_t x);

	int64_t m_zero_index;

public:

	qgraph_i_base();
	virtual ~qgraph_i_base();

	int64_t get_zero_index() const { return m_zero_index; }
	int64_t& get_zero_index() { return m_zero_index; }

	uint64_t now() const;

	std::pair<std::map<uint64_t, uint64_t>::iterator, bool> generic_varmap(DataType dt, uint64_t x);

	std::pair<std::map<uint64_t, uint64_t>::iterator, bool> varmap(uint64_t x);
	std::pair<std::map<uint64_t, uint64_t>::iterator, bool> boolean_varmap(uint64_t x);
	std::pair<std::map<uint64_t, uint64_t>::iterator, bool> integer_varmap(uint64_t x);

	void generic_destroy(DataType dt, uint64_t x);

	void destroy(uint64_t x);
	void equal_scalar(uint64_t x, const scalar_value& xv);

	void input(uint64_t x, const scalar_value& xv, const char* s, bool xp);
	void output(uint64_t x, const char* s = 0);
	void checkpoint();
	void process_equal(uint64_t r, Operation op, uint64_t x, const scalar_value& xv);
	void process_func1(uint64_t r, Operation op, uint64_t x, const scalar_value& xv);
	void process_func2(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv);
	void process_func2_sy(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, const scalar_value& yv);
	void process_func2_sx(uint64_t r, Operation op, const scalar_value& xv, uint64_t y, const scalar_value& yv);
	void process_func2_logical(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv);
	void process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, const scalar_value& yv);
	void process_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv);
	void process_iff_sy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const scalar_value& xv, const scalar_value& yv);
	void process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const scalar_value& xv, const scalar_value& yv);

	void destroy_boolean(uint64_t x);
	void equal_bool(uint64_t x, const boolean_value& xv);

	void process_boolean1(uint64_t r, Operation op, uint64_t x, const boolean_value& xv);
	void process_boolean1_bx(uint64_t r, Operation op, const boolean_value& xv);
	void process_boolean2(uint64_t r, Operation op, uint64_t x, const boolean_value& xv, uint64_t y, const boolean_value& yv);
	void process_boolean2_by(uint64_t r, Operation op, uint64_t x, const boolean_value& xv, const boolean_value& yv);
	void process_boolean_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const boolean_value& xv, uint64_t y, const boolean_value& yv);
	void process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const boolean_value& xv, const boolean_value& yv);
	void process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const boolean_value& xv, const boolean_value& yv);

	void destroy_integer(uint64_t x);
	void equal_int(uint64_t x, const integer_value& xv);

	void process_integer1(uint64_t r, Operation op, uint64_t x, const integer_value& xv);
	void process_integer1_ix(uint64_t r, Operation op, const integer_value& xv);
	void process_integer2(uint64_t r, Operation op, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv);
	void process_integer2_iy(uint64_t r, Operation op, uint64_t x, const integer_value& xv, const integer_value& yv);
	void process_integer2_ix(uint64_t r, Operation op, const integer_value& xv, uint64_t y, const integer_value& yv);
	void process_integer2_logical(uint64_t r, Operation op, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv);
	void process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const integer_value& xv, const integer_value& yv);
	void process_integer_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv);
	void process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const integer_value& xv, const integer_value& yv);
	void process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const integer_value& xv, const integer_value& yv);

	const std::vector<Operation>& get_ops() const { return m_ops; }
	std::vector<Operation>& get_ops() { return m_ops; }
	const std::vector<std::vector<boost::bimap<uint64_t, uint64_t>>>& get_input_map() const { return m_input_map; }
	std::vector<std::vector<boost::bimap<uint64_t, uint64_t>>>& get_input_map() { return m_input_map; }
	const std::vector<boost::bimap<uint64_t, uint64_t>>& get_output_map() const { return m_output_map; }
	std::vector<boost::bimap<uint64_t, uint64_t>>& get_output_map() { return m_output_map; }
	const boost::bimap<std::string, uint64_t>& get_variable_name_map() const { return m_variable_name_map; }
	const std::map<uint64_t, uint64_t>& get_variable_map() const { return m_variable_map[QFLOATING_POINT]; }
	std::map<uint64_t, uint64_t>& get_variable_map() { return m_variable_map[QFLOATING_POINT]; }
	std::vector<std::map<uint64_t, uint64_t>>& get_all_variable_map() { return m_variable_map; }
	const std::vector<std::map<uint64_t, uint64_t>>& get_assign_map() const { return m_assign_map; }
	std::vector<std::map<uint64_t, uint64_t>>& get_assign_map() { return m_assign_map; }
	const uint64_t& get_wksp_size() const { return m_wksp_size[QFLOATING_POINT]; }
	const uint64_t& get_integer_wksp_size() const { return m_wksp_size[QINTEGER]; }
	const uint64_t& get_boolean_wksp_size() const { return m_wksp_size[QBOOLEAN]; }
	const std::vector<uint64_t>& get_wksp_index() const { return m_wksp_index[QFLOATING_POINT]; }
	const std::vector<uint64_t>& get_integer_wksp_index() const { return m_wksp_index[QINTEGER]; }
	const std::vector<uint64_t>& get_boolean_wksp_index() const { return m_wksp_index[QBOOLEAN]; }
	const std::vector<uint64_t>& get_ops_arg_index() const { return m_ops_arg_index; }
	std::vector<uint64_t>& get_ops_arg_index() { return m_ops_arg_index; }
	const uint64_t& get_var_counter() const { return m_var_counter[QFLOATING_POINT]; }
	uint64_t& get_var_counter() { return m_var_counter[QFLOATING_POINT]; }
	const std::vector<std::vector<lifecycle>>& get_lifecycle() const { return m_lifecycle; }
	std::vector<std::vector<lifecycle>>& get_lifecycle() { return m_lifecycle; }
	const uint64_t& get_n_nonparam() const { return m_n_nonparam; }
	uint64_t& get_n_nonparam() { return m_n_nonparam; }
	const std::map<uint64_t, uint64_t>& get_input_output_map() const { return m_input_output_map; }
	std::map<uint64_t, uint64_t>& get_input_output_map() { return m_input_output_map; }
	const std::vector<std::vector<uint64_t>>& get_checkpoint_input() const { return m_checkpoint_input; }

	const std::vector<uint64_t>& get_skip_ops_init() const { return m_skip_ops_init; }
	const std::vector<uint64_t>& get_skip_ops_arg_init() const { return m_skip_ops_arg_init; }

	const std::vector<uint64_t>& get_checkpoint_ops_index() const { return m_checkpoint_ops_index; }

	std::vector<uint64_t>& get_checkpoint_ops_index() { return m_checkpoint_ops_index; }
	std::vector<uint64_t>& get_checkpoint_ops_arg_index() { return m_checkpoint_ops_arg_index; }

	const std::vector<ADType>& get_adtype() const { return m_adtype; }

	void set_lifecycle_input(bool f);

	void set_input_output_lifecycle();

	template<class Op>
	Op& sweep_forward(Op& visitor) const;

	template<class Op>
	Op& sweep_forward(Op& visitor, uint64_t from, uint64_t to) const;

	template<class Op>
	Op& sweep_backward(Op& visitor) const;

	template<class Op, class fwdOp>
	Op& sweep_backward(Op& visitor, fwdOp& fwd_visitor) const;

	template<class Op>
	Op& sweep_backward(Op& visitor, uint64_t from, uint64_t to) const;

	uint64_t get_input_index(uint64_t x) const;
	uint64_t get_index(uint64_t x) const;
	uint64_t get_index(const char* s) const;

};

template<class T>
class qworkspace_i;

#include "qgraph_gpu_memory.h"
#include "qgpu_traits.h"

template<class T>
class qgraph_i : public qgraph_i_base {

	std::map<int,typename gpu_traits<T>::graph_memory> m_amd_memory; // Key = device and value = GPU memory
	std::map<int, typename gpu_traits<T>::graph_memory> m_nvidia_memory; // Key = device and value = GPU memory

	std::vector<typename graph_traits<T>::scalar_type> m_scalar;
	std::map<typename graph_traits<T>::scalar_type_map, uint64_t> m_scalar_map;

	std::vector<typename graph_traits<T>::integer_type> m_integer;
	std::map<typename graph_traits<T>::integer_type, uint64_t, integer_type_predicate<T>> m_integer_map;

	std::vector<typename graph_traits<T>::boolean_type> m_boolean;
	std::map<typename graph_traits<T>::boolean_type, uint64_t> m_boolean_map;

	scalar<T> wrap(const typename graph_traits<T>::scalar_type& xv);
	integer<T> wrap(const typename graph_traits<T>::integer_type& xv);
	_boolean<T> wrap(const typename graph_traits<T>::boolean_type& cv);

public:

	uint64_t get_scalar_index(const typename graph_traits<T>::scalar_type& xv);
	uint64_t get_boolean_index(const typename graph_traits<T>::boolean_type& xv);
	uint64_t get_integer_index(const typename graph_traits<T>::integer_type& xv);

	qgraph_i();
	virtual ~qgraph_i();

	void destroy(uint64_t x);
	void equal_scalar(uint64_t r, const typename graph_traits<T>::scalar_type& xv);

	void input(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s = 0);
	void param(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s = 0);
	void output(uint64_t x, const char* s = 0);
	void process_equal(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv);
	void process_func1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv);
	void process_func2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv);
	void process_func2_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv);
	void process_func2_sx(uint64_t r, Operation op, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv);
	void process_func2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv);
	void process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv);
	void process_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv);
	void process_iff_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv);
	void process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv);

	void destroy_boolean(uint64_t x);
	void equal_bool(uint64_t r, const typename graph_traits<T>::boolean_type& xv);

	void process_boolean1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv);
	void process_boolean1_bx(uint64_t r, Operation op, const typename graph_traits<T>::boolean_type& xv);
	void process_boolean2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv);
	void process_boolean2_by(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv);
	void process_boolean_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv);
	void process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv);
	void process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv);

	void destroy_integer(uint64_t x);
	void equal_int(uint64_t r, const typename graph_traits<T>::integer_type& xv);

	void process_integer1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv);
	void process_integer1_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv);
	void process_integer2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv);
	void process_integer2_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv);
	void process_integer2_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv);
	void process_integer2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv);
	void process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv);
	void process_integer_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv);
	void process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv);
	void process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv);

	void fill_scalar();

	void post_process(bool remap = true);

	const std::vector<typename graph_traits<T>::scalar_type>& get_scalar() const { return m_scalar; }
	std::vector<typename graph_traits<T>::scalar_type>& get_scalar() { return m_scalar; }

	const std::vector<typename graph_traits<T>::integer_type>& get_integer() const { return m_integer; }
	std::vector<typename graph_traits<T>::integer_type>& get_integer() { return m_integer; }

	const std::vector<typename graph_traits<T>::boolean_type>& get_boolean() const { return m_boolean; }
	std::vector<typename graph_traits<T>::boolean_type>& get_boolean() { return m_boolean; }

	std::map<typename graph_traits<T>::scalar_type_map, uint64_t>& get_scalar_map() { return m_scalar_map; }
	std::map<typename graph_traits<T>::integer_type, uint64_t, integer_type_predicate<T>>& get_integer_map() { return m_integer_map; }
	std::map<typename graph_traits<T>::boolean_type, uint64_t>& get_boolean_map() { return m_boolean_map; }

	void run(qworkspace_i<T>& ws, ADType direction = NONE) const;
	void forward(qworkspace_i<T>& ws, uint64_t from, uint64_t to) const;
	void backward(qworkspace_i<T>& ws, uint64_t from, uint64_t to) const;

	void make_forwardAD();
	std::shared_ptr<qgraph_i<T>> forwardAD() const;

	void make_backwardAD();
	std::shared_ptr<qgraph_i<T>> backwardAD() const;

	void allocate(qworkspace_i<T>& ws, uint64_t n);
};

template<class T>
qgraph_i<T>* make_graph();

#include "qgraph.h"

template<class T>
vstech::qgraph<T> make_graph(std::shared_ptr<qgraph_i<T>> i);

template<class T>
std::shared_ptr<qgraph_i<T>> get_impl(const vstech::qgraph<T>& g);
