#pragma once

#include "qinteger.h"
using namespace vstech;

#include "qboolean_i.h"

template<class T>
struct integer_operation_traits {

	static typename qinteger_traits<T>::storage_type create(const uint64_t& i)
	{
		typename qinteger_traits<T>::storage_type s;
		assign(s, i);
		return s;
	}

	static const int64_t& bracket(const typename qinteger_traits<T>::storage_type& s, const uint64_t& i)
	{
		return s.m_x[i];
	}

	static int64_t& bracket(typename qinteger_traits<T>::storage_type& s, const uint64_t& i)
	{
		return s.m_x[i];
	}

	static void assign(typename qinteger_traits<T>::storage_type& s, const int64_t& i)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			s.m_x[j] = i;
	}

	static void assign(typename qinteger_traits<T>::storage_type& s, const typename qinteger_traits<T>::storage_type& i)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			s.m_x[j] = i.m_x[j];
	}

	static void add(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] + y.m_x[j];
	}

	static void subtract(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] - y.m_x[j];
	}

	static void multiply(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] * y.m_x[j];
	}

	static void divide(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] / y.m_x[j];
	}

	static void add(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const int64_t& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] + y;
	}

	static void subtract(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const int64_t& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] - y;
	}

	static void subtract(typename qinteger_traits<T>::storage_type& r, const int64_t& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x - y.m_x[j];
	}

	static void multiply(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const int64_t& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] * y;
	}

	static void divide(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x, const int64_t& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x.m_x[j] / y;
	}

	static void divide(typename qinteger_traits<T>::storage_type& r, const int64_t& x, const typename qinteger_traits<T>::storage_type& y)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = x / y.m_x[j];
	}

	static void chs(typename qinteger_traits<T>::storage_type& r, const typename qinteger_traits<T>::storage_type& x)
	{
		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			r.m_x[j] = -x.m_x[j];
	}

	static qboolean_p* equal(const typename qinteger_traits<T>::storage_type& lhs, const typename qinteger_traits<T>::storage_type& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] == rhs.m_x[i];
		return new qboolean_i(r);
	}

	static qboolean_p* equal(const typename qinteger_traits<T>::storage_type& lhs, const int64_t& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] == rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* not_equal(const typename qinteger_traits<T>::storage_type& lhs, const typename qinteger_traits<T>::storage_type& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] != rhs.m_x[i];
		return new qboolean_i(r);

	}

	static qboolean_p* not_equal(const typename qinteger_traits<T>::storage_type& lhs, const int64_t& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] != rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* greater_than(const typename qinteger_traits<T>::storage_type& lhs, const typename qinteger_traits<T>::storage_type& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] > rhs.m_x[i];
		return new qboolean_i(r);

	}

	static qboolean_p* greater_than(const typename qinteger_traits<T>::storage_type& lhs, const int64_t& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] > rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* less_than(const typename qinteger_traits<T>::storage_type& lhs, const typename qinteger_traits<T>::storage_type& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] < rhs.m_x[i];
		return new qboolean_i(r);

	}

	static qboolean_p* less_than(const typename qinteger_traits<T>::storage_type& lhs, const int64_t& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs.m_x[i] < rhs;
		return new qboolean_i(r);
	}

	static void qif(typename qinteger_traits<T>::storage_type& r, const typename qboolean_traits<T>::storage_type& cond, const typename qinteger_traits<T>::storage_type& if_true, const typename qinteger_traits<T>::storage_type& if_false)
	{
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r.m_x[i] = (condition[i] ? if_true : if_false).m_x[i];
	}

	static void qif(typename qinteger_traits<T>::storage_type& r, const typename qboolean_traits<T>::storage_type& cond, const typename qinteger_traits<T>::storage_type& if_true, const int64_t& if_false)
	{
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r.m_x[i] = condition[i] ? if_true.m_x[i] : if_false;
	}

	static void qif(typename qinteger_traits<T>::storage_type& r, const typename qboolean_traits<T>::storage_type& cond, const int64_t& if_true, const int64_t& if_false)
	{
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r.m_x[i] = condition[i] ? if_true : if_false;
	}

};

template<>
struct integer_operation_traits<double> {

	static const int64_t create(const uint64_t& i)
	{
		return i;
	}

	static const int64_t& bracket(const int64_t& s, const uint64_t& i)
	{
		return s;
	}

	static int64_t& bracket(int64_t& s, const uint64_t& i)
	{
		return s;
	}

	static void assign(int64_t& s, const int64_t& i)
	{
		s = i;
	}

	static void add(int64_t& r, const int64_t& x, const int64_t& y)
	{
		r = x + y;
	}

	static void subtract(int64_t& r, const int64_t& x, const int64_t& y)
	{
		r = x + y;
	}

	static void multiply(int64_t& r, const int64_t& x, const int64_t& y)
	{
		r = x * y;
	}

	static void divide(int64_t& r, const int64_t& x, const int64_t& y)
	{
		r = x / y;
	}

	static void chs(int64_t& r, const int64_t& x)
	{
		r = -x;
	}

	static bool equal(const int64_t& lhs, const int64_t& rhs)
	{
		return lhs == rhs;
	}

	static bool not_equal(const int64_t& lhs, const int64_t& rhs)
	{
		return lhs != rhs;
	}

	static bool greater_than(const int64_t& lhs, const int64_t& rhs)
	{
		return lhs > rhs;
	}

	static bool less_than(const int64_t& lhs, const int64_t& rhs)
	{
		return lhs < rhs;
	}

	static void qif(int64_t& r, bool cond, const int64_t& if_true, const int64_t& if_false)
	{
		r = cond ? if_true : if_false;
	}

};

template<class T>
uint64_t get_address(const qinteger<T>& x)
{
	return (uint64_t)&x;
}


template<class T>
typename qinteger_traits<T>::storage_type get_data_member(const qinteger<T>& i)
{
	typename qinteger_traits<T>::storage_type s;
	memcpy(&s, &i, sizeof(qinteger<T>));
	return s;
}

template<class T>
struct graph_traits;

template<class T>
struct integer_type_predicate
{
	bool operator()(const typename graph_traits<T>::integer_type& lhs, const typename graph_traits<T>::integer_type& rhs) const
	{
		typedef typename qtype_traits<typename graph_traits<T>::scalar_type>::mapped_type scalar_type;

		for (uint64_t i = 0; i < qtype_traits<scalar_type>::alignment(); ++i)
			if (integer_operation_traits<scalar_type>::bracket(lhs, i) < integer_operation_traits<scalar_type>::bracket(rhs, i))
				return true;
			else if (integer_operation_traits<scalar_type>::bracket(lhs, i) > integer_operation_traits<scalar_type>::bracket(rhs, i))
				return false;

		return false;
	}
};

template<class T>
struct qinteger_storage_traits {

	typedef std::vector<int64_t> storage_type;
	static std::vector<int64_t> storage(uint64_t n) { return std::vector<int64_t>(n, 0); }
	static void assign(std::vector<int64_t>& x, const typename graph_traits<T>::integer_type& y) { for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i) x[i] = y.m_x[i]; }
	static void assign_int(std::vector<int64_t>& x, const int64_t& y) { std::fill(x.begin(), x.end(), y); }
};

template<>
struct qinteger_storage_traits<double> {

	typedef int64_t storage_type;
	static int64_t storage(uint64_t n) { return 0; }
	static void assign(int64_t& x, const int64_t& y) { x = y; }

};



