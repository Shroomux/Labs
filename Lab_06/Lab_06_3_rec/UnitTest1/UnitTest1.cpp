#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3_rec/Lab_06_3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			int sortedArr[n] = { 1, 3, 3, 8 };

			Assert::IsTrue(IsSorted(sortedArr, n, 0));
			Assert::IsTrue(IsSorted<int>(sortedArr, n, 0));
		}
		TEST_METHOD(TestMethod2)
		{
			const int n = 4;
			int unsortedArr[n] = { 1, 5, 2, 8 };

			Assert::IsFalse(IsSorted(unsortedArr, n, 0));
			Assert::IsFalse(IsSorted<int>(unsortedArr, n, 0));
		}
	};
}
