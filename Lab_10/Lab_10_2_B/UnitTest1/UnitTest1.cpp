#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_2_B/student.cpp"
#include "../Lab_10_2_B/Lab_10_2_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestSortAndBinSearch)
        {
            Student arr[4]{};
            arr[0].prizv = "Яковенко"; arr[0].spec = KN;  arr[0].kurs = 2; arr[0].prog = 5;
            arr[1].prizv = "Авраменко"; arr[1].spec = INF; arr[1].kurs = 3; arr[1].chysMet = 4;
            arr[2].prizv = "Бойко";    arr[2].spec = KN;  arr[2].kurs = 2; arr[2].prog = 4;
            arr[3].prizv = "Сидоренко"; arr[3].spec = FI;  arr[3].kurs = 1; arr[3].pedag = 5;

            Sort(arr, 4);
            // Порядок за назвою спеціальності -> курсом -> прізвищем:
            // [0]: INF ("Інформатика") - Авраменко
            // [1]: KN  ("Комп'ютерні науки"), курс 2 - Бойко
            // [2]: KN  ("Комп'ютерні науки"), курс 2 - Яковенко
            // [3]: FI  ("Фізика та інформатика") - Сидоренко

            Assert::AreEqual(1, BinSearch(arr, 4, "Бойко", KN, 2));
            Assert::AreEqual(-1, BinSearch(arr, 4, "Неіснуючий", KN, 2));
        }

        TEST_METHOD(TestIndexSort)
        {
            Student arr[3]{};
            arr[0].prizv = "Коваль"; arr[0].spec = FI;  arr[0].kurs = 1;
            arr[1].prizv = "Іванчук"; arr[1].spec = INF; arr[1].kurs = 2;
            arr[2].prizv = "Бабій";  arr[2].spec = KN;  arr[2].kurs = 3;

            int* I = IndexSort(arr, 3);
            // Правильний індексний порядок: INF (1), KN (2), FI (0)
            Assert::AreEqual(1, I[0]);
            Assert::AreEqual(2, I[1]);
            Assert::AreEqual(0, I[2]);

            delete[] I;
        }
	};
}
