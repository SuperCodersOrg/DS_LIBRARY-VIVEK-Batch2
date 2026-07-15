#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListRemoveTests, RemoveFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.remove(10));

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListRemoveTests, RemoveHeadElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(10));

    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST(LinkedListRemoveTests, RemoveMiddleElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(20));

    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.search(10));
    EXPECT_FALSE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST(LinkedListRemoveTests, RemoveLastElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(30));

    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_FALSE(list.search(30));
}

TEST(LinkedListRemoveTests, RemoveNonExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_FALSE(list.remove(100));

    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
}

TEST(LinkedListRemoveTests, RemoveDuplicateElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.remove(20));

    EXPECT_EQ(list.size(), 3);

    EXPECT_TRUE(list.search(20));   // second duplicate should still exist
    EXPECT_TRUE(list.search(30));
}