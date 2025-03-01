#pragma once

#include "intrin.h"
#include "qscalar_i.h"

template<class T> T one() { return (T)1.0; }
template<> __m512d one() { return _mm512_set1_pd(1.0); }
template<> __m512 one() { return _mm512_set1_ps(1.0f); }
template<> __m256d one() { return _mm256_set1_pd(1.0); }
template<> __m256 one() { return _mm256_set1_ps(1.0f); }
template<> __m128d one() { return _mm_set1_pd(1.0); }
template<> __m128 one() { return _mm_set1_ps(1.0f); }
template<> double one() { return 1.0; }
template<> float one() { return 1.0f; }


template<class T> T xvalue() { return (T)0.0; }
template<> __m512d xvalue() { return _mm512_set_pd(1.1, -0.2, 0.3, 2.0, 1.2, -3.1, 1.0, 0.41); }
template<> __m512 xvalue() { return _mm512_set_ps(1.1f, -0.29f, 0.3f, 2.0f, 1.095f, -3.1f, 1.0f, 0.31f, 0.45f, 0.67f, 0.37f, 0.48f, -0.4f, -0.5f, -0.78f, -0.81f); }
template<> __m256d xvalue() { return _mm256_set_pd(1.1, -0.2, 0.3, 2.0); }
template<> __m256 xvalue() { return _mm256_set_ps(1.1f, -0.37f, 0.3f, 1.0f, 1.09f, -2.4f, 0.33f, 0.44f); }
template<> __m128d xvalue() { return _mm_set_pd(-2.1, 1.7); }
template<> __m128 xvalue() { return _mm_set_ps(1.1f, -1.11f, -2.4f, 0.44f); }
template<> double xvalue() { return 1.1; }
template<> float xvalue() { return 1.1f; }

template<class T> T log_xvalue() { return (T)0.0; }
template<> __m512d log_xvalue() { return _mm512_set_pd(1.1, 0.2, 0.3, 2.0, 1.2, 3.1, 1.0, 0.11); }
template<> __m512 log_xvalue() { return _mm512_set_ps(1.1f, 0.2f, 0.3f, 2.0f, 1.2f, 3.1f, 1.0f, 0.11f, 0.45f, 0.67f, 0.12f, 0.1f, 0.4f, 0.5f, 0.78f, 0.81f); }
template<> __m256d log_xvalue() { return _mm256_set_pd(1.1, 0.2, 0.3, 2.0); }
template<> __m256 log_xvalue() { return _mm256_set_ps(1.1f, 0.2f, 0.3f, 2.0f, 1.3f, 4.2f, 1.1f, 0.1f); }
template<> __m128d log_xvalue() { return _mm_set_pd(2.1, 1.7); }
template<> __m128 log_xvalue() { return _mm_set_ps(1.1f, 3.7f, 1.7f, 1.2f); }
template<> double log_xvalue() { return 1.1; }
template<> float log_xvalue() { return 1.1f; }

template<class T> T pow_xvalue() { return (T)0.0; }
template<> __m512d pow_xvalue() { return _mm512_set_pd(1.1, 0.2, 0.3, 0.2, 0.12, 0.31, 1.0, 0.11); }
template<> __m512 pow_xvalue() { return _mm512_set_ps(1.1f, 0.2f, 0.3f, 0.21f, 0.12f, 0.31f, 1.0f, 0.11f, 0.45f, 0.67f, 0.12f, 0.105f, 0.4f, 0.5f, 0.78f, 0.81f); }
template<> __m256d pow_xvalue() { return _mm256_set_pd(1.1, 0.2, 0.3, 1.0); }
template<> __m256 pow_xvalue() { return _mm256_set_ps(1.1f, 0.2f, 0.3f, 0.20f, 0.13f, 0.42f, 1.1f, 0.105f); }
template<> __m128d pow_xvalue() { return _mm_set_pd(0.21, 0.17); }
template<> __m128 pow_xvalue() { return _mm_set_ps(1.1f, 0.37f, 0.17f, 0.23f); }
template<> double pow_xvalue() { return 1.1; }
template<> float pow_xvalue() { return 1.1f; }


