#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09_1/var.cpp"
#include "../Lab_09_1/dod.cpp"
#include "../Lab_09_1/sum.cpp"
#include "../Lab_09_1/Lab_09_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// перевірка обчислення суми ряду
		TEST_METHOD(TestSum)
		{
			x = 2.0;
			e = 0.000001;
			sum();

			double expected = log((x + 1) / (x - 1));
			Assert::AreEqual(expected, s, 0.00001);
		}

		// перевірка рекурентного обчислення доданку
		TEST_METHOD(TestDod)
		{
			x = 2.0;
			n = 1;
			a = 1.0 / x;
			dod();

			double expected = 1.0 / 24.0;
			Assert::AreEqual(expected, a, 1e-9);
		}
	};
}
