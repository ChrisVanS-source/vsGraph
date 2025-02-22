#pragma once

#include "intrin.h"
#include "qdefines.h"
#include "qworkspace.h"
#include "qgraph_traits.h"
#include <cmath>
using namespace vstech;

#include "qimmhss.h"

//${begin}
template<class T>
struct graph_op_traits
{

	static void equal_scalar(typename workspace_traits<T>::type& r, const typename graph_traits<T>::scalar_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=x;
	}

	static void equal(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=x;
	}

	static void squareroot(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sqrt(x);
	}

	static void change_sign(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=-x;
	}

	static void ceiling(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::ceil(x);
	}

	static void flooring(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::floor(x);
	}

	static void heaviside_step(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=hss(x);
	}

	static void exponential(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::exp(x);
	}

	static void logarithm(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log(x);
	}

	static void logarithm2(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log2(x);
	}

	static void logarithm10(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log10(x);
	}

	static void complementary_errorfunc(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::erfc(x);
	}

	static void sine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sin(x);
	}

	static void cosine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::cos(x);
	}

	static void tangent(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::tan(x);
	}

	static void arc_sine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::asin(x);
	}

	static void arc_cosine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::acos(x);
	}

	static void arc_tangent(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::atan(x);
	}

	static void hyperbolic_sine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sinh(x);
	}

	static void hyperbolic_cosine(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::cosh(x);
	}

	static void hyperbolic_tangent(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const uint64_t& offset, const uint64_t& n)
	{
		r=std::tanh(x);
	}

	static void add(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
	}

	static void subtract(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
	}

	static void multiply(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
	}

	static void divide(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
	}

	static void maximum(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
	}

	static void minimum(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
	}

	static void power(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
	}

	static void add_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
	}

	static void subtract_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
	}

	static void scalar_subtract(typename workspace_traits<T>::type& r, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
	}

	static void multiply_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
	}

	static void divide_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
	}

	static void scalar_divide(typename workspace_traits<T>::type& r, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
	}

	static void maximum_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
	}

	static void minimum_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
	}

	static void power_scalar(typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
	}

	static void scalar_power(typename workspace_traits<T>::type& r, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
	}

	static void greater_than(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x > y;
	}

	static void less_than(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x < y;
	}

	static void equal_to(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x == y;
	}

	static void greater_than_scalar(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x > y;
	}

	static void less_than_scalar(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x < y;
	}

	static void equal_to_scalar(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x == y;
	}

	static void iff(typename workspace_traits<T>::type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void iff_scalar(typename workspace_traits<T>::type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void iff_scalar_scalar(typename workspace_traits<T>::type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename graph_traits<T>::scalar_type& x, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void integer_equal_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename graph_traits<T>::integer_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = x;
	}

	static void integer_equal(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = x;
	}

	static void integer_change_sign(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = -x;
	}

	static void integer_add(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x+y;
	}

	static void integer_subtract(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x-y;
	}

	static void integer_multiply(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x*y;
	}

	static void integer_divide(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x/y;
	}

	static void integer_add_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x+y;
	}

	static void integer_subtract_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x-y;
	}

	static void integer_int_subtract(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename graph_traits<T>::integer_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x-y;
	}

	static void integer_multiply_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x*y;
	}

	static void integer_divide_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x/y;
	}

	static void integer_int_divide(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename graph_traits<T>::integer_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x/y;
	}

	static void integer_greater_than(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x>y;
	}

	static void integer_less_than(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x<y;
	}

	static void integer_equal_to(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x==y;
	}

	static void integer_greater_than_int(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x>y;
	}

	static void integer_less_than_int(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x<y;
	}

	static void integer_equal_to_int(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x==y;
	}

	static void integer_iff(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void integer_iff_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void integer_iff_int_int(typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename graph_traits<T>::integer_type& x, const typename graph_traits<T>::integer_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void boolean_equal_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename graph_traits<T>::boolean_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = x;
	}

	static void boolean_equal(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = x;
	}

	static void boolean_not(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const uint64_t& offset, const uint64_t& n)
	{
		r = !x;
	}

	static void boolean_and(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x && y;
	}

	static void boolean_or(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x || y;
	}

	static void boolean_equal_to(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x == y;
	}

	static void boolean_and_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::boolean_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x && y;
	}

	static void boolean_or_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::boolean_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x || y;
	}

	static void boolean_equal_to_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::boolean_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = x == y;
	}

	static void boolean_iff(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void boolean_iff_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& x, const typename graph_traits<T>::boolean_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void boolean_iff_bool_bool(typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type_ref r, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename graph_traits<T>::boolean_type& x, const typename graph_traits<T>::boolean_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
	}

	static void equal_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=x;
		dr=dx;
	}

	static void squareroot_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sqrt(x);
		dr=dx*(T)0.5/r;
	}

	static void change_sign_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=-x;
		dr=-dx;
	}

	static void ceiling_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::ceil(x);
		dr=0;
	}

	static void flooring_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::floor(x);
		dr=0;
	}

	static void heaviside_step_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=hss(x);
		dr=0;
	}

	static void exponential_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::exp(x);
		dr=r*dx;
	}

	static void logarithm_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log(x);
		dr=dx/x;
	}

	static void logarithm2_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log2(x);
		dr=dx/(x*(T)0.69314718055994529);
	}

	static void logarithm10_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::log10(x);
		dr=dx/(x*(T)2.3025850929940459);
	}

	static void complementary_errorfunc_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::erfc(x);
		dr=-std::exp(-x*x)*(T)1.1283791670955126*dx;
	}

	static void sine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sin(x);
		dr=std::cos(x)*dx;
	}

	static void cosine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::cos(x);
		dr=-std::sin(x)*dx;
	}

	static void tangent_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::tan(x);
		dr=dx/(std::cos(x)*std::cos(x));
	}

	static void arc_sine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::asin(x);
		dr=dx/std::sqrt((T)1.0-x*x);
	}

	static void arc_cosine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::acos(x);
		dr=-dx/std::sqrt((T)1.0-x*x);
	}

	static void arc_tangent_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::atan(x);
		dr=dx/(x*x+(T)1.0);
	}

	static void hyperbolic_sine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::sinh(x);
		dr=std::cosh(x)*dx;
	}

	static void hyperbolic_cosine_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::cosh(x);
		dr=std::sinh(x)*dx;
	}

	static void hyperbolic_tangent_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const uint64_t& offset, const uint64_t& n)
	{
		r=std::tanh(x);
		dr=((T)1.0-r*r)*dx;
	}

	static void add_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
		dr=dx+dy;
	}

	static void add_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
		dr=dy;
	}

	static void add_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
		dr=dx;
	}

	static void subtract_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
		dr=dx-dy;
	}

	static void subtract_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
		dr=-dy;
	}

	static void subtract_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
		dr=dx;
	}

	static void multiply_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
		dr=y*dx+x*dy;
	}

	static void multiply_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
		dr=x*dy;
	}

	static void multiply_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
		dr=y*dx;
	}

	static void divide_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
		dr=(dx-r*dy)/y;
	}

	static void divide_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
		dr=-r*dy/y;
	}

	static void divide_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
		dr=dx/y;
	}

	static void maximum_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
		dr=hss(x-y)*dx+hss(y-x)*dy;
	}

	static void maximum_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
		dr=hss(y-x)*dy;
	}

	static void maximum_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
		dr=hss(x-y)*dx;
	}

	static void minimum_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
		dr=hss(y-x)*dx+hss(x-y)*dy;
	}

	static void minimum_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
		dr=hss(x-y)*dy;
	}

	static void minimum_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
		dr=hss(y-x)*dx;
	}

	static void power_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
		dr=std::pow(x,y-(T)1.0)*y*dx+std::log(x)*r*dy;
	}

	static void power_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
		dr=std::log(x)*r*dy;
	}

	static void power_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
		dr=std::pow(x,y-(T)1.0)*y*dx;
	}

	static void add_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x+y;
		dr=dx;
	}

	static void subtract_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
		dr=dx;
	}

	static void scalar_subtract_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x-y;
		dr=-dy;
	}

	static void multiply_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x*y;
		dr=y*dx;
	}

	static void divide_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
		dr=dx/y;
	}

	static void scalar_divide_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=x/y;
		dr=-r*dy/y;
	}

	static void maximum_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::max(x,y);
		dr=hss(x-y)*dx;
	}

	static void minimum_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::min(x,y);
		dr=hss(y-x)*dx;
	}

	static void power_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
		dr=std::pow(x,y-(T)1.0)*y*dx;
	}

	static void scalar_power_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r=std::pow(x,y);
		dr=std::log(x)*r*dy;
	}

	static void iff_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
		dr = c ? dx : dy;
	}

	static void iff_px_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, const typename workspace_traits<T>::type& dy, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
		dr = c ? (T)0.0 : dy;
	}

	static void iff_py_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
		dr = c ? dx : (T)0.0;
	}

	static void iff_scalar_forward(typename workspace_traits<T>::type& r, typename workspace_traits<T>::type& dr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& dx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		r = c ? x : y;
		dr = c ? dx : (T)0.0;
	}

	static void equal_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
	}

	static void squareroot_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*(T)0.5/r;
	}

	static void change_sign_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx-=wr;
	}

	static void exponential_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*r;
	}

	static void logarithm_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/x;
	}

	static void logarithm2_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/(x*(T)0.69314718055994529);
	}

	static void logarithm10_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/(x*(T)2.3025850929940459);
	}

	static void complementary_errorfunc_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx-=wr*std::exp(-x*x)*(T)1.1283791670955126;
	}

	static void sine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*std::cos(x);
	}

	static void cosine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=-wr*std::sin(x);
	}

	static void tangent_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/(std::cos(x)*std::cos(x));
	}

	static void arc_sine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/std::sqrt((T)1.0-x*x);
	}

	static void arc_cosine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=-wr/std::sqrt((T)1.0-x*x);
	}

	static void arc_tangent_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/(x*x+(T)1.0);
	}

	static void hyperbolic_sine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*std::cosh(x);
	}

	static void hyperbolic_cosine_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*std::sinh(x);
	}

	static void hyperbolic_tangent_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*((T)1.0-r*r);
	}

	static void add_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
		wy+=wr;
	}

	static void add_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=wr;
	}

	static void add_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
	}

	static void subtract_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
		wy-=wr;
	}

	static void subtract_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy-=wr;
	}

	static void subtract_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
	}

	static void multiply_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=y*wr;
		wy+=x*wr;
	}

	static void multiply_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=x*wr;
	}

	static void multiply_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=y*wr;
	}

	static void divide_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/y;
		wy+=-r*wr/y;
	}

	static void divide_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=-r*wr/y;
	}

	static void divide_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/y;
	}

	static void maximum_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(x-y)*wr;
		wy+=hss(y-x)*wr;
	}

	static void maximum_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=hss(y-x)*wr;
	}

	static void maximum_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(x-y)*wr;
	}

	static void minimum_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(y-x)*wr;
		wy+=hss(x-y)*wr;
	}

	static void minimum_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=hss(x-y)*wr;
	}

	static void minimum_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(y-x)*wr;
	}

	static void power_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*std::pow(x,y-(T)1.0)*y;
		wy+=wr*std::log(x)*r;
	}

	static void power_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=wr*std::log(x)*r;
	}

	static void power_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr*std::pow(x,y-(T)1.0)*y;
	}

	static void add_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
	}

	static void subtract_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr;
	}

	static void scalar_subtract_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy-=wr;
	}

	static void multiply_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=y*wr;
	}

	static void divide_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=wr/y;
	}

	static void scalar_divide_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=-r*wr/y;
	}

	static void maximum_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(x-y)*wr;
	}

	static void minimum_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=hss(y-x)*wr;
	}

	static void power_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		wx+=std::pow(x,y-(T)1.0)*y*wr;
	}

	static void scalar_power_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename graph_traits<T>::scalar_type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		wy+=std::log(x)*r*wr;
	}

	static void iff_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		if (c)
			wx += wr;
		else
			wy += wr;
	}

	static void iff_px_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, const typename workspace_traits<T>::type& y, typename workspace_traits<T>::type& wy, const uint64_t& offset, const uint64_t& n)
	{
		if (!c)
			wy += wr;
	}

	static void iff_py_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename workspace_traits<T>::type& y, const uint64_t& offset, const uint64_t& n)
	{
		if (c)
			wx += wr;
	}

	static void iff_scalar_backward(const typename workspace_traits<T>::type& r, const typename workspace_traits<T>::type& wr, const typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type& c, const typename workspace_traits<T>::type& x, typename workspace_traits<T>::type& wx, const typename graph_traits<T>::scalar_type& y, const uint64_t& offset, const uint64_t& n)
	{
		if (c)
			wx += wr;
	}

};