template<class T> T trig_xvalue() { return (T)0.0; }
template<> __m512d trig_xvalue() { return _mm512_set_pd(-0.9, 0.2, 0.3, 0.8, 0.99, -0.99, 0.13, -0.23); }
template<> __m512 trig_xvalue() { return _mm512_set_ps(-0.9f, 0.2f, 0.3f, 0.8f, 0.92f, -0.93f, 0.13f, -0.23f, 0.78f, 0.12f, 0.48f, 0.17f, 0.19f, 0.23f, 0.37f, 0.123f); }
template<> __m256d trig_xvalue() { return _mm256_set_pd(-0.9, 0.2, 0.3, 0.8); }
template<> __m256 trig_xvalue() { return _mm256_set_ps(-0.9f, 0.2f, 0.3f, 0.8f, -0.2f, 0.23f, 0.33f, -0.44f); }
template<> __m128d trig_xvalue() { return _mm_set_pd(0.0, 0.5); }
template<> __m128 trig_xvalue() { return _mm_set_ps(0.17f, -0.22f, 0.57f, -0.38f); }
template<> double trig_xvalue() { return -0.9; }
template<> float trig_xvalue() { return -0.9f; }


template<class T> T epsilon() { return (T)0.0; }
template<> double epsilon() { return 1e-12; }
template<> float epsilon() { return 1e-6f; }

