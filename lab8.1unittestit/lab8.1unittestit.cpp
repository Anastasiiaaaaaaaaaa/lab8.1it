#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1it/lab8.1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab81IterativeTests
{
    TEST_CLASS(Lab81IterativeTests)
    {
    public:

        TEST_METHOD(TestThirdCommaIndex_Found)
        {
            char str[] = "one,two,three,four";
            int index = ThirdCommaIndex(str);
            Assert::AreEqual(13, index);
        }

        TEST_METHOD(TestThirdCommaIndex_NotFound)
        {
            char str[] = "one,two";
            int index = ThirdCommaIndex(str);
            Assert::AreEqual(-1, index);
        }

        TEST_METHOD(TestChange_ReplaceCommas)
        {
            char str[100] = "a,b,c";
            char* result = Change(str);
            Assert::AreEqual("a**b**c", str);
            Assert::AreEqual("a**b**c", result);
        }
    };
}