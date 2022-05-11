#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.4.2/Lab_12.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* begin1 = NULL,
				* end1 = NULL,
				* begin2 = NULL,
				* end2 = NULL,
				* T=NULL;
			bool result = false;
			int flag = 0;
			int flag2 = 0;
			int a1[5] = { 1,1,2,3,5 };
			int a2[3] = { 1,2,3 };
			for (int i = 0; i < 5; i++)
			{
				insert(begin1, a1[i],T);
			}
			T = NULL;
			for (int i = 0; i < 3; i++)
			{
				insert(begin2, a2[i],T);
			}
			Assert::AreEqual(AreInElem(begin1, begin2, begin1,begin2, begin2, result,flag,flag2), true);

		}
	};
}
