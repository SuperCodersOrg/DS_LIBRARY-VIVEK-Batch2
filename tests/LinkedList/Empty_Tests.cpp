#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"


TEST(EmptyTests, NewListIsEmpty)
{
    LinkedList<int> list;

    EXPECT_TRUE(list.empty());
}


TEST(EmptyTests, NotEmptyAfterInsertion)
{
    LinkedList<int> list;

    list.insertBack(10);

    EXPECT_FALSE(list.empty());
}


TEST(EmptyTests, EmptyAfterDeletingOnlyElement)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.deleteFront();

    EXPECT_TRUE(list.empty());
}


TEST(EmptyTests, EmptyAfterClear)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.clear();

    EXPECT_TRUE(list.empty());
}


TEST(EmptyTests, NotEmptyAfterRemovingOneElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.remove(10);

    EXPECT_FALSE(list.empty());
}


TEST(EmptyTests, EmptyAfterRemovingAllElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.remove(10);
    list.remove(20);

    EXPECT_TRUE(list.empty());
}

