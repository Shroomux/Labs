#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_2/Lab_05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 0;
			double eps = 0.0001;
			double x = 2.0;
			double expected = log((x + 1.0) / (x - 1.0)); // ln(3) ≈ 1.09861
			double actual = S(x, eps, n, 0);

			Assert::AreEqual(expected, actual, 0.001);
		}
	};
}
