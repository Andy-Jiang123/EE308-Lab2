#include "pch.h"
#include "CppUnitTest.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string x;
			x = "C:/Users/JHQ/Desktop/test.c";
			int a = 1;
			Assert::AreEqual("total num: 35", Count_Keywork_Switch_Case(x, a));



		}
	};
}
