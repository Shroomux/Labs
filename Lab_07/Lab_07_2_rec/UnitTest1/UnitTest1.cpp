#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_rec/Lab_07_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 4;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Рядок 0: {-7, -1, 4, -5} -> максимум 4 знаходиться в стовпці з індексом 2
            a[0][0] = -7; a[0][1] = -1; a[0][2] = 4; a[0][3] = -5;

            int maxCol = SearchMaxCol(a, 0, n, 1, 0);
            Assert::AreEqual(2, maxCol);

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
