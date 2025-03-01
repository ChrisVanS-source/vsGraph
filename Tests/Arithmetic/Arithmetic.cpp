#include "UnitTestDefines.h"
#include "qdefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"

namespace Arithmetic
{
	TEST_CLASS(Arithmetic)
	{
	public:

		CPPUNIT_TEST_SUITE(Arithmetic);
		CPPUNIT_TEST(MathArithmetic);
		CPPUNIT_TEST(MathArithmeticPtr);
		CPPUNIT_TEST_SUITE_END();

		template<class T>
		struct Function2 {

			template<class Op, class dOpdx, class dOpdy>
			static void run(Op op, dOpdx dopdx, dOpdy dopdy, const T& val)
			{
				auto eps = epsilon<typename qtype_traits<T>::type>();

				qscalar<T> x = val, y = val;
				y *= (y-(typename qtype_traits<T>::type)0.1);

				qscalar<T> r_s = op(x,y);
				qscalar<T> drx_s = dopdx(x,y);
				qscalar<T> dry_s = dopdy(x,y);

				qrecorder<T> rec;

				rec.start();

				rec.input(x);
				rec.input(y);

				auto z = op(x,y);

				rec.output(z);

				rec.stop();

				auto g = rec.graph();

				auto ws = g.workspace();

				g.run(ws);

				auto res = ws.get_value(z);

				auto dg = g.forwardAD();

				ws = dg.workspace();

				ws.set_dual(x, 1.0);
				ws.set_dual(y, 0.0);

				dg.run(ws);

				auto r_fwd = ws.get_value(z);

				auto drx_fwd = ws.get_dual(z);

				ws.set_dual(x, 0.0);
				ws.set_dual(y, 1.0);

				dg.run(ws);

				auto dry_fwd = ws.get_dual(z);

				dg = g.backwardAD();

				ws = dg.workspace();

				ws.set_adjoint(z, 1.0);

				dg.run(ws);

				auto r_bkwd = ws.get_value(z);

				auto drx_bkwd = ws.get_adjoint(x);
				auto dry_bkwd = ws.get_adjoint(y);

				for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
				{
					Assert::AreEqual(((typename qtype_traits<T>::type*) & r_fwd)[i], ((typename qtype_traits<T>::type*) & r_bkwd)[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & drx_fwd)[i], ((typename qtype_traits<T>::type*) & drx_bkwd)[i], eps);
					Assert::AreEqual(drx_s[i], ((typename qtype_traits<T>::type*) & drx_bkwd)[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & dry_fwd)[i], ((typename qtype_traits<T>::type*) & dry_bkwd)[i], eps);
					Assert::AreEqual(dry_s[i], ((typename qtype_traits<T>::type*) & dry_bkwd)[i], eps);
				}
			}

			template<class Op, class dOpdx, class dOpdy>
			static void run_ptr(Op op, dOpdx dopdx, dOpdy dopdy, const T& val, uint64_t n, const typename qtype_traits<T>::type& fact)
			{
				auto eps = epsilon<typename qtype_traits<T>::type>()*fact;

				qscalar<T> X = val, Y = val;
				Y *= (Y - (typename qtype_traits<T>::type)0.1);

				auto ptrX = alloc_array(n, X);
				auto ptrY = alloc_array(n, Y);

				qdouble x, y;
				qscalar<T> r_s;

				for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
				{
					x = X[i];
					y = Y[i];
					r_s[i] = (typename qtype_traits<T>::type)op(x, y)[0];
				}

				qscalar<T> drx_s = dopdx(X, Y);
				qscalar<T> dry_s = dopdy(X, Y);

				qrecorder<T*> rec;

				rec.start();

				rec.input(x);
				rec.input(y);

				auto z = op(x, y);

				rec.output(z);

				rec.stop();

				auto g = rec.graph();

				auto ws = g.workspace();

				g.allocate(ws,n);

				ws.set_value(x, ptrX.get());
				ws.set_value(y, ptrY.get());

				g.run(ws);

				auto res = ws.get_value(z);

				auto dg = g.forwardAD();

				auto dws_x = dg.workspace();

				dg.allocate(dws_x,n);

				dws_x.set_value(x, ptrX.get());
				dws_x.set_value(y, ptrY.get());

				std::shared_ptr<typename qtype_traits<T>::type[]> ptr(new typename qtype_traits<T>::type[n]);

				for (uint64_t i = 0; i < n; ++i)
					ptr.get()[i] = (typename qtype_traits<T>::type)((i+1.0)/n + 0.5);

				dws_x.set_dual(x, ptr.get());
				dws_x.set_dual(y, 0.0);

				dg.run(dws_x);

				auto r_x = dws_x.get_value(z);
				auto drdx_fwd = dws_x.get_dual(z);

				auto dws_y = dg.workspace();

				dg.allocate(dws_y,n);

				dws_y.set_value(x, ptrX.get());
				dws_y.set_value(y, ptrY.get());

				dws_y.set_dual(x, 0.0);
				dws_y.set_dual(y, ptr.get());

				dg.run(dws_y);

				auto r_y = dws_y.get_value(z);
				auto drdy_fwd = dws_y.get_dual(z);

				dg = g.backwardAD();

				auto dws_bkwd = dg.workspace();

				dg.allocate(dws_bkwd,n);

				dws_bkwd.set_value(x, ptrX.get());
				dws_bkwd.set_value(y, ptrY.get());

				dws_bkwd.set_adjoint(z, ptr.get());

				dg.run(dws_bkwd);

				auto r_bkwd = dws_bkwd.get_value(z);

				auto drdx_bkwd = dws_bkwd.get_adjoint(x);
				auto drdy_bkwd = dws_bkwd.get_adjoint(y);

				for (uint64_t i = 0; i < n; ++i)
				{
					uint64_t j = i % qtype_traits<T>::alignment();
					Assert::AreEqual(res[i], r_x[i], eps);
					Assert::AreEqual(res[i], r_y[i], eps);
					Assert::AreEqual(res[i], r_bkwd[i], eps);
					Assert::AreEqual(drx_s[j] * ptr.get()[i], drdx_bkwd[i], eps);
					Assert::AreEqual(dry_s[j] * ptr.get()[i], drdy_bkwd[i], eps);
					Assert::AreEqual(drx_s[j] * ptr.get()[i], drdx_fwd[i], eps);
					Assert::AreEqual(dry_s[j] * ptr.get()[i], drdy_fwd[i], eps);

				}
			}

			template<class Op, class dOpdx>
			static void run_scalar(Op op, dOpdx dopdx, const T& val, const typename qtype_traits<T>::type& fact)
			{
				auto eps = epsilon<typename qtype_traits<T>::type>()*fact;

				qscalar<T> x = val, y = val;
				y *= (y - (typename qtype_traits<T>::type)0.1);

				qscalar<T> r_s = op(x, y.get_x());
				qscalar<T> drx_s = dopdx(x, y.get_x());

				qrecorder<T> rec;

				rec.start();

				rec.input(x);

				qscalar<T> z = op(x, y.get_x());

				rec.output(z);

				rec.stop();

				auto g = rec.graph();

				auto ws = g.workspace();

				g.run(ws);

				auto r = ws.get_value(z);

				auto dg = g.forwardAD();

				ws = dg.workspace();
				ws.set_dual(x, 1.0);

				dg.run(ws);

				auto r_fwd = ws.get_value(z);
				auto dr_fwd = ws.get_dual(z);

				dg = g.backwardAD();
				ws = dg.workspace();
				ws.set_adjoint(z, 1.0);

				dg.run(ws);

				auto r_bkwd = ws.get_value(z);
				auto dr_bkwd = ws.get_adjoint(x);

				for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
				{
					Assert::AreEqual(((typename qtype_traits<T>::type*) & r)[i], r_s[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & r)[i], ((typename qtype_traits<T>::type*) & r_fwd)[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & r)[i], ((typename qtype_traits<T>::type*) & r_bkwd)[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & dr_fwd)[i], drx_s[i], eps);
					Assert::AreEqual(((typename qtype_traits<T>::type*) & dr_fwd)[i], ((typename qtype_traits<T>::type*) & dr_bkwd)[i], eps);
				}

			}

			template<class Op, class dOpdx>
			static void run_scalar_ptr(Op op, dOpdx dopdx, const T& val, uint64_t n, const typename qtype_traits<T>::type& fact)
			{
				auto eps = epsilon<typename qtype_traits<T>::type>() * fact;

				qscalar<T> X = val, Y = val;
				Y *= (Y - (typename qtype_traits<T>::type)0.1);

				auto ptrX = alloc_array(n, X);

				qdouble x, y;
				qscalar<T> r_s;

				for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
				{
					x = X[i];
					y = Y[0]; // For T* recorder, scalar has only 1 element
					r_s[i] = (typename qtype_traits<T>::type)op(x, y.get_x())[0];
				}

				qscalar<T> dr_s = dopdx(X, (typename qtype_traits<T>::type)Y[0]);

				qrecorder<T*> rec;

				rec.start();

				rec.input(x);

				qdouble z = op(x, y.get_x());

				rec.output(z);

				rec.stop();

				auto g = rec.graph();
				auto ws = g.workspace();
				g.allocate(ws,n);

				ws.set_value(x, ptrX.get());

				g.run(ws);

				auto r = ws.get_value(z);

				auto dg = g.forwardAD();

				auto wsf = dg.workspace();
				dg.allocate(wsf,n);

				wsf.set_value(x, ptrX.get());
				wsf.set_dual(x, 1.0);

				dg.run(wsf);

				auto r_fwd = wsf.get_value(z);
				auto dr_fwd = wsf.get_dual(z);

				auto dg_bkwd = g.backwardAD();
				auto wsb = dg_bkwd.workspace();
				dg_bkwd.allocate(wsb,n);

				wsb.set_value(x, ptrX.get());
				wsb.set_adjoint(z, 1.0);
				dg_bkwd.run(wsb);

				auto r_bkwd = wsb.get_value(z);
				auto dr_bkwd = wsb.get_adjoint(x);

				for (uint64_t i = 0; i < n; ++i)
				{
					uint64_t j = i % qtype_traits<T>::alignment();
					Assert::AreEqual(r[i], r_fwd[i], eps);
					Assert::AreEqual(r[i], r_bkwd[i], eps);
					Assert::AreEqual(r_s[j], r[i], eps);
					Assert::AreEqual(dr_fwd[i], dr_bkwd[i], eps);
					Assert::AreEqual(dr_s[j], dr_fwd[i], eps);
				}


			}
		};

#define CHECK_ARITHMETIC(OP,DOPDX,DOPDY,VAL) \
		if (cpu_info::has_avx512()) \
		{ \
			Function2<__m512d>::run([](const qscalar<__m512d>& x, const qscalar<__m512d>& y) { return OP; }, [](const qscalar<__m512d>& x, const qscalar<__m512d>& y) { return DOPDX; }, [](const qscalar<__m512d>& x, const qscalar<__m512d>& y) { return DOPDY; },VAL<__m512d>()); \
			Function2<__m512>::run([](const qscalar<__m512>& x, const qscalar<__m512>& y) { return OP; }, [](const qscalar<__m512>& x, const qscalar<__m512>& y) { return DOPDX; }, [](const qscalar<__m512>& x, const qscalar<__m512>& y) { return DOPDY; },VAL<__m512>()); \
		} \
		Function2<__m256d>::run([](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return OP; }, [](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return DOPDX; }, [](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return DOPDY; },VAL<__m256d>()); \
		Function2<__m256>::run([](const qscalar<__m256>& x, const qscalar<__m256>& y) { return OP; }, [](const qscalar<__m256>& x, const qscalar<__m256>& y) { return DOPDX; }, [](const qscalar<__m256>& x, const qscalar<__m256>& y) { return DOPDY; },VAL<__m256>()); \
		Function2<__m128d>::run([](const qscalar<__m128d>& x, const qscalar<__m128d>& y) { return OP; }, [](const qscalar<__m128d>& x, const qscalar<__m128d>& y) { return DOPDX; }, [](const qscalar<__m128d>& x, const qscalar<__m128d>& y) { return DOPDY; },VAL<__m128d>()); \
		Function2<__m128>::run([](const qscalar<__m128>& x, const qscalar<__m128>& y) { return OP; }, [](const qscalar<__m128>& x, const qscalar<__m128>& y) { return DOPDX; }, [](const qscalar<__m128>& x, const qscalar<__m128>& y) { return DOPDY; },VAL<__m128>()); 

		TEST_METHOD(MathArithmetic)
		{
			gpu_info::num_nvidia();
			gpu_info::num_amd();

			CHECK_ARITHMETIC(x * y, y, x, xvalue);
			CHECK_ARITHMETIC(x / y, 1.0/y, -x/(y*y),xvalue);
			CHECK_ARITHMETIC(x + y, x+1.0-x, x+1.0-x,xvalue);
			CHECK_ARITHMETIC(x - y, x + 1.0 - x, x - 1.0 - x,xvalue);
			CHECK_ARITHMETIC(std::pow(x,y), std::pow(x, y - 1.0) * y, std::pow(x,y)*std::log(x),log_xvalue);
			CHECK_ARITHMETIC(std::max(x, y), heaviside(x-y), heaviside(y-x), xvalue);
			CHECK_ARITHMETIC(std::min(x, y), heaviside(y-x), heaviside(x-y), xvalue);

		}

#define CHECK_ARITHMETIC_PTR(OP,DOPDX,DOPDY,VAL,n, fact) \
		if (cpu_info::has_avx512()) \
		{ \
			Function2<__m512d>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m512d>& x, const qscalar<__m512d>& y) { return DOPDX; }, [](const qscalar<__m512d>& x, const qscalar<__m512d>& y) { return DOPDY; },VAL<__m512d>(),n, fact); \
			Function2<__m512>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m512>& x, const qscalar<__m512>& y) { return DOPDX; }, [](const qscalar<__m512>& x, const qscalar<__m512>& y) { return DOPDY; },VAL<__m512>(),n, fact); \
		} \
		Function2<__m256d>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return DOPDX; }, [](const qscalar<__m256d>& x, const qscalar<__m256d>& y) { return DOPDY; },VAL<__m256d>(),n, fact); \
		Function2<__m256>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m256>& x, const qscalar<__m256>& y) { return DOPDX; }, [](const qscalar<__m256>& x, const qscalar<__m256>& y) { return DOPDY; },VAL<__m256>(),n, fact); \
		Function2<__m128d>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m128d>& x, const qscalar<__m128d>& y) { return DOPDX; }, [](const qscalar<__m128d>& x, const qscalar<__m128d>& y) { return DOPDY; },VAL<__m128d>(),n, fact); \
		Function2<__m128>::run_ptr([](const qdouble& x, const qdouble& y) { return OP; }, [](const qscalar<__m128>& x, const qscalar<__m128>& y) { return DOPDX; }, [](const qscalar<__m128>& x, const qscalar<__m128>& y) { return DOPDY; },VAL<__m128>(),n, fact); 

		TEST_METHOD(MathArithmeticPtr)
		{
			CHECK_ARITHMETIC_PTR(x * y, y, x, xvalue,100, 1.0);
			CHECK_ARITHMETIC_PTR(x / y, 1.0 / y, -x / (y * y), xvalue, 100, 20.0);
			CHECK_ARITHMETIC_PTR(x + y, x + 1.0 - x, x + 1.0 - x, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_PTR(x - y, x + 1.0 - x, x - 1.0 - x, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_PTR(std::pow(x, y), std::pow(x, y - 1.0) * y, std::pow(x, y) * std::log(x), pow_xvalue, 100, 1.0);
			CHECK_ARITHMETIC_PTR(std::max(x, y), heaviside(x - y), heaviside(y - x), xvalue, 100, 1.0);
			CHECK_ARITHMETIC_PTR(std::min(x, y), heaviside(y - x), heaviside(x - y), xvalue, 100, 1.0);
		}

#define CHECK_ARITHMETIC_SCALAR(OP,DOPDX,VAL,fact) \
		if (cpu_info::has_avx512()) \
		{ \
			Function2<__m512d>::run_scalar([](const qscalar<__m512d>& x, const __m512d& y) { return OP; }, [](const qscalar<__m512d>& x, const __m512d& y) { return DOPDX; },VAL<__m512d>(),fact); \
			Function2<__m512>::run_scalar([](const qscalar<__m512>& x, const __m512& y) { return OP; }, [](const qscalar<__m512>& x, const __m512& y) { return DOPDX; },VAL<__m512>(),fact); \
		} \
		Function2<__m256d>::run_scalar([](const qscalar<__m256d>& x, const __m256d& y) { return OP; }, [](const qscalar<__m256d>& x, const __m256d& y) { return DOPDX; },VAL<__m256d>(),fact); \
		Function2<__m256>::run_scalar([](const qscalar<__m256>& x, const __m256& y) { return OP; }, [](const qscalar<__m256>& x, const __m256& y) { return DOPDX; },VAL<__m256>(),fact); \
		Function2<__m128d>::run_scalar([](const qscalar<__m128d>& x, const __m128d& y) { return OP; }, [](const qscalar<__m128d>& x, const __m128d& y) { return DOPDX; },VAL<__m128d>(),fact); \
		Function2<__m128>::run_scalar([](const qscalar<__m128>& x, const __m128& y) { return OP; }, [](const qscalar<__m128>& x, const __m128& y) { return DOPDX; },VAL<__m128>(),fact); 

		TEST_METHOD(MathArithmeticScalar)
		{
			gpu_info::num_nvidia();
			gpu_info::num_amd();

			CHECK_ARITHMETIC_SCALAR(x * y, y, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(y * x, y, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(x / y, x /x / y, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(y / x, y / (-x * x), xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(x + y, x + 1.0 - x, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(y + x, x + 1.0 - x, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(x - y, x + 1.0 - x, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(y - x, x - 1.0 - x, xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(std::pow(x, y), std::pow(x, y) * y/x, pow_xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(std::pow(y, x), std::pow(y, x) * std::log(x+y-x), pow_xvalue, 2.0);
			CHECK_ARITHMETIC_SCALAR(std::max(x, y), heaviside(x - y), xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(std::max(y, x), heaviside(x - y), xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(std::min(x, y), heaviside(y - x), xvalue, 1.0);
			CHECK_ARITHMETIC_SCALAR(std::min(y, x), heaviside(y - x), xvalue, 1.0);

		}

#define CHECK_ARITHMETIC_SCALAR_PTR(OP,DOPDX,VAL,n,fact) \
		if (cpu_info::has_avx512()) \
		{ \
			Function2<__m512d>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m512d>& x, const double& y) { return DOPDX; },VAL<__m512d>(),n,fact); \
			Function2<__m512>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m512>& x, const float& y) { return DOPDX; },VAL<__m512>(),n,fact); \
		} \
		Function2<__m256d>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m256d>& x, const double& y) { return DOPDX; },VAL<__m256d>(),n,fact); \
		Function2<__m256>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m256>& x, const float& y) { return DOPDX; },VAL<__m256>(),n,fact); \
		Function2<__m128d>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m128d>& x, const double& y) { return DOPDX; },VAL<__m128d>(),n,fact); \
		Function2<__m128>::run_scalar_ptr([](const qdouble& x, const double& y) { return OP; }, [](const qscalar<__m128>& x, const float& y) { return DOPDX; },VAL<__m128>(),n,fact); 

		TEST_METHOD(MathArithmeticScalarPtr)
		{
			gpu_info::num_nvidia();
			gpu_info::num_amd();


			CHECK_ARITHMETIC_SCALAR_PTR(x + y, x-x+1.0, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(y + x, x - x + 1.0, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(x - y, x - x + 1.0, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(y - x, x - x - 1.0, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(x * y, y + x-x, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(y * x, y + x -x, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(x / y, x/x/y, xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(y / x, y/(-x*x), xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::pow(x, y), std::pow(x, y) * y / x, pow_xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::pow(y, x), std::pow(y, x) * std::log(x + y - x), pow_xvalue, 100, 2.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::max(x, y), heaviside(x - y), xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::max(y, x), heaviside(x - y), xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::min(x, y), heaviside(y - x), xvalue, 100, 1.0);
			CHECK_ARITHMETIC_SCALAR_PTR(std::min(y, x), heaviside(y - x), xvalue, 100, 1.0);

		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(Arithmetic::Arithmetic);


