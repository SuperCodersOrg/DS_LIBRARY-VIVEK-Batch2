#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(SizeTests, EmptyListSizeIsZero)
{
    LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);
}

TEST(SizeTests, SizeAfterInsertions)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.size(), 3);
}

TEST(SizeTests, SizeAfterDeletion)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.deleteFront();

    EXPECT_EQ(list.size(), 2);
}

TEST(SizeTests, SizeAfterRemove)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.remove(20);

    EXPECT_EQ(list.size(), 2);
}

TEST(SizeTests, SizeAfterClear)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.clear();

    EXPECT_EQ(list.size(), 0);
}

TEST(SizeTests, SizeUnchangedAfterInvalidInsert)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.insert(5, 20);

    EXPECT_EQ(list.size(), 1);
}