template<>
struct graph_op_traits<__m512d>
{

	static void equal_scalar(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m512d& r, const __m512d& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m512d& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m512d>::storage_type& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m512d& r, __m512d& dr, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m512d& r, const __m512d& wr, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m512d& r, const __m512d& wr, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m256d>
{

	static void equal_scalar(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m256d& r, const __m256d& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m256d& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m256d>::storage_type& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m256d& r, __m256d& dr, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m256d& r, const __m256d& wr, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m256d& r, const __m256d& wr, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m128d>
{

	static void equal_scalar(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m128d& r, const __m128d& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m128d& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m128d>::storage_type& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m128d& r, __m128d& dr, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m128d& r, const __m128d& wr, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m128d& r, const __m128d& wr, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m512>
{

	static void equal_scalar(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m512& r, const __m512& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m512& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m512>::storage_type& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m512& r, __m512& dr, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m512& r, __m512& dr, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m512& r, const __m512& wr, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m512& r, const __m512& wr, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m256>
{

	static void equal_scalar(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m256& r, const __m256& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m256& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m256>::storage_type& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m256& r, __m256& dr, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m256& r, __m256& dr, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m256& r, const __m256& wr, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m256& r, const __m256& wr, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m128>
{

	static void equal_scalar(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void equal(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void flooring(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void exponential(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void sine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void cosine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void tangent(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(__m128& r, const __m128& x, const uint64_t& offset, const uint64_t& n);
	static void add(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void multiply(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void maximum(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(__m128& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void iff(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m128>::storage_type& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const uint64_t& offset, const uint64_t& n);
	static void add_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(__m128& r, __m128& dr, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(__m128& r, __m128& dr, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const __m128& r, const __m128& wr, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const __m128& r, const __m128& wr, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m512d*>
{

	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m256d*>
{

	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m128d*>
{

	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<double*>
{

	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(double* r, const double& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void equal(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(double* r, const double* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power(double* r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(double* r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(double* r, const double& x, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(double* r, double* dr, const double* x, const double* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(double* r, double* dr, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(double* r, double* dr, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(double* r, double* dr, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(double* r, double* dr, const double& x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const double* r, const double* wr, const double* x, double* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const double* r, const double* wr, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const double* r, const double* wr, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const double* r, const double* wr, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const double* r, const double* wr, const double& x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m512*>
{

	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m256*>
{

	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<__m128*>
{

	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
};

template<>
struct graph_op_traits<float*>
{

	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n);
	static void equal_scalar(float* r, const float& x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void equal(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void squareroot(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void change_sign(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void ceiling(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void flooring(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void exponential(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm2(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void logarithm10(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent(float* r, const float* x, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power(float* r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar(float* r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void scalar_power(float* r, const float& x, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n);
	static void integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n);
	static void integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n);
	static void boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void equal_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void ceiling_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void flooring_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void heaviside_step_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void exponential_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_forward(float* r, float* dr, const float* x, const float* dx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void add_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void power_px_forward(float* r, float* dr, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_forward(float* r, float* dr, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_forward(float* r, float* dr, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_forward(float* r, float* dr, const float& x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void equal_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void squareroot_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void change_sign_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void exponential_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm2_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void logarithm10_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void complementary_errorfunc_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void arc_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_sine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_cosine_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n);
	static void hyperbolic_tangent_backward(const float* r, const float* wr, const float* x, float* wx, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void add_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void add_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void subtract_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void subtract_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void multiply_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void multiply_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void divide_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void divide_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void maximum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void maximum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void minimum_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void minimum_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void power_px_backward(const float* r, const float* wr, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void power_py_backward(const float* r, const float* wr, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void add_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void subtract_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_subtract_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void multiply_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void divide_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_divide_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void maximum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void minimum_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
	static void power_scalar_backward(const float* r, const float* wr, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void scalar_power_backward(const float* r, const float* wr, const float& x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n, uint64_t& i);
	static void iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n);
	static void iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n);
	static void iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n);
};

//${end}
