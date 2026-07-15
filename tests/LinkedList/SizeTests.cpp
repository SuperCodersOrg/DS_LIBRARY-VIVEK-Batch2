#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListSizeTests, EmptyListSizeIsZero)
{
    LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListSizeTests, SizeAfterInsertions)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_EQ(list.size(), 3);
}

TEST(LinkedListSizeTests, SizeAfterDeletion)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.deleteFront();

    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListSizeTests, SizeAfterRemove)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.remove(20);

    EXPECT_EQ(list.size(), 2);
}

TEST(LinkedListSizeTests, SizeAfterClear)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.clear();

    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListSizeTests, SizeUnchangedAfterInvalidInsert)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.insert(5, 20);

    EXPECT_EQ(list.size(), 1);
}