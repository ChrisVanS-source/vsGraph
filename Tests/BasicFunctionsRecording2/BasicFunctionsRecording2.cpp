#include "UnitTestDefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctionsRecording2
{
	TEST_CLASS(BasicFunctionsRecording2)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsRecording2);
		CPPUNIT_TEST(MathFunc1RecordingPositive);
		CPPUNIT_TEST_SUITE_END();
		TEST_METHOD(MathFunc1RecordingPositive)
		{
			CHECK_RECORDING_LOG(std::log);
			CHECK_RECORDING_LOG(std::log2);
			CHECK_RECORDING_LOG(std::log10);
			CHECK_RECORDING_LOG(std::sqrt);
			CHECK_RECORDING(std::exp);
			CHECK_RECORDING(std::sinh);
			CHECK_RECORDING(std::cosh);
			CHECK_RECORDING(std::tanh);

		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsRecording2::BasicFunctionsRecording2);


