#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_it/Lab_08_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIncludeWithPairNo)
		{
			char str[] = "piano music";
			Assert::IsTrue(Include(str));
		}
		TEST_METHOD(TestIncludeWithoutPairs)
		{
			char str[] = "simple test";
			Assert::IsFalse(Include(str));
		}
		TEST_METHOD(TestIncludeWithPairOn)
		{
			char str[] = "lemon tree";
			Assert::IsTrue(Include(str));
		}
	};
}
