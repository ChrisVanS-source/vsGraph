#include "UnitTestDefines.h"
#include "qdefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctionsBackward2
{
	TEST_CLASS(BasicFunctionsBackward2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsBackward2);
		CPPUNIT_TEST(MathFunc1Backward);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Backward)
		{
			CHECK_BACKWARD(std::sin, std::cos);
			CHECK_BACKWARD(std::tan, dtan);
			CHECK_BACKWARD(std::cos, -std::sin);
			CHECK_BACKWARD_TRIG(std::asin, dasin);
			CHECK_BACKWARD_TRIG(std::acos, dacos);
			CHECK_BACKWARD_TRIG(std::atan, datan);
		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsBackward2::BasicFunctionsBackward2);


