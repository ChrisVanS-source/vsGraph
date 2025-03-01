#pragma once

#ifdef __linux__
#include "CppUnitTestAssert.h" 
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#define TEST_CLASS(A) class A : public CppUnit::TestFixture
#define TEST_METHOD(A) void A()
#else
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define CPPUNIT_TEST_SUITE(A)
#define CPPUNIT_TEST(A)
#define CPPUNIT_TEST_SUITE_END()
#define CPPUNIT_TEST_SUITE_REGISTRATION(A)
#endif

#define display_duration(A)

#ifdef __linux__

#include <cppunit/ui/text/TestRunner.h>

#include <chrono>

int main(int argc, char** argv)
{
	auto test_start = std::chrono::high_resolution_clock::now();

	CppUnit::TextTestRunner runner;
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
	runner.run();

	auto test_end = std::chrono::high_resolution_clock::now();

	auto test_duration = std::chrono::duration_cast<std::chrono::microseconds>(test_end - test_start);

	std::cout << test_duration.count() << std::endl;

}

#endif


