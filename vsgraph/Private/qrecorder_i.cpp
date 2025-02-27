#include "qdefines.h"
#include "qrecorder_i.h"
#include "qrecorder_traits.h"
#include "intrin.h"

template<class T>
qrecorder_i<T>::qrecorder_i() : m_g(make_graph<T>()), m_add_variable_equal(false)
{}

template<class T>
qrecorder_i<T>::~qrecorder_i()
{}

namespace {

	template<class T>
	class qrecorder_impl : public qrecorder_i<T> {

	public:

		qrecorder_impl() {}
		~qrecorder_impl() {}

		void destroy(uint64_t x)
		{
			qrecorder_i<T>::m_g->destroy(x);
		}

		void input(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s)
		{
			qrecorder_i<T>::m_g->input(x, xv, s);
		}

		void param(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s)
		{
			qrecorder_i<T>::m_g->param(x, xv, s);
		}

		void output(uint64_t x, const char* s)
		{
			qrecorder_i<T>::m_g->output(x, s);
		}

		void checkpoint()
		{
			qrecorder_i<T>::m_g->checkpoint();
		}

		void equal_scalar(uint64_t r, const typename graph_traits<T>::scalar_type& xv)
		{
			qrecorder_i<T>::m_g->equal_scalar(r, xv);
		}

		void process_equal(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv)
		{
			qrecorder_i<T>::m_g->process_equal(r, op, x, xv);
		}

		void process_func1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv)
		{
			qrecorder_i<T>::m_g->process_func1(r, op, x, xv);
		}

