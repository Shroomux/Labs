#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_5/Lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int depth = 0;
			int actual_res = f(25, 2, 2, 1, depth);

			Assert::AreEqual(565, actual_res);
			Assert::AreEqual(3, depth);
		}
	};
}
