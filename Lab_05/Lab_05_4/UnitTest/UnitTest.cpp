#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_4/Lab_05_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int K = 1;
			int N = 1;

			double exp = cos(sin(1.0)) / (1.0 + sin(1.0) * sin(1.0));
			double act = S0(K, N);
			Assert::AreEqual(exp, act, 0.00001);
		}
	};
}
