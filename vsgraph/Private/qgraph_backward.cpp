#include "qdefines.h"
#include "qgraph_backward.h"
#include "qgraph_operation.h"
#include "qgraph_i.h"
#include "qworkspace_i.h"
#include "intrin.h"

template class graph_backward<double>;
template class graph_backward<float>;
#ifdef INSTANTIATE_AVX512
template class graph_backward<__m512d>;
template class graph_backward<__m512>;
#endif
template class graph_backward<__m256d>;
template class graph_backward<__m256>;
template class graph_backward<__m128d>;
template class graph_backward<__m128>;

template class graph_backward<double*>;
template class graph_backward<float*>;
#ifdef INSTANTIATE_AVX512
template class graph_backward<__m512d*>;
template class graph_backward<__m512*>;
#endif
template class graph_backward<__m256d*>;
template class graph_backward<__m256*>;
template class graph_backward<__m128d*>;
template class graph_backward<__m128*>;

#include "qgraph_function.h"
#include "qgraph_sweep.h"

template<class T>
graph_backward<T>::graph_backward(const qgraph_i<T>& g, qworkspace_i<T>& ws, ADType direction) :
	m_var_counter(ws.get_var_counter()),
	m_wksp(ws.wksp()),
	m_integer_wksp(ws.get_integer_wksp()),
	m_boolean_wksp(ws.get_boolean_wksp()),
	m_wksp_index(ws.get_wksp_index()),
	m_integer_wksp_index(ws.get_integer_wksp_index()),
	m_boolean_wksp_index(ws.get_boolean_wksp_index()),
	m_scalar(ws.get_scalar()),
	m_integer(ws.get_integer()),
	m_boolean(ws.get_boolean()),
	m_skip_ops_init(g.get_skip_ops_init()),
	m_skip_ops_arg_init(g.get_skip_ops_arg_init()),
	m_skip_index(0),
	m_zero(graph_traits<T>::cast(0.0)),
	m_offset(0),
	m_n(ws.get_n())
{
	graph_function<T> gf(ws);
	if (direction != BACKWARD)
		g.sweep_forward(gf);
	if (direction != FORWARD)
		g.sweep_backward(*this,gf);
}


template<class T>
graph_backward<T>::~graph_backward()
{}

template<class T>
void graph_backward<T>::init_adjoint(const uint64_t& x_i, uint64_t clock)
{
	if (clock == m_skip_ops_init[m_skip_index] && x_i == m_skip_ops_arg_init[m_skip_index])
		++m_skip_index;
	else
		graph_op_traits<T>::equal_scalar(m_wksp[m_wksp_index[x_i + m_var_counter]], m_zero, m_offset, m_n);
}

//${begin}
template<class T> void graph_backward<T>::equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::equal_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::squareroot_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::change_sign_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::exponential_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::logarithm_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::logarithm2_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::logarithm10_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::complementary_errorfunc_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::sine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::cosine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::tangent_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::arc_sine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::arc_cosine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::arc_tangent_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::hyperbolic_sine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::hyperbolic_cosine_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::hyperbolic_tangent_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::add_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::add_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::add_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::subtract_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::subtract_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::subtract_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::multiply_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::multiply_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::multiply_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::divide_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::divide_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::divide_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::maximum_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::maximum_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::maximum_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::minimum_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::minimum_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::minimum_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::power_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::power_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::power_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::add_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::subtract_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::scalar_subtract_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_scalar[x_i], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::multiply_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::divide_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::scalar_divide_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_scalar[x_i], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::maximum_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::minimum_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::power_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::scalar_power_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_scalar[x_i], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
}

template<class T> void graph_backward<T>::greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	if (x_i != y_i)
		init_adjoint(y_i, clock);
	graph_op_traits<T>::iff_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(y_i, clock);
	graph_op_traits<T>::iff_px_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]], m_offset, m_n);
}

template<class T> void graph_backward<T>::iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::iff_py_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_offset, m_n);
}

template<class T> void graph_backward<T>::iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
}

template<class T> void graph_backward<T>::iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	init_adjoint(x_i, clock);
	graph_op_traits<T>::iff_scalar_backward(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i], m_offset, m_n);
}

template<class T> void graph_backward<T>::iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i) 
{
}

template<class T> void graph_backward<T>::iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

template<class T> void graph_backward<T>::boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

template<class T> void graph_backward<T>::boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
}

//${end}