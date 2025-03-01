#include "UnitTestDefines.h"
#include "qdefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"

template<class T>
struct bool_init {

	static std::initializer_list<bool> list() { return { true }; }

};

template<>
struct bool_init<__m512d> {

	static std::initializer_list<bool> list() { return { true, false, true, false, true, false, true, false }; }

};

template<>
struct bool_init<__m512> {

	static std::initializer_list<bool> list() { return { true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false }; }

};

template<>
struct bool_init<__m256d> {

	static std::initializer_list<bool> list() { return { true, false, true, false }; }

};

template<>
struct bool_init<__m256> {

	static std::initializer_list<bool> list() { return { true, false, true, false, true, false, true, false }; }

};

template<>
struct bool_init<__m128d> {

	static std::initializer_list<bool> list() { return { true, false }; }

};

template<>
struct bool_init<__m128> {

	static std::initializer_list<bool> list() { return { true, false, true, false }; }

};

template<class T>
struct integer_init {

	static std::initializer_list<int64_t> list() { return { 1 }; }

};

template<>
struct integer_init<__m512d> {

	static std::initializer_list<int64_t> list() { return { 1, 0, 1, 0, 1, 0, 1, 0 }; }

};

template<>
struct integer_init<__m512> {

	static std::initializer_list<int64_t> list() { return { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }; }

};

template<>
struct integer_init<__m256d> {

	static std::initializer_list<int64_t> list() { return { 1, 0, 1, 0 }; }

};

template<>
struct integer_init<__m256> {

	static std::initializer_list<int64_t> list() { return { 1, 0, 1, 0, 1, 0, 1, 0 }; }

};

template<>
struct integer_init<__m128d> {

	static std::initializer_list<int64_t> list() { return { 1, 0 }; }

};

template<>
struct integer_init<__m128> {

	static std::initializer_list<int64_t> list() { return { 1, 0, 1, 0 }; }

};




