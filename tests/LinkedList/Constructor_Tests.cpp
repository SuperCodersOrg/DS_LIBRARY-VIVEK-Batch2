#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(ConstructorTests, NewListIsEmpty)
{
    LinkedList<int> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ConstructorTests, SearchInEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}


TEST(ConstructorTests, FindInEmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.find(10), nullptr);
}


TEST(ConstructorTests, ClearNewList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.clear());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ConstructorTests, DeleteFrontOnNewList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.deleteFront());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ConstructorTests, StringListConstructor)
{
    LinkedList<std::string> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.search("Apple"));
}