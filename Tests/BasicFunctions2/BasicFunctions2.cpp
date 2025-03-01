#include "UnitTestDefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctions2
{
	TEST_CLASS(BasicFunctions2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctions2);
		CPPUNIT_TEST(MathFunc1);
		CPPUNIT_TEST(MathFunc1Dual);
		CPPUNIT_TEST_SUITE_END();


		template<class T>
		void MathFunc1_template()
		{
			auto eps = epsilon<typename qtype_traits<T>::type>();

			qscalar<T> x = xvalue<T>();

			MATHFUNC1_CHECK_RESULTS(std::normal_cdf);

			x = log_xvalue<T>();

			MATHFUNC1_CHECK_RESULTS(std::log);
			MATHFUNC1_CHECK_RESULTS(std::log2);
			MATHFUNC1_CHECK_RESULTS(std::log10);
			MATHFUNC1_CHECK_RESULTS(std::sqrt);

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
			MATHFUNC1_CHECK_RESULTS_DUAL(-, [](const typename qtype_traits<T>::type& x) { return -1.0; });
			MATHFUNC1_CHECK_RESULTS_DUAL(inverse, [](const typename qtype_traits<T>::type& x) { return -1.0 / (x * x); });

			x = log_xvalue<T>();
			xd = qdual<qscalar<T>>(x, one<T>());

			MATHFUNC1_CHECK_RESULTS_DUAL(std::log, [](const typename qtype_traits<T>::type& x) { return 1.0 / x; });
			MATHFUNC1_CHECK_RESULTS_DUAL(std::log2, [](const typename qtype_traits<T>::type& x) { return 1.0 / (x * 0.69314718055994529); });
			MATHFUNC1_CHECK_RESULTS_DUAL(std::log10, [](const typename qtype_traits<T>::type& x) { return 1.0 / (x * 2.3025850929940459); });

		}

		TEST_METHOD(MathFunc1Dual)
		{
		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctions2::BasicFunctions2);


