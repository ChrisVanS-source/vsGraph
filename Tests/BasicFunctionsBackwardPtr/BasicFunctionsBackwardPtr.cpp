#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsBackwardPtr
{
	TEST_CLASS(BasicFunctionsBackwardPtr)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsBackwardPtr);
		CPPUNIT_TEST(MathFunc1Backward_Ptr);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Backward_Ptr)
		{
			CHECK_BACKWARD_XVALUE_PTR(std::exp, std::exp, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::sinh, std::cosh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::cosh, std::sinh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::tanh, dtanh, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::erfc, derfc, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(-, dchs, xvalue, 100);

			CHECK_BACKWARD_XVALUE_PTR(std::log, dlog, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::log2, dlog2, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::log10, dlog10, log_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::sqrt, dsqrt, log_xvalue, 100);
		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsBackwardPtr::BasicFunctionsBackwardPtr);


