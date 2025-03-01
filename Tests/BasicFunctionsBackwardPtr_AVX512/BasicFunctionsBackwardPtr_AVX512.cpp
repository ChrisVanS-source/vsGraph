#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsBackwardPtr_AVX512
{
	TEST_CLASS(BasicFunctionsBackwardPtr_AVX512)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsBackwardPtr_AVX512);
		CPPUNIT_TEST(MathFunc1Backward_Ptr);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Backward_Ptr)
		{
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::exp, std::exp, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::sinh, std::cosh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::cosh, std::sinh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::tanh, dtanh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::erfc, derfc, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(-, dchs, xvalue, 100);

			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::log, dlog, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::log2, dlog2, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::log10, dlog10, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::sqrt, dsqrt, log_xvalue, 100);

			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::sin, std::cos, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::cos, -std::sin, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::tan, dtan, xvalue, 100);

			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::asin, dasin, trig_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::acos, dacos, trig_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR_AVX512(std::atan, datan, trig_xvalue, 100);



		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsBackwardPtr_AVX512::BasicFunctionsBackwardPtr_AVX512);


