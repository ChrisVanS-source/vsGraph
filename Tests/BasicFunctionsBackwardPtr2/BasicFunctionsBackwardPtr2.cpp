#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsBackwardPtr2
{
	TEST_CLASS(BasicFunctionsBackwardPtr2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsBackwardPtr2);
		CPPUNIT_TEST(MathFunc1Backward_Ptr);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Backward_Ptr)
		{
			CHECK_BACKWARD_XVALUE_PTR(std::sin, std::cos, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::cos, -std::sin, xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::tan, dtan, xvalue, 100);

			CHECK_BACKWARD_XVALUE_PTR(std::asin, dasin, trig_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::acos, dacos, trig_xvalue, 100);
			CHECK_BACKWARD_XVALUE_PTR(std::atan, datan, trig_xvalue, 100);
		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsBackwardPtr2::BasicFunctionsBackwardPtr2);


