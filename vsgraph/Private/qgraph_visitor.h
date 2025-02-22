#pragma once

#include <cstdint>
#include "qgraph_enum.h"

class graph_visitor {

public:

	graph_visitor() {}
	~graph_visitor() {}

	// Notification function

	virtual void before_forward() {}
	virtual void after_forward() {}
	virtual void before_backward() {}
	virtual void after_backward() {}

	// Generic functions

	virtual void process_func1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_func1_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_func2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_func2_sx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i) {}
	virtual void process_func2_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i) {}
	virtual void process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i) {}
	virtual void process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i) {}
	virtual void process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i) {}

	virtual void process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_integer1_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i) {}
	virtual void process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i) {}
	virtual void process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}

	virtual void process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_boolean1_bx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i) {}
	virtual void process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i) {}
	virtual void process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}
	virtual void process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) {}

	// Functions specific to functions

//${begin}
	virtual void equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	virtual void greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	virtual void iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	virtual void iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i);
	virtual void iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i);
	virtual void integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	virtual void boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	virtual void boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
//${end}
	virtual void checkpoint(uint64_t clock, Operation op);
};