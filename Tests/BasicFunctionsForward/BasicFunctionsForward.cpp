#include "UnitTestDefines.h"
#include "qdefines.h"


#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"


namespace BasicFunctionsForward
{
	TEST_CLASS(BasicFunctionsForward)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsForward);
		CPPUNIT_TEST(MathFunc1Forward);
		CPPUNIT_TEST_SUITE_END();


		TEST_METHOD(MathFunc1Forward)
		{
			CHECK_FORWARD(std::exp, std::exp);
			CHECK_FORWARD(std::sinh, std::cosh);
			CHECK_FORWARD(std::cosh, std::sinh);
			CHECK_FORWARD(std::tanh, dtanh);
			CHECK_FORWARD(std::erfc, derfc);
			CHECK_FORWARD(-, dchs);

			CHECK_FORWARD_LOG(std::log, dlog);
			CHECK_FORWARD_LOG(std::log2, dlog2);
			CHECK_FORWARD_LOG(std::log10, dlog10);
			CHECK_FORWARD_LOG(std::sqrt, dsqrt);



		}

	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsForward::BasicFunctionsForward);


