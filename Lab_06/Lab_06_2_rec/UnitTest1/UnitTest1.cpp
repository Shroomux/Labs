#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2_rec/Lab_06_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 6;
			int a[size] = { 1, 2, 3, 4, 5, 6 };
			int expected[size] = { 2, 1, 4, 3, 6, 5 };

			SwapPairs(a, size, 0);

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], a[i]);
			}
		}
	};
}
