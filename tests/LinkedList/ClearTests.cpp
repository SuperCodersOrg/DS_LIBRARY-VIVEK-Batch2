#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"


TEST(ClearTests, ClearEmptyList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.clear());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ClearTests, ClearSingleElement)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.search(10));
}


TEST(ClearTests, ClearMultipleElements)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.insertBack(i);

    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);

    for (int i = 1; i <= 5; i++)
        EXPECT_FALSE(list.search(i));
}


TEST(ClearTests, InsertAfterClear)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list.clear();

    list.insertBack(30);

    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.search(30));
    EXPECT_FALSE(list.search(10));
}


TEST(ClearTests, MultipleClearCalls)
{
    LinkedList<int> list;

    list.insertBack(10);

    list.clear();
    list.clear();
    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ClearTests, ClearStringList)
{
    LinkedList<std::string> list;

    list.insertBack("Apple");
    list.insertBack("Banana");

    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}