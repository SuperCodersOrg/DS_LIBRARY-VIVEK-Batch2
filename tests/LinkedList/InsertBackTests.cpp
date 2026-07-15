#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"


TEST(LinkedListInsertBackTests, InsertIntoEmptyList)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.search(10));
    EXPECT_FALSE(list.empty());
}


TEST(LinkedListInsertBackTests, InsertMultipleElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.size(), 3);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}


TEST(LinkedListInsertBackTests, PreservesInsertionOrder)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    int expected = 10;

    list.forEach([&](int value)
    {
        EXPECT_EQ(value, expected);
        expected += 10;
    });
}


TEST(LinkedListInsertBackTests, InsertDuplicateValues)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(10);

    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.search(10));
}


TEST(LinkedListInsertBackTests, InsertStringValues)
{
    LinkedList<std::string> list;

    list.insertBack("Apple");
    list.insertBack("Banana");

    EXPECT_EQ(list.size(), 2);

    EXPECT_TRUE(list.search("Apple"));
    EXPECT_TRUE(list.search("Banana"));
}


TEST(LinkedListInsertBackTests, LargeNumberOfInsertions)
{
    LinkedList<int> list;

    for (int i = 0; i < 100; i++)
        list.insertBack(i);

    EXPECT_EQ(list.size(), 100);

    EXPECT_TRUE(list.search(0));
    EXPECT_TRUE(list.search(99));
}