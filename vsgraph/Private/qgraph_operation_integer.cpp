#include "qgraph_operation.h"

//${begin}
void graph_op_traits<__m512d>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m512d>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512d>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m512d>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m512d>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m512d>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m512d>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m512d>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m512d>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m512d>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m512d>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m512d>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m512d>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m512d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512d>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m256d>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m256d>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256d>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m256d>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m256d>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m256d>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m256d>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m256d>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m256d>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m256d>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m256d>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m256d>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m256d>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m256d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256d>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m128d>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m128d>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128d>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m128d>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m128d>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m128d>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m128d>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m128d>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m128d>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m128d>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m128d>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m128d>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128d>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m128d>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m128d>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128d>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m512>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m512>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m512>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m512>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m512>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m512>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m512>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m512>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m512>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m512>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m512>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m512>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m512>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m512>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m512>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m256>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m256>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m256>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m256>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m256>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m256>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m256>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m256>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m256>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m256>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m256>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m256>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m256>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m256>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m256>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m128>::integer_equal_int(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x.m_x[i];
}

void graph_op_traits<__m128>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m128>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m128>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m128>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m128>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m128>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]+y.m_x[i];
}

void graph_op_traits<__m128>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]-y.m_x[i];
}

void graph_op_traits<__m128>::integer_int_subtract(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x.m_x[i]-y[i];
}

void graph_op_traits<__m128>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]*y.m_x[i];
}

void graph_op_traits<__m128>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const qinteger_traits<__m128>::storage_type& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x[i]/y.m_x[i];
}

void graph_op_traits<__m128>::integer_int_divide(std::vector<int64_t>& r, const qinteger_traits<__m128>::storage_type& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = 0; i < qtype_traits<__m128>::alignment(); ++i)
		r[i] = x.m_x[i]/y[i];
}

void graph_op_traits<__m512d*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m512d*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512d*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m512d*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m512d*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m512d*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m512d*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m512d*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m512d*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m512d*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m512d*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m512d*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m512d*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<__m256d*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m256d*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256d*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m256d*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m256d*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m256d*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m256d*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m256d*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m256d*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m256d*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m256d*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m256d*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m256d*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<__m128d*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m128d*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128d*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m128d*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m128d*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m128d*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m128d*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m128d*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m128d*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m128d*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m128d*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m128d*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m128d*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<double*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<double*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<double*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<double*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<double*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<double*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<double*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<double*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<double*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<double*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<double*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<double*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<double*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<__m512*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m512*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m512*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m512*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m512*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m512*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m512*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m512*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m512*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m512*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m512*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m512*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m512*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<__m256*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m256*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m256*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m256*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m256*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m256*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m256*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m256*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m256*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m256*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m256*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m256*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m256*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<__m128*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<__m128*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<__m128*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<__m128*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<__m128*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<__m128*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<__m128*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<__m128*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<__m128*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<__m128*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<__m128*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<__m128*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<__m128*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

void graph_op_traits<float*>::integer_equal_int(std::vector<int64_t>& r, const int64_t& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x;
}

void graph_op_traits<float*>::integer_equal(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i];
}

void graph_op_traits<float*>::integer_change_sign(std::vector<int64_t>& r, const std::vector<int64_t>& x, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = -x[i];
}

void graph_op_traits<float*>::integer_add(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y[i];
}

void graph_op_traits<float*>::integer_subtract(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y[i];
}

void graph_op_traits<float*>::integer_multiply(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y[i];
}

void graph_op_traits<float*>::integer_divide(std::vector<int64_t>& r, const std::vector<int64_t>& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y[i];
}

void graph_op_traits<float*>::integer_add_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]+y;
}

void graph_op_traits<float*>::integer_subtract_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]-y;
}

void graph_op_traits<float*>::integer_int_subtract(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x-y[i];
}

void graph_op_traits<float*>::integer_multiply_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]*y;
}

void graph_op_traits<float*>::integer_divide_int(std::vector<int64_t>& r, const std::vector<int64_t>& x, const int64_t& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x[i]/y;
}

void graph_op_traits<float*>::integer_int_divide(std::vector<int64_t>& r, const int64_t& x, const std::vector<int64_t>& y, const uint64_t& offset, const uint64_t& n)
{
	for (uint64_t i = offset; i < n; ++i)
		r[i] = x/y[i];
}

//${end}