template<class T, class U>
struct MathFunc1_Rec_template
{
	template<class Op>
	static void run(Op op, qscalar<T>& x)
	{
		auto epsT = epsilon<typename qtype_traits<T>::type>();
		auto epsU = epsilon<typename qtype_traits<U>::type>();

		double eps = epsT;
		if (eps < epsU)
			eps = epsU;

		qrecorder<U> rec;

		rec.start();

		rec.input(x);

		auto y = op(x);

		rec.output(y);

		rec.stop();

		auto g = rec.graph();

		auto ws = g.workspace();

		g.run(ws);

		auto res = ws.get_value(y);

		for (uint64_t i = 0; i < qtype_traits<U>::alignment(); ++i)
			Assert::AreEqual((double)y[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(res, i), (double)eps);

	}

};

#define CHECK_RECORDING_XVALUE(A,B) \
		{ \
			qscalar<double> xd = B<double>(); \
			qscalar<float> xf = B<float>(); \
			qscalar<__m256d> x256d = B<__m256d>(); \
			qscalar<__m256> x256 = B<__m256>(); \
			qscalar<__m128d> x128d = B<__m128d>(); \
			qscalar<__m128> x128 = B<__m128>(); \
			\
			if (cpu_info::has_avx512()) \
			{ \
				qscalar<__m512d> x512d = B<__m512d>(); \
				qscalar<__m512> x512 = B<__m512>(); \
				MathFunc1_Rec_template<double, __m512d>::run([](const qscalar<double>& x) { return A(x); }, xd); \
				MathFunc1_Rec_template<float, __m512d>::run([](const qscalar<float>& x) { return A(x); }, xf); \
				MathFunc1_Rec_template<__m512d, __m512d>::run([](const qscalar<__m512d>& x) { return A(x); }, x512d); \
				MathFunc1_Rec_template<double, __m512>::run([](const qscalar<double>& x) { return A(x); }, xd); \
				MathFunc1_Rec_template<float, __m512>::run([](const qscalar<float>& x) { return A(x); }, xf); \
				MathFunc1_Rec_template<__m512, __m512>::run([](const qscalar<__m512>& x) { return A(x); }, x512); \
			} \
			MathFunc1_Rec_template<double, __m256d>::run([](const qscalar<double>& x) { return A(x); }, xd); \
			MathFunc1_Rec_template<float, __m256d>::run([](const qscalar<float>& x) { return A(x); }, xf); \
			MathFunc1_Rec_template<__m256d, __m256d>::run([](const qscalar<__m256d>& x) { return A(x); }, x256d); \
			MathFunc1_Rec_template<double, __m256>::run([](const qscalar<double>& x) { return A(x); }, xd); \
			MathFunc1_Rec_template<float, __m256>::run([](const qscalar<float>& x) { return A(x); }, xf); \
			MathFunc1_Rec_template<__m256, __m256>::run([](const qscalar<__m256>& x) { return A(x); }, x256); \
			MathFunc1_Rec_template<double, __m128d>::run([](const qscalar<double>& x) { return A(x); }, xd); \
			MathFunc1_Rec_template<float, __m128d>::run([](const qscalar<float>& x) { return A(x); }, xf); \
			MathFunc1_Rec_template<__m128d, __m128d>::run([](const qscalar<__m128d>& x) { return A(x); }, x128d); \
			MathFunc1_Rec_template<double, __m128>::run([](const qscalar<double>& x) { return A(x); }, xd); \
			MathFunc1_Rec_template<float, __m128>::run([](const qscalar<float>& x) { return A(x); }, xf); \
			MathFunc1_Rec_template<__m128, __m128>::run([](const qscalar<__m128>& x) { return A(x); }, x128); \
		}

#define CHECK_RECORDING(A) CHECK_RECORDING_XVALUE(A,xvalue)
#define CHECK_RECORDING_LOG(A) CHECK_RECORDING_XVALUE(A,log_xvalue)
#define CHECK_RECORDING_TRIG(A) CHECK_RECORDING_XVALUE(A,trig_xvalue)


template<class T, class U>
struct MathFunc1_Forward_template
{
	template<class Op, class dOp>
	static void run(Op op, dOp dop, qscalar<T>& x, uint64_t n = qtype_traits<U>::alignment())
	{
		auto epsT = epsilon<typename qtype_traits<T>::type>();
		auto epsU = epsilon<typename qtype_traits<typename graph_traits<U>::scalar_type>::type>();

		double eps = epsT;
		if (eps < epsU)
			eps = epsU;

		qrecorder<U> rec;

		rec.start();

		rec.input(x);

		auto y = op(x);

		rec.output(y);

		rec.stop();

		auto g = rec.graph().forwardAD();

		auto ws = g.workspace();

		ws.set_dual(x, 1.0);

		g.run(ws);

		auto r = ws.get_value(y);
		auto dr = ws.get_dual(y);

		auto dy = dop(x);

		for (uint64_t i = 0; i < n; ++i)
		{
			Assert::AreEqual((double)y[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(r, i), (double)eps);
			Assert::AreEqual((double)dy[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(dr, i), (double)eps);
		}

	}

};

#define CHECK_FORWARD_XVALUE(A,dA,B) \
		{ \
			qscalar<double> xd = B<double>(); \
			qscalar<float> xf = B<float>(); \
			qscalar<__m256d> x256d = B<__m256d>(); \
			qscalar<__m256> x256 = B<__m256>(); \
			qscalar<__m128d> x128d = B<__m128d>(); \
			qscalar<__m128> x128 = B<__m128>(); \
			\
			if (cpu_info::has_avx512()) \
			{ \
				qscalar<__m512d> x512d = B<__m512d>(); \
				qscalar<__m512> x512 = B<__m512>(); \
				MathFunc1_Forward_template<double, __m512d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
				MathFunc1_Forward_template<float, __m512d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
				MathFunc1_Forward_template<__m512d, __m512d>::run([](const qscalar<__m512d>& x) { return A(x); }, [](const qscalar<__m512d>& x) { return dA(x); }, x512d); \
				MathFunc1_Forward_template<double, __m512>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
				MathFunc1_Forward_template<float, __m512>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
				MathFunc1_Forward_template<__m512, __m512>::run([](const qscalar<__m512>& x) { return A(x); }, [](const qscalar<__m512>& x) { return dA(x); }, x512); \
			} \
			MathFunc1_Forward_template<double, __m256d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Forward_template<float, __m256d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Forward_template<__m256d, __m256d>::run([](const qscalar<__m256d>& x) { return A(x); }, [](const qscalar<__m256d>& x) { return dA(x); }, x256d); \
			MathFunc1_Forward_template<double, __m256>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Forward_template<float, __m256>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Forward_template<__m256, __m256>::run([](const qscalar<__m256>& x) { return A(x); }, [](const qscalar<__m256>& x) { return dA(x); }, x256); \
			MathFunc1_Forward_template<double, __m128d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Forward_template<float, __m128d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Forward_template<__m128d, __m128d>::run([](const qscalar<__m128d>& x) { return A(x); }, [](const qscalar<__m128d>& x) { return dA(x); }, x128d); \
			MathFunc1_Forward_template<double, __m128>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Forward_template<float, __m128>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Forward_template<__m128, __m128>::run([](const qscalar<__m128>& x) { return A(x); }, [](const qscalar<__m128>& x) { return dA(x); }, x128); \
		}

#define CHECK_FORWARD(A,dA) CHECK_FORWARD_XVALUE(A,dA,xvalue);
#define CHECK_FORWARD_LOG(A,dA) CHECK_FORWARD_XVALUE(A,dA,log_xvalue);
#define CHECK_FORWARD_TRIG(A,dA) CHECK_FORWARD_XVALUE(A,dA,trig_xvalue);

template<class T, class U>
struct MathFunc1_Backward_template
{
	template<class Op, class dOp>
	static void run(Op op, dOp dop, qscalar<T>& x)
	{

		auto epsT = epsilon<typename qtype_traits<T>::type>();
		auto epsU = epsilon<typename qtype_traits<U>::type>();

		double eps = epsT;
		if (eps < epsU)
			eps = epsU;

		qrecorder<U> rec;

		rec.start();

		rec.input(x);

		auto y = op(x);

		rec.output(y);

		rec.stop();

		auto g = rec.graph().backwardAD();

		auto ws = g.workspace();

		ws.set_adjoint(y, 1.0);

		g.run(ws);

		auto r = ws.get_value(y);
		auto dr = ws.get_adjoint(x);

		auto dy = dop(x);

		for (uint64_t i = 0; i < qtype_traits<U>::alignment(); ++i)
		{
			Assert::AreEqual((double)y[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(r, i), (double)eps);
			Assert::AreEqual((double)dy[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(dr, i), (double)eps);
		}

	}

};

#define CHECK_BACKWARD_XVALUE(A,dA,B) \
		{ \
			qscalar<double> xd = B<double>(); \
			qscalar<float> xf = B<float>(); \
			qscalar<__m256d> x256d = B<__m256d>(); \
			qscalar<__m256> x256 = B<__m256>(); \
			qscalar<__m128d> x128d = B<__m128d>(); \
			qscalar<__m128> x128 = B<__m128>(); \
			\
			if (cpu_info::has_avx512()) \
			{ \
				qscalar<__m512d> x512d = B<__m512d>(); \
				qscalar<__m512> x512 = B<__m512>(); \
				MathFunc1_Backward_template<double, __m512d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
				MathFunc1_Backward_template<float, __m512d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
				MathFunc1_Backward_template<__m512d, __m512d>::run([](const qscalar<__m512d>& x) { return A(x); }, [](const qscalar<__m512d>& x) { return dA(x); }, x512d); \
				MathFunc1_Backward_template<double, __m512>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
				MathFunc1_Backward_template<float, __m512>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
				MathFunc1_Backward_template<__m512, __m512>::run([](const qscalar<__m512>& x) { return A(x); }, [](const qscalar<__m512>& x) { return dA(x); }, x512); \
			} \
			MathFunc1_Backward_template<double, __m256d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Backward_template<float, __m256d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Backward_template<__m256d, __m256d>::run([](const qscalar<__m256d>& x) { return A(x); }, [](const qscalar<__m256d>& x) { return dA(x); }, x256d); \
			MathFunc1_Backward_template<double, __m256>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Backward_template<float, __m256>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Backward_template<__m256, __m256>::run([](const qscalar<__m256>& x) { return A(x); }, [](const qscalar<__m256>& x) { return dA(x); }, x256); \
			MathFunc1_Backward_template<double, __m128d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Backward_template<float, __m128d>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Backward_template<__m128d, __m128d>::run([](const qscalar<__m128d>& x) { return A(x); }, [](const qscalar<__m128d>& x) { return dA(x); }, x128d); \
			MathFunc1_Backward_template<double, __m128>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<double>& x) { return dA(x); }, xd); \
			MathFunc1_Backward_template<float, __m128>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<float>& x) { return dA(x); }, xf); \
			MathFunc1_Backward_template<__m128, __m128>::run([](const qscalar<__m128>& x) { return A(x); }, [](const qscalar<__m128>& x) { return dA(x); }, x128); \
		}

#define CHECK_BACKWARD(A,dA) CHECK_BACKWARD_XVALUE(A,dA,xvalue);
#define CHECK_BACKWARD_LOG(A,dA) CHECK_BACKWARD_XVALUE(A,dA,log_xvalue);
#define CHECK_BACKWARD_TRIG(A,dA) CHECK_BACKWARD_XVALUE(A,dA,trig_xvalue);

#define _USE_MATH_DEFINES
#include "math.h"

namespace std {

