#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_it/Lab_06_4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            const int n = 5;
            double a[n] = { -2.5, 4.0, -1.5, 0.0, 3.0 };
            Assert::AreEqual(-4.0, SumNegative(a, n), 0.0001);
        }

        TEST_METHOD(TestMethod2)
        {
            const int n = 5;
            double a[n] = { 20.0, 2.0, 3.0, 4.0, -10.0 };
            Assert::AreEqual(24.0, ProductBetween(a, 0, 4), 0.0001);
        }
	};
}
