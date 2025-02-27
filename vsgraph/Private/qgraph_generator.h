#pragma once

#include <map>
#include <vector>
#include <memory>
#include "qgraph_enum.h"
#include "qgraph_traits.h"
#include "boost/bimap.hpp"
#include "qgraph_visitor.h" // To remove

template<class T>
class qgraph_i;

#include "qscalar.h"
using namespace vstech;

template<class T>
class graph_generator : public graph_visitor {

	std::shared_ptr<qgraph_i<T>> m_g;

	std::vector<std::map<uint64_t, uint64_t>> m_assign_map;

	uint64_t m_address;
	uint64_t m_var_counter;
	uint64_t m_n_non_param;

	ADType m_adtype;
	ADType m_phase;

	std::vector<uint64_t> m_param_remap;

	std::vector<uint64_t> m_aux_map;

	uint64_t m_n_orig_variable; 

	uint64_t m_skip_index;

	const std::vector<uint64_t>& m_skip_ops_init;
	const std::vector<uint64_t>& m_skip_ops_arg_init;

	const std::vector<typename graph_traits<T>::scalar_type>& m_scalar;

	bool adjoint_used(const uint64_t& x_i, uint64_t clock);

	uint64_t add_variable();

	int64_t get_double_index(const double& x);
	int64_t get_scalar_index(const typename graph_traits<T>::scalar_type& x);

	const uint64_t& auxiliary(uint64_t x) const;
	void set_auxiliary(uint64_t x, const uint64_t& wx);

	void check_integrity(uint64_t new_i, const uint64_t& v);

	void equal_scalar(uint64_t orig_clock, const uint64_t& r_i, const uint64_t& s_i);

	void process_func1(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, bool check_output = true);
	void process_func2(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, bool check_output = true);
	void process_func2_sy(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i, bool check_output = true);

	void process_integer1(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_integer2(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

	void process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_boolean1_bx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

	void update_adjoint(uint64_t orig_clock, const uint64_t& x_i, Operation op, const uint64_t& r_i, const uint64_t& m_i = (uint64_t)-1, Operation wrop = MULTIPLY);
	void update_adjoint_sy(uint64_t orig_clock, const uint64_t& x_i, Operation op, const uint64_t& r_i, const int64_t& s_i, Operation wrop = MULTIPLY_SCALAR);

	std::vector<boost::bimap<uint64_t, uint64_t>> m_input_map;
	std::vector<boost::bimap<uint64_t, uint64_t>> m_output_map;
	std::map<uint64_t, uint64_t> m_input_output_map;
	std::map<uint64_t, uint64_t> m_variable_map;

	uint64_t m_zero_index;

public:

	graph_generator(const qgraph_i<T>& g);
	~graph_generator();

	void swap(qgraph_i<T>& g);

	void before_forward();
	void after_forward() {}
	void before_backward();
	void after_backward() {}

//${begin}
	void equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void greater_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void less_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void greater_than_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void less_than_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void equal_to_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_equal_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_equal(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_change_sign(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_add(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_multiply(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_add_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_subtract_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_int_subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_multiply_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_divide_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_int_divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_greater_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_less_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_greater_than_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_less_than_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_equal_to_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff_int_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_equal(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_not(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_and(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_or(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_and_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_or_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_to_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff_bool_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
//${end}

	void iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	void iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	void iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i);

};
