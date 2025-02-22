#pragma once

#include "qscalar.h"
#include "qgraph_traits.h"
#include "qgraph_i.h"
#include "qgraph_enum.h"
#include <memory> // For std::shared_ptr
#include "qscalar_i.h"
#include "qboolean_i.h"

template<class T>
class qrecorder_i {

	bool m_add_variable_equal;

public:

	void set_lifecycle_input(bool f) { m_g->set_lifecycle_input(f); }

	void add_variable_equal(bool f) { m_add_variable_equal = f; }

	std::shared_ptr<qgraph_i<T>> m_g;

	qrecorder_i();
	virtual ~qrecorder_i();

	// Input, output

	template<class U>
	void input(const qscalar<U>& x, const char* s = 0)
	{
		input(get_address(x), graph_traits<T>::cast(x.get_x()), s);
	}

	template<class U>
	void param(const qscalar<U>& x, const char* s = 0)
	{
		param(get_address(x), graph_traits<T>::cast(x.get_x()), s);
	}

	template<class U>
	void output(const qscalar<U>& x, const char* s = 0)
	{
		output(get_address(x), s);
	}

	// Destructor

	template<class U> void destroy(const qscalar<U>& x)
	{
		destroy(get_address(x));
	}

	// Addition

	template<class U> void add(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), ADD, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void add(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), ADD_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void add(const qscalar<U>& r, const qscalar<U>& x)
	{
		add(r, r, x);
	}

	template<class U> void add(const qscalar<U>& r, const U& x)
	{
		add(r, r, x);
	}

	// Subtraction

	template<class U> void subtract(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), SUBTRACT, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void subtract(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), SUBTRACT_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void subtract(const qscalar<U>& r, const qscalar<U>& x)
	{
		subtract(r, r, x);
	}

	template<class U> void subtract(const qscalar<U>& r, const U& x)
	{
		subtract(r, r, x);
	}

	template<class U> void subtract(const qscalar<U>& r, const U& x, const qscalar<U>& y)
	{
		process_func2_sx(get_address(r), SCALAR_SUBTRACT, x, get_address(y), y.get_x());
	}

	// Multiplication

	template<class U> void multiply(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), MULTIPLY, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void multiply(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), MULTIPLY_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void multiply(const qscalar<U>& r, const qscalar<U>& x)
	{
		multiply(r, r, x);
	}

	template<class U> void multiply(const qscalar<U>& r, const U& x)
	{
		multiply(r, r, x);
	}

	// Division

	template<class U> void divide(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), DIVIDE, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void divide(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), DIVIDE_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void divide(const qscalar<U>& r, const qscalar<U>& x)
	{
		divide(r, r, x);
	}

	template<class U> void divide(const qscalar<U>& r, const U& x)
	{
		divide(r, r, x);
	}

	template<class U> void divide(const qscalar<U>& r, const U& x, const qscalar<U>& y)
	{
		process_func2_sx(get_address(r), SCALAR_DIVIDE, x, get_address(y), y.get_x());
	}

	// Equal operator

	template<class U> void equal_scalar(const qscalar<U>& r, const U& x)
	{
		equal_scalar(get_address(r), x); // Special handling of operator=(number)
	}

	template<class U> void equal(const qscalar<U>& r, const qscalar<U>& x)
	{
		if (m_add_variable_equal)
			process_func1(get_address(r), EQUAL, get_address(x), x.get_x());
		else
			process_equal(get_address(r), EQUAL, get_address(x), x.get_x());
	}

	// Functions of 1 argument

