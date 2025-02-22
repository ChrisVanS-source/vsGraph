#pragma once

#include <cstdint>
#include <vector>
#include "qgraph_traits.h"
#include "qgraph_enum.h"
#include "qworkspace.h"
#include "qgraph_visitor.h" // To remove
using namespace vstech;

template<class T> class qgraph_i;
template<class T> class qworkspace_i;

template<class T>
class graph_backward : public graph_visitor
{
	const std::vector<uint64_t>& m_wksp_index;
	const std::vector<uint64_t>& m_integer_wksp_index;
	const std::vector<uint64_t>& m_boolean_wksp_index;

	std::vector<typename workspace_traits<T>::type>& m_wksp;
	std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& m_integer_wksp;
	std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& m_boolean_wksp;

	const std::vector<typename graph_traits<T>::scalar_type>& m_scalar;
	const std::vector<typename graph_traits<T>::integer_type>& m_integer;
	const std::vector<typename graph_traits<T>::boolean_type>& m_boolean;

	uint64_t m_var_counter;
	const std::vector<uint64_t>& m_skip_ops_init;
	const std::vector<uint64_t>& m_skip_ops_arg_init;
	uint64_t m_skip_index;

	void init_adjoint(const uint64_t& x_i, uint64_t clock);

	typename graph_traits<T>::scalar_type m_zero;

	uint64_t m_offset;
	uint64_t m_n;

public:

	graph_backward(const qgraph_i<T>& g, qworkspace_i<T>& ws, ADType direction);

	~graph_backward();

	// Notification function

	void before_backward() {}
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
	void greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	void iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	void iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i);
	void integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
//${end}

};

