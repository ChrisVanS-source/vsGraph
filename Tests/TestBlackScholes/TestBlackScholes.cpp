#include "UnitTestDefines.h"
#include <sstream>
#include "TestBlackScholes.h"

int test_blackscholes();

#include "ScopedRedirect.h"

namespace TestBlackScholes
{
	TEST_CLASS(TestBlackScholes)
	{
	public:
		
		CPPUNIT_TEST_SUITE(TestBlackScholes);
		CPPUNIT_TEST(TestGreeks);
		CPPUNIT_TEST_SUITE_END();

		TEST_METHOD(TestGreeks)
		{
			std::ostringstream test_res;
			ScopedRedirect redirect(std::cout, test_res);
			test_blackscholes();
			std::string actual_res = test_res.str();
			Assert::AreEqual(expected_res, actual_res);
		}
	};
}

#define main test_blackscholes

#include "../../Examples/BlackScholes/BlackScholes.cpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBlackScholes::TestBlackScholes);
