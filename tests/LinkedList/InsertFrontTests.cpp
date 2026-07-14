#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

// insert into empty list
TEST(InsertFrontTests, InsertIntoEmptyList)
{
    LinkedList<int> list;

    list.insertFront(10);

    EXPECT_EQ(list.size(), 1);

    bool found = list.search(10);
    EXPECT_TRUE(found);
}

TEST(InsertFrontTests, InsertMultipleElements)
{
    LinkedList<int> list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    EXPECT_EQ(list.size(), 3);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST(InsertFrontTests, NewElementBecomesHead)
{
    LinkedList<int> list;

    list.insertFront(20);
    list.insertFront(10);

    EXPECT_EQ(*list.find(10), 10);
}

TEST(InsertFrontTests, InsertDuplicateValues)
{
    LinkedList<int> list;

    list.insertFront(5);
    list.insertFront(5);

    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.search(5));
}

TEST(InsertFrontTests, InsertStringValues)
{
    LinkedList<std::string> list;

    list.insertFront("Apple");
    list.insertFront("Banana");

    EXPECT_TRUE(list.search("Apple"));
    EXPECT_TRUE(list.search("Banana"));

    EXPECT_EQ(list.size(), 2);
}

TEST(InsertFrontTests, LargeNumberOfInsertions)
{
    LinkedList<int> list;

    for (int i = 0; i < 100; i++)
        list.insertFront(i);

    EXPECT_EQ(list.size(), 100);

    EXPECT_TRUE(list.search(0));
    EXPECT_TRUE(list.search(99));
}

