#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListFindTests, FindInEmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.find(10), nullptr);
}

TEST(LinkedListFindTests, FindExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    int* ptr = list.find(20);

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, 20);
}

TEST(LinkedListFindTests, FindNonExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_EQ(list.find(30), nullptr);
}

TEST(LinkedListFindTests, ModifyElementUsingReturnedPointer)
{
    LinkedList<int> list;

    list.insertBack(10);

    int* ptr = list.find(10);

    ASSERT_NE(ptr, nullptr);

    *ptr = 100;

    EXPECT_TRUE(list.search(100));
    EXPECT_FALSE(list.search(10));
}

TEST(LinkedListFindTests, ConstFind)
{
    LinkedList<int> temp;

    temp.insertBack(10);
    temp.insertBack(20);

    const LinkedList<int>& list = temp;

    const int* ptr = list.find(20);

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, 20);
}

TEST(LinkedListFindTests, FindStringElement)
{
    LinkedList<std::string> list;

    list.insertBack("Apple");
    list.insertBack("Banana");

    std::string* ptr = list.find("Banana");

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, "Banana");
}