	template<class U>
	void change_sign(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), CHANGE_SIGN, get_address(x), x.get_x());
	}

	template<class U>
	void sine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), SINE, get_address(x), x.get_x());
	}

	template<class U>
	void cosine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), COSINE, get_address(x), x.get_x());
	}

	template<class U>
	void tangent(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), TANGENT, get_address(x), x.get_x());
	}

	template<class U>
	void arc_sine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), ARC_SINE, get_address(x), x.get_x());
	}

	template<class U>
	void arc_cosine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), ARC_COSINE, get_address(x), x.get_x());
	}

	template<class U>
	void arc_tangent(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), ARC_TANGENT, get_address(x), x.get_x());
	}

	template<class U>
	void logarithm(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), LOGARITHM, get_address(x), x.get_x());
	}

	template<class U>
	void logarithm2(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), LOGARITHM2, get_address(x), x.get_x());
	}

	template<class U>
	void logarithm10(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), LOGARITHM10, get_address(x), x.get_x());
	}

	template<class U>
	void exponential(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), EXPONENTIAL, get_address(x), x.get_x());
	}

	template<class U>
	void hyperbolic_sine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), HYPERBOLIC_SINE, get_address(x), x.get_x());
	}

	template<class U>
	void hyperbolic_cosine(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), HYPERBOLIC_COSINE, get_address(x), x.get_x());
	}

	template<class U>
	void hyperbolic_tangent(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), HYPERBOLIC_TANGENT, get_address(x), x.get_x());
	}

	template<class U>
	void squareroot(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), SQUAREROOT, get_address(x), x.get_x());
	}

	template<class U>
	void complementary_errorfunction(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), COMPLEMENTARY_ERRORFUNC, get_address(x), x.get_x());
	}

	template<class U>
	void ceiling(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), CEILING, get_address(x), x.get_x());
	}

	template<class U>
	void flooring(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), FLOORING, get_address(x), x.get_x());
	}

	template<class U>
	void heaviside_step(const qscalar<U>& r, const qscalar<U>& x)
	{
		process_func1(get_address(r), HEAVISIDE_STEP, get_address(x), x.get_x());
	}

	// Functions of 2 arguments

	// Power

	template<class U> void power(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), POWER, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void power(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), POWER_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void power(const qscalar<U>& r, const U& x, const qscalar<U>& y)
	{
		process_func2_sx(get_address(r), SCALAR_POWER, x, get_address(y), y.get_x());
	}

	// Maximum

	template<class U> void maximum(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), MAXIMUM, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void maximum(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), MAXIMUM_SCALAR, get_address(x), x.get_x(), y);
	}

	// Minimum

	template<class U> void minimum(const qscalar<U>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2(get_address(r), MINIMUM, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void minimum(const qscalar<U>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_sy(get_address(r), MINIMUM_SCALAR, get_address(x), x.get_x(), y);
	}

	// Logical operators

	template<class U> void greater_than(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2_logical(get_address(r), GREATER_THAN, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void greater_than(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_logical_sy(get_address(r), GREATER_THAN_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void less_than(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2_logical(get_address(r), LESS_THAN, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void less_than(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_logical_sy(get_address(r), LESS_THAN_SCALAR, get_address(x), x.get_x(), y);
	}

	template<class U> void equal_to(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_func2_logical(get_address(r), EQUAL_TO, get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void equal_to(const qboolean<typename qtype_traits<U>::mapped_type>& r, const qscalar<U>& x, const U& y)
	{
		process_func2_logical_sy(get_address(r), EQUAL_TO_SCALAR, get_address(x), x.get_x(), y);
	}

	// qif statement

	template<class U> void iff(const qscalar<U>& r, const qboolean<typename qtype_traits<U>::mapped_type>& cond, const qscalar<U>& x, const qscalar<U>& y)
	{
		process_iff(get_address(r), IFF, get_address(cond), get_data_member(cond), get_address(x), x.get_x(), get_address(y), y.get_x());
	}

	template<class U> void iff(const qscalar<U>& r, const qboolean<typename qtype_traits<U>::mapped_type>& cond, const qscalar<U>& x, const U& y)
	{
		process_iff_sy(get_address(r), IFF_SCALAR, get_address(cond), get_data_member(cond), get_address(x), x.get_x(), y);
	}

	template<class U> void iff(const qscalar<U>& r, const qboolean<typename qtype_traits<U>::mapped_type>& cond, const U& x, const U& y)
	{
		process_iff_sx_sy(get_address(r), IFF_SCALAR_SCALAR, get_address(cond), get_data_member(cond), x, y);
	}

	// Boolean

	template<class U> void destroy(const qboolean<U>& x)
	{
		destroy_boolean(get_address(x));
	}

	template<class U> void equal_bool(const qboolean<U>& r, const typename graph_traits<T>::boolean_type& x)
	{
		equal_bool(get_address(r), x); // Special handling of operator=(bool)
	}

	template<class U> void equal(const qboolean<U>& r, const qboolean<U>& x)
	{
		process_boolean1(get_address(r), BOOLEAN_EQUAL, get_address(x), get_data_member(x));
	}

	// Logical operator

	template<class U> void logical_and(const qboolean<U>& r, const qboolean<U>& x, const qboolean<U>& y)
	{
		process_boolean2(get_address(r), BOOLEAN_AND, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void logical_and(const qboolean<U>& r, const qboolean<U>& x, const typename qboolean_storage_traits<U>::storage_type& y)
	{
		process_boolean2_by(get_address(r), BOOLEAN_AND_BOOL, get_address(x), get_data_member(x), y);
	}

	template<class U> void logical_or(const qboolean<U>& r, const qboolean<U>& x, const qboolean<U>& y)
	{
		process_boolean2(get_address(r), BOOLEAN_OR, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void logical_or(const qboolean<U>& r, const qboolean<U>& x, const typename qboolean_storage_traits<U>::storage_type& y)
	{
		process_boolean2_by(get_address(r), BOOLEAN_OR_BOOL, get_address(x), get_data_member(x), y);
	}

	template<class U> void logical_not(const qboolean<U>& r, const qboolean<U>& x)
	{
		process_boolean1(get_address(r), BOOLEAN_NOT, get_address(x), get_data_member(x));
	}

	template<class U> void equal_to(const qboolean<U>& r, const qboolean<U>& x, const qboolean<U>& y)
	{
		process_boolean2(get_address(r), BOOLEAN_EQUAL_TO, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void equal_to(const qboolean<U>& r, const qboolean<U>& x, const typename qboolean_storage_traits<U>::storage_type& y)
	{
		process_boolean2_by(get_address(r), BOOLEAN_EQUAL_TO_BOOL, get_address(x), get_data_member(x), y);
	}

	// Boolean iff

	template<class U> void iff(const qboolean<U>& r, const qboolean<U>& cond, const qboolean<U>& if_true, const qboolean<U>& if_false)
	{
		process_boolean_iff(get_address(r), BOOLEAN_IFF, get_address(cond), get_data_member(cond), get_address(if_true), get_data_member(if_true), get_address(if_false), get_data_member(if_false));
	}

	template<class U> void iff(const qboolean<U>& r, const qboolean<U>& cond, const qboolean<U>& if_true, const typename qboolean_storage_traits<U>::storage_type& if_false)
	{
		process_boolean_iff_by(get_address(r), BOOLEAN_IFF_BOOL, get_address(cond), get_data_member(cond), get_address(if_true), get_data_member(if_true), if_false);
	}

	template<class U> void iff(const qboolean<U>& r, const qboolean<U>& cond, const typename qboolean_storage_traits<U>::storage_type& if_true, const typename qboolean_storage_traits<U>::storage_type& if_false)
	{
		process_boolean_iff_bx_by(get_address(r), BOOLEAN_IFF_BOOL_BOOL, get_address(cond), get_data_member(cond), if_true, if_false);
	}

	// Integer functions

	template<class U> void destroy(const qinteger<U>& x)
	{
		destroy_integer(get_address(x));
	}

	template<class U> void equal_int(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x)
	{
		equal_int(get_address(r), x); // Special handling of operator=(int)
	}

	template<class U> void equal(const qinteger<U>& r, const qinteger<U>& x)
	{
		process_integer1(get_address(r), INTEGER_EQUAL, get_address(x), get_data_member(x));
	}

	template<class U> void add(const qinteger<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2(get_address(r), INTEGER_ADD, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void add(const qinteger<U>& r, const qinteger<U>& x)
	{
		add(r, r, x);
	}

	template<class U> void add(const qinteger<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_iy(get_address(r), INTEGER_ADD_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void add(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x)
	{
		add(r, r, x);
	}

	template<class U> void subtract(const qinteger<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2(get_address(r), INTEGER_SUBTRACT, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void subtract(const qinteger<U>& r, const qinteger<U>& x)
	{
		subtract(r, r, x);
	}

	template<class U> void subtract(const qinteger<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_iy(get_address(r), INTEGER_SUBTRACT_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void subtract(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x)
	{
		subtract(r, r, x);
	}

	template<class U> void subtract(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x, const qinteger<U>& y)
	{
		process_integer2_ix(get_address(r), INTEGER_INT_SUBTRACT, x, get_address(y), get_data_member(y));
	}

	template<class U> void multiply(const qinteger<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2(get_address(r), INTEGER_MULTIPLY, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void multiply(const qinteger<U>& r, const qinteger<U>& x)
	{
		multiply(r, r, x);
	}

	template<class U> void multiply(const qinteger<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_iy(get_address(r), INTEGER_MULTIPLY_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void multiply(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x)
	{
		multiply(r, r, x);
	}

	template<class U> void divide(const qinteger<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2(get_address(r), INTEGER_DIVIDE, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void divide(const qinteger<U>& r, const qinteger<U>& x)
	{
		divide(r, r, x);
	}

	template<class U> void divide(const qinteger<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_iy(get_address(r), INTEGER_DIVIDE_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void divide(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x)
	{
		divide(r, r, x);
	}

	template<class U> void divide(const qinteger<U>& r, const typename qinteger_traits<U>::storage_type& x, const qinteger<U>& y)
	{
		process_integer2_ix(get_address(r), INTEGER_INT_DIVIDE, x, get_address(y), get_data_member(y));
	}

	template<class U>
	void change_sign(const qinteger<U>& r, const qinteger<U>& x)
	{
		process_integer1(get_address(r), INTEGER_CHANGE_SIGN, get_address(x), get_data_member(x));
	}

	template<class U> void equal_to(const qboolean<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2_logical(get_address(r), INTEGER_EQUAL_TO, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void equal_to(const qboolean<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_logical_iy(get_address(r), INTEGER_EQUAL_TO_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void greater_than(const qboolean<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2_logical(get_address(r), INTEGER_GREATER_THAN, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void greater_than(const qboolean<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_logical_iy(get_address(r), INTEGER_GREATER_THAN_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void less_than(const qboolean<U>& r, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer2_logical(get_address(r), INTEGER_LESS_THAN, get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void less_than(const qboolean<U>& r, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer2_logical_iy(get_address(r), INTEGER_LESS_THAN_INT, get_address(x), get_data_member(x), y);
	}

	template<class U> void iff(const qinteger<U>& r, const qboolean<U>& cond, const qinteger<U>& x, const qinteger<U>& y)
	{
		process_integer_iff(get_address(r), INTEGER_IFF, get_address(cond), get_data_member(cond), get_address(x), get_data_member(x), get_address(y), get_data_member(y));
	}

	template<class U> void iff(const qinteger<U>& r, const qboolean<U>& cond, const qinteger<U>& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer_iff_iy(get_address(r), INTEGER_IFF_INT, get_address(cond), get_data_member(cond), get_address(x), get_data_member(x), y);
	}

	template<class U> void iff(const qinteger<U>& r, const qboolean<U>& cond, const typename qinteger_traits<U>::storage_type& x, const typename qinteger_traits<U>::storage_type& y)
	{
		process_integer_iff_ix_iy(get_address(r), INTEGER_IFF_INT_INT, get_address(cond), get_data_member(cond), x, y);
	}

	// Pure virtual functions to be implemented in redirect or implementation
	// Recording

	virtual void destroy(uint64_t x) = 0;

	virtual void input(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s) = 0;
	virtual void param(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s) = 0;
	virtual void output(uint64_t x, const char* s) = 0;
	virtual void checkpoint() = 0;
	virtual void equal_scalar(uint64_t r, const typename graph_traits<T>::scalar_type& xv) = 0;
	virtual void process_equal(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv) = 0;
	virtual void process_func1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv) = 0;
	virtual void process_func2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_func2_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_func2_sx(uint64_t r, Operation op, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) = 0;

	virtual void destroy_boolean(uint64_t x) = 0;
	virtual void equal_bool(uint64_t r, const typename graph_traits<T>::boolean_type& xv) = 0;

	virtual void process_func2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_iff_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) = 0;
	virtual void process_boolean1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv) = 0;
	virtual void process_boolean2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv) = 0;
	virtual void process_boolean2_by(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) = 0;
	virtual void process_boolean_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv) = 0;
	virtual void process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) = 0;
	virtual void process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) = 0;

	virtual void destroy_integer(uint64_t x) = 0;
	virtual void equal_int(uint64_t r, const typename graph_traits<T>::integer_type& xv) = 0;

	virtual void process_integer1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv) = 0;
	virtual void process_integer2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer2_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer2_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) = 0;
	virtual void process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) = 0;

	// Post-processing

	virtual void post_process() {}

};

template<class T>
qrecorder_i<T>* make_recorder();

template<class T>
void reset_recorder(qrecorder_i<T>* i = 0);

template<class T>
qrecorder_i<T>* recorder_ptr();

