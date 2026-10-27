#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_rec/Lab_06_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 6;
			int s[n] = { 5, 4, 7, 9, 6, 8 };

			int expectedCount = 4;
			int expectedSum = 25;

			Assert::AreEqual(expectedCount, Count(s, n, 0));
			Assert::AreEqual(expectedSum, Sum(s, n, 0));
		}
	};
}
