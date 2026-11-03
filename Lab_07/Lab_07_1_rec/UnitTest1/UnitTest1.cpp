#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1_rec/Lab_07_1_rec.cpp"

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

            a[0][0] = 10; a[0][1] = 5; a[0][2] = 0; a[0][3] = 8;
            a[1][0] = 15; a[1][1] = 2; a[1][2] = 0; a[1][3] = 1;
            a[2][0] = 10; a[2][1] = 5; a[2][2] = 0; a[2][3] = 3;

            SortRows(a, rowCount, colCount, 0);

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