	double normal_cdf(const double& x)
	{
		return std::erfc(-x * M_SQRT1_2) * 0.5;
	}

	float normal_cdf(const float& x)
	{
		return std::erfc(-x * (float)M_SQRT1_2) * 0.5f;
	}

}

template<class T, class Op >
void check_results(const qscalar<T>& x, const qscalar<T>& y, const typename qtype_traits<T>::type& eps, Op op)
{
	for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
		Assert::AreEqual((double)y[i], (double)op(x[i]), (double)eps);
}

#define MATHFUNC1_CHECK_RESULTS(A) check_results(x, A(x), eps, [](const typename qtype_traits<T>::type& x) { return A(x); })
#define MATHFUNC1_CHECK_RESULTS2(A,B) check_results(x, A(x), eps, [](const typename qtype_traits<T>::type& x) { return B(x); })

template<class T>
static T inverse(const T& x) { return graph_traits<T>::cast(1.0) / x; }

template<class T>
static qdual<T> inverse(const qdual<T>& x) { T one(1.0); return one / x; }


#define MATHFUNC1_CHECK_RESULTS_DUAL(A,B) \
		check_results(xd.x(), A(xd).x(), eps, [](const typename qtype_traits<T>::type& v) { return A(v); }); \
		check_results(xd.x(), A(xd).dx(), eps, [](const typename qtype_traits<T>::type& v) { return B(v); }) 

template<class T>
qscalar<T> dlog(const qscalar<T>& x)
{
	return 1.0 / x;
}

template<class T>
qscalar<T> dlog2(const qscalar<T>& x)
{
	return 1.0 / (x * graph_traits<T>::cast(0.69314718055994529));
}

template<class T>
qscalar<T> dlog10(const qscalar<T>& x)
{
	return 1.0 / (x * graph_traits<T>::cast(2.3025850929940459));
}

template<class T>
qscalar<T> derfc(const qscalar<T>& x)
{
	return -std::exp(-x * x) * graph_traits<T>::cast(M_2_SQRTPI);
}

template<class T>
qscalar<T> dsqrt(const qscalar<T>& x)
{
	return 0.5/std::sqrt(x);
}

template<class T>
qscalar<T> dtan(const qscalar<T>& x)
{
	return 1.0/(std::cos(x)*std::cos(x));
}

template<class T>
qscalar<T> dchs(const qscalar<T>& x)
{
	qscalar<T> y(-1.0);
	return y;
}

template<class T>
qscalar<T> dasin(const qscalar<T>& x)
{
	return 1.0/std::sqrt(1.0-x*x);
}

template<class T>
qscalar<T> dacos(const qscalar<T>& x)
{
	return -1.0 / std::sqrt(1.0 - x * x);
}

template<class T>
qscalar<T> datan(const qscalar<T>& x)
{
	return 1.0 / (1.0 + x * x);
}

template<class T>
qscalar<T> dtanh(const qscalar<T>& x)
{
	return 1.0 / (std::cosh(x) * std::cosh(x));
}


template<class T>
std::shared_ptr<typename qtype_traits<T>::type[]> alloc_array(uint64_t n, const qscalar<T>& x)
{
	std::shared_ptr<typename qtype_traits<T>::type[]> ptr(new typename qtype_traits<T>::type[n]);
	for (uint64_t i = 0; i < n; ++i)
		ptr.get()[i] = x[i % qtype_traits<T>::alignment()];
	return ptr;
}

template<class T, class U>
struct MathFunc1_Forward_template_Ptr
{
	template<class Op, class dOp>
	static void run(Op op, dOp dop, const qscalar<U>& X, uint64_t n)
	{
		auto epsT = epsilon<typename qtype_traits<T>::type>();
		auto epsU = epsilon<typename qtype_traits<typename graph_traits<U>::scalar_type>::type>();

		qscalar<typename qtype_traits<U>::type> x(X[0]);

		auto ptr = alloc_array(n, X);

		double eps = epsT;
		if (eps < epsU)
			eps = epsU;

		qrecorder<U*> rec;

		rec.start();

		rec.input(x);

		auto y = op(x);

		rec.output(y);

		rec.stop();

		auto g = rec.graph().forwardAD();

		auto ws = g.workspace();

		g.allocate(ws,n);

		ws.set_value(x, ptr.get());
		ws.set_dual(x, 1.0);

		g.run(ws);

		auto r = ws.get_value(y);
		auto dr = ws.get_dual(y);

		auto dy = dop(X);

		for (uint64_t i = 0; i < n; ++i)
		{
			Assert::AreEqual((double)dy[i % qtype_traits<U>::alignment()], (double)dr[i], (double)eps);
			Assert::AreEqual((double)op(qscalar<typename qtype_traits<U>::type>(X[i % qtype_traits<U>::alignment()]))[0], (double)r[i], (double)eps);
		}
	}

};

#define CHECK_FORWARD_XVALUE_PTR(A,dA,B,n) \
		{ \
			MathFunc1_Forward_template_Ptr<double, __m256d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m256d>& x) { return dA(x); }, B<__m256d>(), n); \
			MathFunc1_Forward_template_Ptr<float, __m256>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m256>& x) { return dA(x); }, B<__m256>(), n); \
			MathFunc1_Forward_template_Ptr<double, __m128d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m128d>& x) { return dA(x); }, B<__m128d>(), n); \
			MathFunc1_Forward_template_Ptr<float, __m128>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m128>& x) { return dA(x); }, B<__m128>(), n); \
		}


