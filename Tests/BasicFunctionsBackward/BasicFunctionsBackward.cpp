#include "UnitTestDefines.h"
#include "qdefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctionsBackward
{
	TEST_CLASS(BasicFunctionsBackward)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsBackward);
		CPPUNIT_TEST(MathFunc1Backward);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(MathFunc1Backward)
		{
			CHECK_BACKWARD(std::exp, std::exp);
			CHECK_BACKWARD(std::cosh, std::sinh);
			CHECK_BACKWARD(std::sinh, std::cosh);
			CHECK_BACKWARD(std::tanh, dtanh);
			CHECK_BACKWARD(std::erfc, derfc);
			CHECK_BACKWARD(-, dchs);

			CHECK_BACKWARD_LOG(std::log, dlog);
			CHECK_BACKWARD_LOG(std::log2, dlog2);
			CHECK_BACKWARD_LOG(std::log10, dlog10);
			CHECK_BACKWARD_LOG(std::sqrt, dsqrt);
		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsBackward::BasicFunctionsBackward);


