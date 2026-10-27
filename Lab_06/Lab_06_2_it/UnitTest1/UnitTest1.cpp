#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2_it/Lab_06_2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 6;
			int a[size] = { 10, 20, 30, 40, 50, 60 };
			int expected[size] = { 20, 10, 40, 30, 60, 50 };

			SwapPairs(a, size);

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], a[i]);
			}
		}
	};
}
