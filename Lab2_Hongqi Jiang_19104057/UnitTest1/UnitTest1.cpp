#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2_Hongqi Jiang_19104057/count.cpp"

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
			Assert::AreEqual(1, Count_If_Elseif(x, a));



		}
	};
}
