#include "qgraph_operation.h"
#include "qscalar_i.h"

//${begin}
void graph_op_traits<__m512d>::greater_than(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m512d>::less_than(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m512d>::equal_to(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m512d>::greater_than_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m512d>::less_than_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m512d>::equal_to_scalar(std::vector<bool>& r, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m512d>::iff(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512d>::iff_scalar(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512d>::iff_scalar_scalar(__m512d& r, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512d>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m512d>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m512d>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m512d>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m512d>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m512d>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m512d>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m512d>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m512d>::storage_type& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m512d>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512d>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512d>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m512d>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512d>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512d>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512d>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512d>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512d>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512d>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d>::iff_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m512d>::iff_px_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& y, const __m512d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0 : bracket(dy, i);
	}
}

void graph_op_traits<__m512d>::iff_py_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m512d>::iff_scalar_forward(__m512d& r, __m512d& dr, const std::vector<bool>& c, const __m512d& x, const __m512d& dx, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m512d>::iff_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m512d>::iff_px_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, const __m512d& y, __m512d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m512d>::iff_py_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m512d>::iff_scalar_backward(const __m512d& r, const __m512d& wr, const std::vector<bool>& c, const __m512d& x, __m512d& wx, const __m512d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m256d>::greater_than(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m256d>::less_than(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m256d>::equal_to(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m256d>::greater_than_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m256d>::less_than_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m256d>::equal_to_scalar(std::vector<bool>& r, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m256d>::iff(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256d>::iff_scalar(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256d>::iff_scalar_scalar(__m256d& r, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256d>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m256d>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m256d>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m256d>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m256d>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m256d>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m256d>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m256d>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m256d>::storage_type& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m256d>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256d>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256d>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m256d>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256d>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256d>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256d>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256d>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256d>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256d>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d>::iff_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m256d>::iff_px_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& y, const __m256d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0 : bracket(dy, i);
	}
}

void graph_op_traits<__m256d>::iff_py_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m256d>::iff_scalar_forward(__m256d& r, __m256d& dr, const std::vector<bool>& c, const __m256d& x, const __m256d& dx, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m256d>::iff_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m256d>::iff_px_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, const __m256d& y, __m256d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m256d>::iff_py_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m256d>::iff_scalar_backward(const __m256d& r, const __m256d& wr, const std::vector<bool>& c, const __m256d& x, __m256d& wx, const __m256d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m128d>::greater_than(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m128d>::less_than(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m128d>::equal_to(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m128d>::greater_than_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m128d>::less_than_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m128d>::equal_to_scalar(std::vector<bool>& r, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m128d>::iff(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128d>::iff_scalar(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128d>::iff_scalar_scalar(__m128d& r, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128d>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m128d>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m128d>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m128d>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m128d>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m128d>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m128d>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m128d>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m128d>::storage_type& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m128d>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128d>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128d>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m128d>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128d>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128d>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128d>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128d>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128d>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128d>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d>::iff_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m128d>::iff_px_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& y, const __m128d& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0 : bracket(dy, i);
	}
}

void graph_op_traits<__m128d>::iff_py_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m128d>::iff_scalar_forward(__m128d& r, __m128d& dr, const std::vector<bool>& c, const __m128d& x, const __m128d& dx, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0;
	}
}

void graph_op_traits<__m128d>::iff_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m128d>::iff_px_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, const __m128d& y, __m128d& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m128d>::iff_py_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m128d>::iff_scalar_backward(const __m128d& r, const __m128d& wr, const std::vector<bool>& c, const __m128d& x, __m128d& wx, const __m128d& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m512>::greater_than(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m512>::less_than(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m512>::equal_to(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m512>::greater_than_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m512>::less_than_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m512>::equal_to_scalar(std::vector<bool>& r, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m512>::iff(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512>::iff_scalar(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512>::iff_scalar_scalar(__m512& r, const std::vector<bool>& c, const __m512& x, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m512>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m512>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m512>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m512>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m512>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m512>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m512>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m512>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m512>::storage_type& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m512>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m512>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512>::iff_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m512>::iff_px_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& y, const __m512& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0f : bracket(dy, i);
	}
}

void graph_op_traits<__m512>::iff_py_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m512>::iff_scalar_forward(__m512& r, __m512& dr, const std::vector<bool>& c, const __m512& x, const __m512& dx, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m512>::iff_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m512>::iff_px_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, const __m512& y, __m512& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m512>::iff_py_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m512>::iff_scalar_backward(const __m512& r, const __m512& wr, const std::vector<bool>& c, const __m512& x, __m512& wx, const __m512& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m256>::greater_than(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m256>::less_than(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m256>::equal_to(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m256>::greater_than_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m256>::less_than_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m256>::equal_to_scalar(std::vector<bool>& r, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m256>::iff(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256>::iff_scalar(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256>::iff_scalar_scalar(__m256& r, const std::vector<bool>& c, const __m256& x, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m256>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m256>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m256>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m256>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m256>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m256>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m256>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m256>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m256>::storage_type& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m256>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m256>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256>::iff_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m256>::iff_px_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& y, const __m256& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0f : bracket(dy, i);
	}
}

void graph_op_traits<__m256>::iff_py_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m256>::iff_scalar_forward(__m256& r, __m256& dr, const std::vector<bool>& c, const __m256& x, const __m256& dx, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m256>::iff_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m256>::iff_px_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, const __m256& y, __m256& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m256>::iff_py_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m256>::iff_scalar_backward(const __m256& r, const __m256& wr, const std::vector<bool>& c, const __m256& x, __m256& wx, const __m256& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m128>::greater_than(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m128>::less_than(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m128>::equal_to(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m128>::greater_than_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) > bracket(y, i);
}

void graph_op_traits<__m128>::less_than_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) < bracket(y, i);
}

void graph_op_traits<__m128>::equal_to_scalar(std::vector<bool>& r, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = bracket(x, i) == bracket(y, i);
}

void graph_op_traits<__m128>::iff(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128>::iff_scalar(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128>::iff_scalar_scalar(__m128& r, const std::vector<bool>& c, const __m128& x, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
}

void graph_op_traits<__m128>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m128>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m128>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m128>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]>y.m_x[i];
}

void graph_op_traits<__m128>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]<y.m_x[i];
}

void graph_op_traits<__m128>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]==y.m_x[i];
}

void graph_op_traits<__m128>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y.m_x[i];
}

void graph_op_traits<__m128>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const qinteger_traits<__m128>::storage_type& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x.m_x[i] : y.m_x[i];
}

void graph_op_traits<__m128>::boolean_equal_bool(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m128>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128>::iff_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : bracket(dy, i);
	}
}

void graph_op_traits<__m128>::iff_px_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& y, const __m128& dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? 0.0f : bracket(dy, i);
	}
}

void graph_op_traits<__m128>::iff_py_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m128>::iff_scalar_forward(__m128& r, __m128& dr, const std::vector<bool>& c, const __m128& x, const __m128& dx, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
	{
		bracket(r, i) = c[i] ? bracket(x, i) : bracket(y, i);
		bracket(dr, i) = c[i] ? bracket(dx, i) : 0.0f;
	}
}

void graph_op_traits<__m128>::iff_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
		else
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m128>::iff_px_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, const __m128& y, __m128& wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		if (!c[i])
			bracket(wy, i) += bracket(wr, i);
}

void graph_op_traits<__m128>::iff_py_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m128>::iff_scalar_backward(const __m128& r, const __m128& wr, const std::vector<bool>& c, const __m128& x, __m128& wx, const __m128& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		if (c[i])
			bracket(wx, i) += bracket(wr, i);
}

void graph_op_traits<__m512d*>::greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m512d*>::less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m512d*>::equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512d*>::greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m512d*>::less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m512d*>::equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m512d*>::iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d*>::iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512d*>::iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512d*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m512d*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m512d*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m512d*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m512d*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m512d*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m512d*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512d*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512d*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m512d*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512d*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m512d*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512d*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512d*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512d*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m512d*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m512d*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m512d*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512d*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512d*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512d*>::iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m512d*>::iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0 : dy[i];
	}
}

void graph_op_traits<__m512d*>::iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m512d*>::iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m512d*>::iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m512d*>::iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m512d*>::iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m512d*>::iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m256d*>::greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m256d*>::less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m256d*>::equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256d*>::greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m256d*>::less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m256d*>::equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m256d*>::iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d*>::iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256d*>::iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256d*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m256d*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m256d*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m256d*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m256d*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m256d*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m256d*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256d*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256d*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m256d*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256d*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m256d*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256d*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256d*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256d*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m256d*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m256d*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m256d*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256d*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256d*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256d*>::iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m256d*>::iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0 : dy[i];
	}
}

void graph_op_traits<__m256d*>::iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m256d*>::iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m256d*>::iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m256d*>::iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m256d*>::iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m256d*>::iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m128d*>::greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m128d*>::less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m128d*>::equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128d*>::greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m128d*>::less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m128d*>::equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m128d*>::iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d*>::iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128d*>::iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128d*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m128d*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m128d*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m128d*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m128d*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m128d*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m128d*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128d*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128d*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m128d*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128d*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m128d*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128d*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128d*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128d*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m128d*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m128d*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m128d*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128d*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128d*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128d*>::iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m128d*>::iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0 : dy[i];
	}
}

void graph_op_traits<__m128d*>::iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m128d*>::iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<__m128d*>::iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m128d*>::iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m128d*>::iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m128d*>::iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<double*>::greater_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<double*>::less_than(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<double*>::equal_to(std::vector<bool>& r, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<double*>::greater_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<double*>::less_than_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<double*>::equal_to_scalar(std::vector<bool>& r, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<double*>::iff(double* r, const std::vector<bool>& c, const double* x, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<double*>::iff_scalar(double* r, const std::vector<bool>& c, const double* x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<double*>::iff_scalar_scalar(double* r, const std::vector<bool>& c, const double& x, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<double*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<double*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<double*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<double*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<double*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<double*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<double*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<double*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<double*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<double*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<double*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<double*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<double*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<double*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<double*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<double*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<double*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<double*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<double*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<double*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<double*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<double*>::iff_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<double*>::iff_px_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* y, const double* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0 : dy[i];
	}
}

void graph_op_traits<double*>::iff_py_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<double*>::iff_scalar_forward(double* r, double* dr, const std::vector<bool>& c, const double* x, const double* dx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0;
	}
}

void graph_op_traits<double*>::iff_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<double*>::iff_px_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, const double* y, double* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<double*>::iff_py_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<double*>::iff_scalar_backward(const double* r, const double* wr, const std::vector<bool>& c, const double* x, double* wx, const double& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m512*>::greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m512*>::less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m512*>::equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512*>::greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m512*>::less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m512*>::equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m512*>::iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512*>::iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512*>::iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m512*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m512*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m512*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m512*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m512*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m512*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m512*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m512*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m512*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m512*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m512*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m512*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m512*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m512*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m512*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m512*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m512*>::iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m512*>::iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0f : dy[i];
	}
}

void graph_op_traits<__m512*>::iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m512*>::iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m512*>::iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m512*>::iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m512*>::iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m512*>::iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m256*>::greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m256*>::less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m256*>::equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256*>::greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m256*>::less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m256*>::equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m256*>::iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256*>::iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256*>::iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m256*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m256*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m256*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m256*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m256*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m256*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m256*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m256*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m256*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m256*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m256*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m256*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m256*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m256*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m256*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m256*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m256*>::iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m256*>::iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0f : dy[i];
	}
}

void graph_op_traits<__m256*>::iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m256*>::iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m256*>::iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m256*>::iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m256*>::iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m256*>::iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m128*>::greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<__m128*>::less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<__m128*>::equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128*>::greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<__m128*>::less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<__m128*>::equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m128*>::iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128*>::iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128*>::iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<__m128*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<__m128*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<__m128*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<__m128*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<__m128*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<__m128*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m128*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<__m128*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<__m128*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<__m128*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<__m128*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<__m128*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<__m128*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<__m128*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<__m128*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<__m128*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<__m128*>::iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<__m128*>::iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0f : dy[i];
	}
}

void graph_op_traits<__m128*>::iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m128*>::iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<__m128*>::iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<__m128*>::iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<__m128*>::iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<__m128*>::iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<float*>::greater_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y[i];
}

void graph_op_traits<float*>::less_than(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y[i];
}

void graph_op_traits<float*>::equal_to(std::vector<bool>& r, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<float*>::greater_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] > y;
}

void graph_op_traits<float*>::less_than_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] < y;
}

void graph_op_traits<float*>::equal_to_scalar(std::vector<bool>& r, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<float*>::iff(float* r, const std::vector<bool>& c, const float* x, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<float*>::iff_scalar(float* r, const std::vector<bool>& c, const float* x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<float*>::iff_scalar_scalar(float* r, const std::vector<bool>& c, const float& x, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<float*>::integer_greater_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y[i];
}

void graph_op_traits<float*>::integer_less_than(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y[i];
}

void graph_op_traits<float*>::integer_equal_to(std::vector<bool>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y[i];
}

void graph_op_traits<float*>::integer_greater_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]>y;
}

void graph_op_traits<float*>::integer_less_than_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]<y;
}

void graph_op_traits<float*>::integer_equal_to_int(std::vector<bool>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]==y;
}

void graph_op_traits<float*>::integer_iff(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<float*>::integer_iff_int(std::vector<int64_t>& r, const std::vector<bool>& c, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<float*>::integer_iff_int_int(std::vector<int64_t>& r, const std::vector<bool>& c, const int64_t& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<float*>::boolean_equal_bool(std::vector<bool>& r, const bool& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<float*>::boolean_equal(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<float*>::boolean_not(std::vector<bool>& r, const std::vector<bool>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = !x[i];
}

void graph_op_traits<float*>::boolean_and(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y[i];
}

void graph_op_traits<float*>::boolean_or(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y[i];
}

void graph_op_traits<float*>::boolean_equal_to(std::vector<bool>& r, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y[i];
}

void graph_op_traits<float*>::boolean_and_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] && y;
}

void graph_op_traits<float*>::boolean_or_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] || y;
}

void graph_op_traits<float*>::boolean_equal_to_bool(std::vector<bool>& r, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i] == y;
}

void graph_op_traits<float*>::boolean_iff(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const std::vector<bool>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y[i];
}

void graph_op_traits<float*>::boolean_iff_bool(std::vector<bool>& r, const std::vector<bool>& c, const std::vector<bool>& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x[i] : y;
}

void graph_op_traits<float*>::boolean_iff_bool_bool(std::vector<bool>& r, const std::vector<bool>& c, const bool& x, const bool& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = c[i] ? x : y;
}

void graph_op_traits<float*>::iff_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : dy[i];
	}
}

void graph_op_traits<float*>::iff_px_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* y, const float* dy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? 0.0f : dy[i];
	}
}

void graph_op_traits<float*>::iff_py_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y[i];
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<float*>::iff_scalar_forward(float* r, float* dr, const std::vector<bool>& c, const float* x, const float* dx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
	{
		r[i] = c[i] ? x[i] : y;
		dr[i] = c[i] ? dx[i] : 0.0f;
	}
}

void graph_op_traits<float*>::iff_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
		else
			wy[i] += wr[i];
}

void graph_op_traits<float*>::iff_px_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, const float* y, float* wy, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (!c[i])
			wy[i] += wr[i];
}

void graph_op_traits<float*>::iff_py_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float* y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

void graph_op_traits<float*>::iff_scalar_backward(const float* r, const float* wr, const std::vector<bool>& c, const float* x, float* wx, const float& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		if (c[i])
			wx[i] += wr[i];
}

//${end}
