#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctionsForward2
{
	TEST_CLASS(BasicFunctionsForward2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsForward2);
		CPPUNIT_TEST(MathFunc1Forward);
		CPPUNIT_TEST_SUITE_END();


		TEST_METHOD(MathFunc1Forward)
		{
			CHECK_FORWARD(std::sin, std::cos);
			CHECK_FORWARD(std::cos, -std::sin);
			CHECK_FORWARD(std::tan, dtan);
			CHECK_FORWARD_TRIG(std::asin, dasin);
 			CHECK_FORWARD_TRIG(std::acos, dacos);
			CHECK_FORWARD_TRIG(std::atan, datan);

		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsForward2::BasicFunctionsForward2);