namespace Logical
{
	TEST_CLASS(Logical)
	{
	public:

		CPPUNIT_TEST_SUITE(Logical);
		CPPUNIT_TEST(MathLogical);
		CPPUNIT_TEST(MathLogical2);
		CPPUNIT_TEST(MathLogicalPtr);
		CPPUNIT_TEST(MathLogical2Ptr);
		CPPUNIT_TEST_SUITE_END();

		template<class T>
		void MathLogical_Template()
		{
			qboolean<T> b(bool_init<T>::list());

			qrecorder<T> rec;

			qscalar<T> x = xvalue<T>();

			rec.start();

			rec.input(x);

			qscalar<T> y = qif(b && x > 1.0, x * x, x);

			rec.output(y);

			rec.stop();

			auto g = rec.graph();

			auto ws = g.workspace();

			g.run(ws);

			auto res = ws.get_value(y);

			auto eps = epsilon<typename qtype_traits<T>::type>();

			auto dg_fwd = g.forwardAD();

			auto ws_fwd = dg_fwd.workspace();

			ws_fwd.set_dual(x, 1.0);

			dg_fwd.run(ws_fwd);

			auto r_fwd = ws_fwd.get_value(y);
			auto dr_fwd = ws_fwd.get_dual(y);

			auto dg_bkwd = g.backwardAD();

			auto ws_bkwd = dg_bkwd.workspace();

			ws_bkwd.set_adjoint(y, 1.0);

			dg_bkwd.run(ws_bkwd);

			auto r_bkwd = ws_bkwd.get_value(y);
			auto dr_bkwd = ws_bkwd.get_adjoint(x);

			for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			{
				Assert::AreEqual(((typename qtype_traits<T>::type*) & res)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & r_fwd)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & r_bkwd)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & dr_fwd)[i], ((typename qtype_traits<T>::type*) & dr_bkwd)[i], eps);
			}

		}

		TEST_METHOD(MathLogical)
		{
			if (cpu_info::has_avx512())
			{
				MathLogical_Template<__m512d>();
				MathLogical_Template<__m512>();
			}
			MathLogical_Template<__m256d>();
			MathLogical_Template<__m256>();
			MathLogical_Template<__m128d>();
			MathLogical_Template<__m128>();
		}

		template<class T>
		void MathLogical2_Template()
		{
			qinteger<T> b(integer_init<T>::list());

			qrecorder<T> rec;

			qscalar<T> x = xvalue<T>();

			rec.start();

			rec.input(x);

			qscalar<T> y = qif(b == 1 && x > 1.0, x * x, x);

			rec.output(y);

			rec.stop();

			auto g = rec.graph();

			auto ws = g.workspace();

			g.run(ws);

			auto res = ws.get_value(y);

			auto eps = epsilon<typename qtype_traits<T>::type>();

			auto dg_fwd = g.forwardAD();

			auto ws_fwd = dg_fwd.workspace();

			ws_fwd.set_dual(x, 1.0);

			dg_fwd.run(ws_fwd);

			auto r_fwd = ws_fwd.get_value(y);
			auto dr_fwd = ws_fwd.get_dual(y);

			auto dg_bkwd = g.backwardAD();

			auto ws_bkwd = dg_bkwd.workspace();

			ws_bkwd.set_adjoint(y, 1.0);

			dg_bkwd.run(ws_bkwd);

			auto r_bkwd = ws_bkwd.get_value(y);
			auto dr_bkwd = ws_bkwd.get_adjoint(x);

			for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			{
				Assert::AreEqual(((typename qtype_traits<T>::type*) & res)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & r_fwd)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & r_bkwd)[i], y[i], eps);
				Assert::AreEqual(((typename qtype_traits<T>::type*) & dr_fwd)[i], ((typename qtype_traits<T>::type*) & dr_bkwd)[i], eps);
			}
		}

		TEST_METHOD(MathLogical2)
		{
			if (cpu_info::has_avx512())
			{
				MathLogical2_Template<__m512d>();
				MathLogical2_Template<__m512>();
			}
			MathLogical2_Template<__m256d>();
			MathLogical2_Template<__m256>();
			MathLogical2_Template<__m128d>();
			MathLogical2_Template<__m128>();
		}

		template<class T>
		static void MathLogicalPtr_Template(QDevice device = CPU)
		{
			qbool b(true);

			qrecorder<T*> rec;

			qdouble x = xvalue<double>();

			rec.start();

			rec.input(x);

			qdouble y = qif(b && x > 1.0, x * x, x);

			rec.output(y);

			rec.stop();

			auto g = rec.graph();

			auto ws = g.workspace(device);

			uint64_t n = 100;

			g.allocate(ws,n);

			g.run(ws);

			auto res = ws.get_value(y);

			auto eps = epsilon<typename qtype_traits<T>::type>();

			auto dg_fwd = g.forwardAD();

			auto ws_fwd = dg_fwd.workspace(device);
			dg_fwd.allocate(ws_fwd,n);

			ws_fwd.set_dual(x, 1.0);
			dg_fwd.run(ws_fwd);

			auto r_fwd = ws_fwd.get_value(y);
			auto dr_fwd = ws_fwd.get_dual(y);

			auto dg_bkwd = g.backwardAD();

			auto ws_bkwd = dg_bkwd.workspace(device);
			dg_bkwd.allocate(ws_bkwd,n);

			ws_bkwd.set_adjoint(y, 1.0);

			dg_bkwd.run(ws_bkwd);

			auto r_bkwd = ws_bkwd.get_value(y);
			auto dr_bkwd = ws_bkwd.get_adjoint(x);

			for (uint64_t i = 0; i < n; ++i)
			{
				Assert::AreEqual((double)res[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)r_fwd[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)r_bkwd[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)dr_fwd[i], (double)dr_bkwd[i], (double)eps);
			}


		}

		TEST_METHOD(MathLogicalPtr)
		{
			if (cpu_info::has_avx512())
			{
				MathLogicalPtr_Template<__m512d>();
				MathLogicalPtr_Template<__m512>();
			}
			MathLogicalPtr_Template<__m256d>();
			MathLogicalPtr_Template<__m256>();
			MathLogicalPtr_Template<__m128d>();
			MathLogicalPtr_Template<__m128>();

			if (gpu_info::num_fpoc_amd() > 0)
			{
				MathLogicalPtr_Template<__m256d>(AMD);
			}

			if (gpu_info::num_fpoc_nvidia() > 0)
			{
				MathLogicalPtr_Template<__m256d>(NVIDIA);
			}
		}

		template<class T>
		static void MathLogical2Ptr_Template()
		{
			qint b(1);

			qrecorder<T*> rec;

			qdouble x = xvalue<double>();

			rec.start();

			rec.input(x);

			qdouble y = qif(b == 1 && x > 1.0, x * x, x);

			rec.output(y);

			rec.stop();

			auto g = rec.graph();

			uint64_t n = 100;

			auto ws = g.workspace();
			g.allocate(ws,n);

			g.run(ws);

			auto res = ws.get_value(y);

			auto eps = epsilon<typename qtype_traits<T>::type>();

			auto dg_fwd = g.forwardAD();

			auto ws_fwd = dg_fwd.workspace();
			dg_fwd.allocate(ws_fwd, n);

			ws_fwd.set_dual(x, 1.0);
			dg_fwd.run(ws_fwd);

			auto r_fwd = ws_fwd.get_value(y);
			auto dr_fwd = ws_fwd.get_dual(y);

			auto dg_bkwd = g.backwardAD();

			auto ws_bkwd = dg_bkwd.workspace();
			dg_bkwd.allocate(ws_bkwd,n);

			ws_bkwd.set_adjoint(y, 1.0);

			dg_bkwd.run(ws_bkwd);

			auto r_bkwd = ws_bkwd.get_value(y);
			auto dr_bkwd = ws_bkwd.get_adjoint(x);

			for (uint64_t i = 0; i < n; ++i)
			{
				Assert::AreEqual((double)res[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)r_fwd[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)r_bkwd[i], (double)y[0], (double)eps);
				Assert::AreEqual((double)dr_fwd[i], (double)dr_bkwd[i], (double)eps);
			}

		}

		TEST_METHOD(MathLogical2Ptr)
		{
			if (cpu_info::has_avx512())
			{
				MathLogical2Ptr_Template<__m512d>();
				MathLogical2Ptr_Template<__m512>();
			}
			MathLogical2Ptr_Template<__m256d>();
			MathLogical2Ptr_Template<__m256>();
			MathLogical2Ptr_Template<__m128d>();
			MathLogical2Ptr_Template<__m128>();
		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(Logical::Logical);


