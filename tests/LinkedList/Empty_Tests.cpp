#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"


TEST(LinkedListEmptyTests, NewListIsEmpty)
{
    LinkedList<int> list;

    EXPECT_TRUE(list.empty());
}


TEST(LinkedListEmptyTests, NotEmptyAfterInsertion)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_FALSE(list.empty());
}


TEST(LinkedListEmptyTests, EmptyAfterDeletingOnlyElement)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.deleteFront();

    EXPECT_TRUE(list.empty());
}


TEST(LinkedListEmptyTests, EmptyAfterClear)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.clear();

    EXPECT_TRUE(list.empty());
}


TEST(LinkedListEmptyTests, NotEmptyAfterRemovingOneElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.remove(10);

    EXPECT_FALSE(list.empty());
}


TEST(LinkedListEmptyTests, EmptyAfterRemovingAllElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.remove(10);
    list.remove(20);

    EXPECT_TRUE(list.empty());
}

