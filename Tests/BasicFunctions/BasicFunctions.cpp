#include "UnitTestDefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctions
{
	TEST_CLASS(BasicFunctions)
	{
	public:
		
		CPPUNIT_TEST_SUITE(BasicFunctions);
		CPPUNIT_TEST(MathFunc1);
		CPPUNIT_TEST(MathFunc1Dual);
		CPPUNIT_TEST_SUITE_END();

		template<class T, class Op >
		void check_results(const qscalar<T>& x, const qscalar<T>& y, const typename qtype_traits<T>::type& eps, Op op)
		{
			for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
				Assert::AreEqual((double)y[i], (double)op(x[i]), (double)eps);
		}

#define MATHFUNC1_CHECK_RESULTS(A) check_results(x, A(x), eps, [](const typename qtype_traits<T>::type& x) { return A(x); })
#define MATHFUNC1_CHECK_RESULTS2(A,B) check_results(x, A(x), eps, [](const typename qtype_traits<T>::type& x) { return B(x); })

		template<class T>
		void MathFunc1_template()
		{
			auto eps = epsilon<typename qtype_traits<T>::type>();

			qscalar<T> x = xvalue<T>();

			MATHFUNC1_CHECK_RESULTS(std::sin);
			MATHFUNC1_CHECK_RESULTS(std::cos);
			MATHFUNC1_CHECK_RESULTS(std::tan);
			MATHFUNC1_CHECK_RESULTS(std::exp);
			MATHFUNC1_CHECK_RESULTS(std::sinh);
			MATHFUNC1_CHECK_RESULTS(std::cosh);
			MATHFUNC1_CHECK_RESULTS(std::tanh);
			MATHFUNC1_CHECK_RESULTS(std::erfc);
#if !defined(__linux__) 
			MATHFUNC1_CHECK_RESULTS2(std::ceil,ceil);    // Linux std::ceil crashes for single precision, ceil does not. Release crashes for both (maybe AVX512 related)
			MATHFUNC1_CHECK_RESULTS2(std::floor,floor);  // Linux std::floor crashes for single precision, floor does not. Release crashes for both (maybe AVX512 related)
#endif
			MATHFUNC1_CHECK_RESULTS(-);

			x = trig_xvalue<T>();

			MATHFUNC1_CHECK_RESULTS(std::asin);
			MATHFUNC1_CHECK_RESULTS(std::acos);
			MATHFUNC1_CHECK_RESULTS(std::atan);
		}

		TEST_METHOD(MathFunc1)
		{
			gpu_info::num_nvidia();

			if (cpu_info::has_avx512())
			{
				MathFunc1_template<__m512d>();
				MathFunc1_template<__m512>();
			}
			MathFunc1_template<__m256d>();
			MathFunc1_template<__m256>();
			MathFunc1_template<__m128d>();
			MathFunc1_template<__m128>();		
			MathFunc1_template<double>();
			MathFunc1_template<float>();
		}

		template<class T>
		static T inverse(const T& x) { return graph_traits<T>::cast(1.0)/x; }

		template<class T>
		static qdual<T> inverse(const qdual<T>& x) { T one(1.0); return one / x; }


#define MATHFUNC1_CHECK_RESULTS_DUAL(A,B) \
		check_results(xd.x(), A(xd).x(), eps, [](const typename qtype_traits<T>::type& v) { return A(v); }); \
		check_results(xd.x(), A(xd).dx(), eps, [](const typename qtype_traits<T>::type& v) { return B(v); }) 

		template<class T> 
		void MathFunc1Dual_Template()
		{
			auto eps = epsilon<typename qtype_traits<T>::type>();

			qscalar<T> x = xvalue<T>();
			qdual<qscalar<T>> xd(x, one<T>());

			MATHFUNC1_CHECK_RESULTS_DUAL(std::exp, std::exp);
			MATHFUNC1_CHECK_RESULTS_DUAL(std::sin, std::cos);
			MATHFUNC1_CHECK_RESULTS_DUAL(std::cos, -std::sin);
			MATHFUNC1_CHECK_RESULTS_DUAL(std::sinh, std::cosh);
			MATHFUNC1_CHECK_RESULTS_DUAL(std::cosh, std::sinh);
			MATHFUNC1_CHECK_RESULTS_DUAL(std::erfc, [](const typename qtype_traits<T>::type& x) { return -1.12837916709551257390 * std::exp(-x * x); });
			MATHFUNC1_CHECK_RESULTS_DUAL(std::tan, [](const typename qtype_traits<T>::type& x) { return 1.0 / (std::cos(x) * std::cos(x)); });
			MATHFUNC1_CHECK_RESULTS_DUAL(-,[](const typename qtype_traits<T>::type& x) { return -1.0; });
			MATHFUNC1_CHECK_RESULTS_DUAL(inverse, [](const typename qtype_traits<T>::type& x) { return -1.0/(x*x); });

			x = log_xvalue<T>();
			xd = qdual<qscalar<T>>(x,one<T>());

			MATHFUNC1_CHECK_RESULTS_DUAL(std::log, [](const typename qtype_traits<T>::type& x) { return 1.0 / x; });
			MATHFUNC1_CHECK_RESULTS_DUAL(std::log2, [](const typename qtype_traits<T>::type& x) { return 1.0 / (x * 0.69314718055994529); });
			MATHFUNC1_CHECK_RESULTS_DUAL(std::log10, [](const typename qtype_traits<T>::type& x) { return 1.0 / (x * 2.3025850929940459); });

		}

		TEST_METHOD(MathFunc1Dual)
		{
			if (cpu_info::has_avx512())
			{
				MathFunc1Dual_Template<__m512d>();
				MathFunc1Dual_Template<__m512>();
			}
			MathFunc1Dual_Template<__m256d>();
			MathFunc1Dual_Template<__m256>();
			MathFunc1Dual_Template<__m128d>();
			MathFunc1Dual_Template<__m128>();
			MathFunc1Dual_Template<double>();
			MathFunc1Dual_Template<float>();
		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctions::BasicFunctions);


