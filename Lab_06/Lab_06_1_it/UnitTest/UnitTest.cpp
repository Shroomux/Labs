#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_it/Lab_06_1_it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 6;
			int s[n] = { 5, 4, 7, 9, 6, 8 };

			int expCount = 4;
			int expSum = 25;

			Assert::AreEqual(expCount, Count(s, n));
			Assert::AreEqual(expSum, Sum(s, n));
		}
	};
}
