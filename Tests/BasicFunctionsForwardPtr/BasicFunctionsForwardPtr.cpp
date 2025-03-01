#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsForwardPtr
{
	TEST_CLASS(BasicFunctionsForwardPtr)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsForwardPtr);
		CPPUNIT_TEST(MathFunc1Forward_Ptr);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Forward_Ptr)
		{
			CHECK_FORWARD_XVALUE_PTR(std::exp, std::exp, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::sinh, std::cosh, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::cosh, std::sinh, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::tanh, dtanh, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::erfc, derfc, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(-, dchs, xvalue, 100);

			CHECK_FORWARD_XVALUE_PTR(std::log, dlog, log_xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::log2, dlog2, log_xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::log10, dlog10, log_xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::sqrt, dsqrt, log_xvalue, 100);
		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsForwardPtr::BasicFunctionsForwardPtr);


