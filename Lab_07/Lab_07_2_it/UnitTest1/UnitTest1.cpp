#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_it/Lab_07_2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Рядок 0: {4, 19, -2} -> максимум 19 у стовпці 1
            a[0][0] = 4;  a[0][1] = 19; a[0][2] = -2;
            a[1][0] = 0;  a[1][1] = 5;  a[1][2] = 1;
            a[2][0] = 7;  a[2][1] = -1; a[2][2] = 2;

            int maxCol = SearchMaxCol(a, 0, n);
            Assert::AreEqual(1, maxCol);

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