#define CHECK_FORWARD_XVALUE_PTR_AVX512(A,dA,B,n) \
		{ \
			if (cpu_info::has_avx512()) \
			{ \
				MathFunc1_Forward_template_Ptr<double, __m512d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m512d>& x) { return dA(x); }, B<__m512d>(), n); \
				MathFunc1_Forward_template_Ptr<float, __m512>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m512>& x) { return dA(x); }, B<__m512>(), n); \
			} \
		}


template<class T, class U>
struct MathFunc1_Backward_template_Ptr
{
	template<class Op, class dOp>
	static void run(Op op, dOp dop, const qscalar<U>& X, uint64_t n)
	{
		auto epsT = epsilon<typename qtype_traits<T>::type>();
		auto epsU = epsilon<typename qtype_traits<typename graph_traits<U>::scalar_type>::type>();

		qscalar<typename qtype_traits<U>::type> x(X[0]);

		auto ptr = alloc_array(n, X);

		double eps = epsT;
		if (eps < epsU)
			eps = epsU;

		qrecorder<U*> rec;

		rec.start();

		rec.input(x);

		auto y = op(x);

		rec.output(y);

		rec.stop();

		auto g = rec.graph().backwardAD();

		auto ws = g.workspace();

		g.allocate(ws,n);

		ws.set_value(x, ptr.get());
		ws.set_adjoint(y, 1.0);

		g.run(ws);

		auto r = ws.get_value(y);
		auto dr = ws.get_adjoint(x);

		auto dy = dop(X);

		for (uint64_t i = 0; i < n; ++i)
		{
			Assert::AreEqual((double)dy[i % qtype_traits<U>::alignment()], (double)dr[i], (double)eps);
			Assert::AreEqual((double)op(qscalar<typename qtype_traits<U>::type>(X[i % qtype_traits<U>::alignment()]))[0], (double)r[i], (double)eps);
		}
	}

};

#define CHECK_BACKWARD_XVALUE_PTR(A,dA,B,n) \
		{ \
			MathFunc1_Backward_template_Ptr<double, __m256d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m256d>& x) { return dA(x); }, B<__m256d>(), n); \
			MathFunc1_Backward_template_Ptr<float, __m256>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m256>& x) { return dA(x); }, B<__m256>(), n); \
			MathFunc1_Backward_template_Ptr<double, __m128d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m128d>& x) { return dA(x); }, B<__m128d>(), n); \
			MathFunc1_Backward_template_Ptr<float, __m128>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m128>& x) { return dA(x); }, B<__m128>(), n); \
		}

#define CHECK_BACKWARD_XVALUE_PTR_AVX512(A,dA,B,n) \
		{ \
			if (cpu_info::has_avx512()) \
			{ \
				MathFunc1_Backward_template_Ptr<double, __m512d>::run([](const qscalar<double>& x) { return A(x); }, [](const qscalar<__m512d>& x) { return dA(x); }, B<__m512d>(), n); \
				MathFunc1_Backward_template_Ptr<float, __m512>::run([](const qscalar<float>& x) { return A(x); }, [](const qscalar<__m512>& x) { return dA(x); }, B<__m512>(), n); \
			} \
		}