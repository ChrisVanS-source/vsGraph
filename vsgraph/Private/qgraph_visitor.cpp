#include "qgraph_visitor.h"

//${begin}
void graph_visitor::equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1_sx(clock, r_i, op, x_i);
}

void graph_visitor::equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_func1(clock, r_i, op, x_i);
}

void graph_visitor::add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2(clock, r_i, op, x_i, y_i);
}

void graph_visitor::add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sy(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_sx(clock, r_i, op, x_i, y_i);
}

void graph_visitor::greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_func2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	process_func2_logical_sy(clock,r_i,op,x_i,s_i);
}

void graph_visitor::less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	process_func2_logical_sy(clock,r_i,op,x_i,s_i);
}

void graph_visitor::equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	process_func2_logical_sy(clock,r_i,op,x_i,s_i);
}

void graph_visitor::iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i)
{
	process_iff_sy(clock,r_i,op,c_i,x_i,s_i);
}

void graph_visitor::iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& s_i)
{
	process_iff_sy(clock,r_i,op,c_i,x_i,s_i);
}

void graph_visitor::iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& s_i, const uint64_t& t_i)
{
	process_iff_sx_sy(clock,r_i,op,c_i,s_i,t_i);
}

void graph_visitor::integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_integer1_ix(clock,r_i,op,x_i);
}

void graph_visitor::integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_integer1(clock,r_i,op,x_i);
}

void graph_visitor::integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_integer1(clock,r_i,op,x_i);
}

void graph_visitor::integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_ix(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_ix(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer2_logical_iy(clock,r_i,op,x_i,y_i);
}

void graph_visitor::integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer_iff_iy(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_integer_iff_ix_iy(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_boolean1_bx(clock,r_i,op,x_i);
}

void graph_visitor::boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_boolean1(clock,r_i,op,x_i);
}

void graph_visitor::boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	process_boolean1(clock,r_i,op,x_i);
}

void graph_visitor::boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2_by(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2_by(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean2_by(clock,r_i,op,x_i,y_i);
}

void graph_visitor::boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean_iff(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean_iff_by(clock,r_i,op,c_i,x_i,y_i);
}

void graph_visitor::boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	process_boolean_iff_bx_by(clock,r_i,op,c_i,x_i,y_i);
}

//${end}

void graph_visitor::checkpoint(uint64_t clock, Operation op)
{
}