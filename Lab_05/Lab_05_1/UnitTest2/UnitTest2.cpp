#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_1/Lab_05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double c;
			c = g(0.0, 0.0, 0.0);
			Assert::AreEqual(c, 1.0, 0.0001);
		}
	};
}