		void process_func2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_func2(r, op, x, xv, y, yv);
		}

		void process_func2_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_func2_sy(r, op, x, xv, yv);
		}

		void process_func2_sx(uint64_t r, Operation op, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_func2_sx(r, op, xv, y, yv);
		}

		void process_func2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_func2_logical(r, op, x, xv, y, yv);
		}

		void process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_func2_logical_sy(r, op, x, xv, yv);
		}

		void process_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_iff(r, op, c, cv, x, xv, y, yv);
		}

		void process_iff_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_iff_sy(r, op, c, cv, x, xv, yv);
		}

		void process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			qrecorder_i<T>::m_g->process_iff_sx_sy(r, op, c, cv, xv, yv);
		}

		// Logical

		void destroy_boolean(uint64_t x)
		{
			qrecorder_i<T>::m_g->destroy_boolean(x);
		}

		void equal_bool(uint64_t r, const typename graph_traits<T>::boolean_type& xv)
		{
			qrecorder_i<T>::m_g->equal_bool(r, xv);
		}

		void process_boolean1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv)
		{
			qrecorder_i<T>::m_g->process_boolean1(r, op, x, xv);
		}

		void process_boolean2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv)
		{
			qrecorder_i<T>::m_g->process_boolean2(r, op, x, xv, y, yv);
		}

		void process_boolean2_by(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			qrecorder_i<T>::m_g->process_boolean2_by(r, op, x, xv, yv);
		}

		// Logical iff

		void process_boolean_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv)
		{
			qrecorder_i<T>::m_g->process_boolean_iff(r, op, c, cv, x, xv, y, yv);
		}

		void process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			qrecorder_i<T>::m_g->process_boolean_iff_by(r, op, c, cv, x, xv, yv);
		}

		void process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			qrecorder_i<T>::m_g->process_boolean_iff_bx_by(r, op, c, cv, xv, yv);
		}

		// Integer

		void destroy_integer(uint64_t x)
		{
			qrecorder_i<T>::m_g->destroy_integer(x);
		}

		void equal_int(uint64_t r, const typename graph_traits<T>::integer_type& xv)
		{
			qrecorder_i<T>::m_g->equal_int(r, xv);
		}

		void process_integer1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv)
		{
			qrecorder_i<T>::m_g->process_integer1(r, op, x, xv);
		}

		void process_integer2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer2(r, op, x, xv, y, yv);
		}

		void process_integer2_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer2_iy(r, op, x, xv, yv);
		}

		void process_integer2_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer2_ix(r, op, xv, y,yv);
		}

		void process_integer2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer2_logical(r, op, x, xv, y, yv);
		}

		void process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer2_logical_iy(r, op, x, xv, yv);
		}

		void process_integer_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer_iff(r, op, c, cv, x, xv, y, yv);
		}

		void process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer_iff_iy(r, op, c, cv, x, xv, yv);
		}

		void process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			qrecorder_i<T>::m_g->process_integer_iff_ix_iy(r, op, c, cv, xv, yv);
		}

		// Post processing

		void post_process()
		{
			qrecorder_i<T>::m_g->post_process();
		}


	};

	template<class T, class U>
	class qrecorder_redirect : public qrecorder_i<T> {

		qrecorder_i<U>* m_r;

	public:

		qrecorder_redirect(qrecorder_i<U>* r) : m_r(r) {}
		~qrecorder_redirect() {}

		void destroy(uint64_t x)
		{
			m_r->destroy(x);
		}

		void input(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s)
		{
			m_r->input(x, graph_traits<U>::cast(xv), s);
		}

		void param(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s)
		{
			m_r->param(x, graph_traits<U>::cast(xv), s);
		}

		void output(uint64_t x, const char* s)
		{
			m_r->output(x, s);
		}

		void checkpoint()
		{
			m_r->checkpoint();
		}

		void equal_scalar(uint64_t r, const typename graph_traits<T>::scalar_type& xv)
		{
			m_r->equal_scalar(r, graph_traits<U>::cast(xv));
		}

		void process_equal(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv)
		{
			m_r->process_equal(r, op, x, graph_traits<U>::cast(xv));
		}

		void process_func1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv)
		{
			m_r->process_func1(r, op, x, graph_traits<U>::cast(xv));
		}

		void process_func2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_func2(r, op, x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_func2_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_func2_sy(r, op, x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_func2_sx(uint64_t r, Operation op, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_func2_sx(r, op, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_func2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_func2_logical(r, op, x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_func2_logical_sy(r, op, x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_iff(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_iff_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_iff_sy(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv)
		{
			m_r->process_iff_sx_sy(r, op, c, graph_traits<U>::cast(cv), graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void destroy_boolean(uint64_t x)
		{
			m_r->destroy_boolean(x);
		}

		void equal_bool(uint64_t r, const typename graph_traits<T>::boolean_type& xv)
		{
			m_r->equal_bool(r, graph_traits<U>::cast(xv));
		}

		void process_boolean1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv)
		{
			m_r->process_boolean1(r, op, x, graph_traits<U>::cast(xv));
		}

		void process_boolean2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv)
		{
			m_r->process_boolean2(r, op, x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_boolean2_by(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			m_r->process_boolean2_by(r, op, x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_boolean_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv)
		{
			m_r->process_boolean_iff(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			m_r->process_boolean_iff_by(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv)
		{
			m_r->process_boolean_iff_bx_by(r, op, c, graph_traits<U>::cast(cv), graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void destroy_integer(uint64_t x)
		{
			m_r->destroy_integer(x);
		}

		void equal_int(uint64_t r, const typename graph_traits<T>::integer_type& xv)
		{
			m_r->equal_int(r, graph_traits<U>::cast(xv));
		}

		void process_integer1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv)
		{
			m_r->process_integer1(r, op, x, graph_traits<U>::cast(xv));
		}

		void process_integer2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer2(r, op, x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_integer2_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer2_iy(r, op, x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_integer2_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer2_ix(r, op, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_integer2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer2_logical(r, op, x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer2_logical_iy(r, op, x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_integer_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer_iff(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), y, graph_traits<U>::cast(yv));
		}

		void process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer_iff_iy(r, op, c, graph_traits<U>::cast(cv), x, graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

		void process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv)
		{
			m_r->process_integer_iff_ix_iy(r, op, c, graph_traits<U>::cast(cv), graph_traits<U>::cast(xv), graph_traits<U>::cast(yv));
		}

	};

}

template qrecorder_i<double>* make_recorder<double>();
template qrecorder_i<float>* make_recorder<float>();
#ifdef INSTANTIATE_AVX512
template qrecorder_i<__m512d>* make_recorder<__m512d>();
template qrecorder_i<__m512>* make_recorder<__m512>();
#endif
template qrecorder_i<__m256d>* make_recorder<__m256d>();
template qrecorder_i<__m256>* make_recorder<__m256>();
template qrecorder_i<__m128d>* make_recorder<__m128d>();
template qrecorder_i<__m128>* make_recorder<__m128>();
template qrecorder_i<double*>* make_recorder<double*>();
template qrecorder_i<float*>* make_recorder<float*>();
#ifdef INSTANTIATE_AVX512
template qrecorder_i<__m512d*>* make_recorder<__m512d*>();
template qrecorder_i<__m512*>* make_recorder<__m512*>();
#endif
template qrecorder_i<__m256d*>* make_recorder<__m256d*>();
template qrecorder_i<__m256*>* make_recorder<__m256*>();
template qrecorder_i<__m128d*>* make_recorder<__m128d*>();
template qrecorder_i<__m128*>* make_recorder<__m128*>();

template<class T>
qrecorder_i<T>* make_recorder()
{
	return new qrecorder_impl<T>();
}

void recorder_traits<double>::redirect(qrecorder_i<double>* i)
{
	reset_recorder<float>(new qrecorder_redirect<float, double>(i));
}

void recorder_traits<double>::undirect()
{
	reset_recorder<float>();
}

void recorder_traits<float>::redirect(qrecorder_i<float>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, float>(i));
}

void recorder_traits<float>::undirect()
{
	reset_recorder<double>();
}


void recorder_traits<double*>::redirect(qrecorder_i<double*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, double*>(i));
}

void recorder_traits<double*>::undirect()
{
	reset_recorder<double>();
}

void recorder_traits<float*>::redirect(qrecorder_i<float*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, float*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, float*>(i));
}

void recorder_traits<float*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

#ifdef INSTANTIATE_AVX512
void recorder_traits<__m512d*>::redirect(qrecorder_i<__m512d*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m512d*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m512d*>(i));
}

void recorder_traits<__m512d*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}
#endif

void recorder_traits<__m256d*>::redirect(qrecorder_i<__m256d*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m256d*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m256d*>(i));
}

void recorder_traits<__m256d*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m128d*>::redirect(qrecorder_i<__m128d*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m128d*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m128d*>(i));
}

void recorder_traits<__m128d*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

#ifdef INSTANTIATE_AVX512
void recorder_traits<__m512*>::redirect(qrecorder_i<__m512*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m512*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m512*>(i));
}

void recorder_traits<__m512*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}
#endif

void recorder_traits<__m256*>::redirect(qrecorder_i<__m256*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m256*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m256*>(i));
}

void recorder_traits<__m256*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m128*>::redirect(qrecorder_i<__m128*>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m128*>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m128*>(i));
}

void recorder_traits<__m128*>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

#ifdef INSTANTIATE_AVX512
void recorder_traits<__m512d>::redirect(qrecorder_i<__m512d>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m512d>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m512d>(i));
}

void recorder_traits<__m512d>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m512>::redirect(qrecorder_i<__m512>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m512>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m512>(i));
}

void recorder_traits<__m512>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}
#endif

void recorder_traits<__m256d>::redirect(qrecorder_i<__m256d>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m256d>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m256d>(i));
}

void recorder_traits<__m256d>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m256>::redirect(qrecorder_i<__m256>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m256>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m256>(i));
}

void recorder_traits<__m256>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m128d>::redirect(qrecorder_i<__m128d>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m128d>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m128d>(i));
}

void recorder_traits<__m128d>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}

void recorder_traits<__m128>::redirect(qrecorder_i<__m128>* i)
{
	reset_recorder<double>(new qrecorder_redirect<double, __m128>(i));
	reset_recorder<float>(new qrecorder_redirect<float, __m128>(i));
}

void recorder_traits<__m128>::undirect()
{
	reset_recorder<double>();
	reset_recorder<float>();
}



