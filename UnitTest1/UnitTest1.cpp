#include "pch.h"
#include "CppUnitTest.h"
#include "..//ap.12.3.rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountElementsWithValue)
        {
            Node* head = nullptr;
            insert(head, 5);
            insert(head, 2);
            insert(head, 3);
            insert(head, 1);
            insert(head, 4);
            insert(head, 5);
            insert(head, 1);
            insert(head, 6);
            insert(head, 5);
            insert(head, 8);

            int valueToFind = 2;
            int count = countElementsWithValue(head, valueToFind);
            Assert::AreEqual(1, count);
        }
	};
}
