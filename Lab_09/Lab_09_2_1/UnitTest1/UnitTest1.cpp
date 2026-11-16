#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09_2_1/calc.cpp"
#include "../Lab_09_2_1/Lab_09_2_1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// перевірка обчислення функції calc_w для активної гілки
		TEST_METHOD(TestCalcW)
		{
			double x = 2.0, y = 4.0;

#if IS_IN_RANGE(Z)
			double a = x * x + y + Z;
			double b = x * y * Z;
			double expected = (a > b) ? a : b;
#else
			double a = x * x + (y + Z) * (y + Z);
			double b = x * y;
			double expected = (a < b) ? a : b;
#endif

			Assert::AreEqual(expected, calc_w(x, y), 1e-9);
		}

		// перевірка макросів MAX, MIN, SQR
		TEST_METHOD(TestMacros)
		{
			Assert::AreEqual(9.0, SQR(3.0), 1e-9);
			Assert::AreEqual(10, MAX(4, 10));
			Assert::AreEqual(4, MIN(4, 10));
		}
	};
}
