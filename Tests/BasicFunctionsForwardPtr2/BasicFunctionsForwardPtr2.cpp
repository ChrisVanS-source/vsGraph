#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsForwardPtr2
{
	TEST_CLASS(BasicFunctionsForwardPtr2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsForwardPtr2);
		CPPUNIT_TEST(MathFunc1Forward_Ptr);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Forward_Ptr)
		{
			CHECK_FORWARD_XVALUE_PTR(std::sin, std::cos, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::cos, -std::sin, xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::tan, dtan, xvalue, 100);

			CHECK_FORWARD_XVALUE_PTR(std::asin, dasin, trig_xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::acos, dacos, trig_xvalue, 100);
			CHECK_FORWARD_XVALUE_PTR(std::atan, datan, trig_xvalue, 100);
		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsForwardPtr2::BasicFunctionsForwardPtr2);


