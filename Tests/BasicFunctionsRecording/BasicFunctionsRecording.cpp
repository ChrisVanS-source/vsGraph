#include "UnitTestDefines.h"

#include "qrecorder.h"
#include "qdual.h"
#include "qutils.h"
#include "qgraph_traits.h"
using namespace vstech;

#include "BasicFunctions.h"
#include "qscalar_i.h"

namespace BasicFunctionsRecording
{
	TEST_CLASS(BasicFunctionsRecording)
	{
	public:

		CPPUNIT_TEST_SUITE(BasicFunctionsRecording);
		CPPUNIT_TEST(MathFunc1Recording);
		CPPUNIT_TEST_SUITE_END();

		template<class T, class U>
		struct MathFunc1_Rec_template
		{
			template<class Op>
			static void run(Op op, qscalar<T>& x)
			{
				auto epsT = epsilon<typename qtype_traits<T>::type>();
				auto epsU = epsilon<typename qtype_traits<U>::type>();

				double eps = epsT;
				if (eps < epsU)
					eps = epsU;

				qrecorder<U> rec;

				rec.start();

				rec.input(x);

				auto y = op(x);

				rec.output(y);

				rec.stop();

				auto g = rec.graph();

				auto ws = g.workspace();

				g.run(ws);

				auto res = ws.get_value(y);

				for (uint64_t i = 0; i < qtype_traits<U>::alignment(); ++i)
					Assert::AreEqual((double)y[qtype_traits<T>::alignment() == 1 ? 0 : i], (double)bracket(res, i), (double)eps);

			}

		};

		TEST_METHOD(MathFunc1Recording)
		{
			CHECK_RECORDING(std::sin);
			CHECK_RECORDING(std::cos);
			CHECK_RECORDING(std::tan);
			CHECK_RECORDING_TRIG(std::asin);
			CHECK_RECORDING_TRIG(std::acos);
			CHECK_RECORDING_TRIG(std::atan);
			CHECK_RECORDING(std::erfc);
			CHECK_RECORDING(std::normal_cdf);
#if !defined(__linux__) || defined(_DEBUG)
			CHECK_RECORDING(std::ceil);
			CHECK_RECORDING(std::floor);
#endif
		}
	};
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicFunctionsRecording::BasicFunctionsRecording);


