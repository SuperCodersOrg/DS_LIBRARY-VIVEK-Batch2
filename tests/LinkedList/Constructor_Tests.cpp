#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListConstructorTests, NewListIsEmpty)
{
    LinkedList<int> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(LinkedListConstructorTests, SearchInEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}


TEST(LinkedListConstructorTests, FindInEmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.find(10), nullptr);
}


TEST(LinkedListConstructorTests, ClearNewList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.clear());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(LinkedListConstructorTests, DeleteFrontOnNewList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.deleteFront());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(LinkedListConstructorTests, StringListConstructor)
{
    LinkedList<std::string> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.search("Apple"));
}