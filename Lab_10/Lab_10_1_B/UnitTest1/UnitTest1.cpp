#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_1_B/student.cpp"
#include "../Lab_10_1_B/Lab_10_1_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestIsExcellent)
        {
            Student s1{};
            s1.prizv = "Іваненко";
            s1.kurs = 1;
            s1.spec = KN;
            s1.fiz = 5;
            s1.mat = 5;
            s1.prog = 5;

            Student s2{};
            s2.prizv = "Петренко";
            s2.kurs = 2;
            s2.spec = INF;
            s2.fiz = 5;
            s2.mat = 4;
            s2.chysMet = 5;

            Assert::IsTrue(IsExcellent(s1));
            Assert::IsFalse(IsExcellent(s2));
        }

        TEST_METHOD(TestCalcPercentAvgAbove)
        {
            Student arr[4]{};

            // сер. бал = 5.0 (> 4.5)
            arr[0].spec = KN;
            arr[0].fiz = 5; arr[0].mat = 5; arr[0].prog = 5;

            // сер. бал = 4.67 (> 4.5)
            arr[1].spec = INF;
            arr[1].fiz = 5; arr[1].mat = 4; arr[1].chysMet = 5;

            // сер. бал = 4.33 (<= 4.5)
            arr[2].spec = ME;
            arr[2].fiz = 4; arr[2].mat = 4; arr[2].pedag = 5;

            // сер. бал = 3.67 (<= 4.5)
            arr[3].spec = TN;
            arr[3].fiz = 3; arr[3].mat = 4; arr[3].pedag = 4;

            double actual = CalcPercentAvgAbove(arr, 4, 4.5);
            Assert::AreEqual(50.0, actual, 1e-6);
        }
	};
}
