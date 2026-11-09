#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_string/Lab_08_1_string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestIncludeWithPairNo)
        {
            string str = "piano music";
            Assert::IsTrue(Include(str));
        }

        TEST_METHOD(TestIncludeWithPairOn)
        {
            string str = "lemon tree";
            Assert::IsTrue(Include(str));
        }

        TEST_METHOD(TestIncludeWithoutTargetPairs)
        {
            string str = "simple text";
            Assert::IsFalse(Include(str));
        }
	};
}
