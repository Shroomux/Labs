#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_3/Lab_05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 1.0;
			double expected = (1.0 - sin(1.0) * sin(1.0)) / exp(1.0); // ≈ 0.1073938
			double actual = r(x);

			Assert::AreEqual(expected, actual, 0.00001);
		}
	};
}
