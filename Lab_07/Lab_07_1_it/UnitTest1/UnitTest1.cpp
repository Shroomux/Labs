#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1_it/Lab_07_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 4;

            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Рядок 0: {10, 5, 0, 8}
            // Рядок 1: {15, 2, 0, 1} -> має стати першим (15 > 10)
            // Рядок 2: {10, 5, 0, 3} -> однаковий col 0 (10) і col 1 (5), але col 3 менший (3 < 8) -> має стати вище рядка 0
            a[0][0] = 10; a[0][1] = 5; a[0][2] = 0; a[0][3] = 8;
            a[1][0] = 15; a[1][1] = 2; a[1][2] = 0; a[1][3] = 1;
            a[2][0] = 10; a[2][1] = 5; a[2][2] = 0; a[2][3] = 3;

            Sort(a, rowCount, colCount);

            // Очікуваний порядок після сортування:
            // Позиція 0: колишній рядок 1 (15)
            // Позиція 1: колишній рядок 2 (10, 5, 0, 3)
            // Позиція 2: колишній рядок 0 (10, 5, 0, 8)
            Assert::AreEqual(15, a[0][0]);
            Assert::AreEqual(10, a[1][0]);
            Assert::AreEqual(3, a[1][3]);
            Assert::AreEqual(10, a[2][0]);
            Assert::AreEqual(8, a[2][3]);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
