#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(DeleteFrontTests, DeleteFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_NO_THROW(list.deleteFront());

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(DeleteFrontTests, DeleteOnlyElement)
{
    LinkedList<int> list;

    list.insertFront(10);

    list.deleteFront();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.search(10));
}

TEST(DeleteFrontTests, DeleteFrontFromMultipleElements)
{
    LinkedList<int> list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    list.deleteFront();

    EXPECT_EQ(list.size(), 2);

    EXPECT_FALSE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST(DeleteFrontTests, DeleteAllElements)
{
    LinkedList<int> list;

    list.insertFront(30);
    list.insertFront(20);
    list.insertFront(10);

    list.deleteFront();
    list.deleteFront();
    list.deleteFront();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(DeleteFrontTests, MultipleDeletesOnEmptyList)
{
    LinkedList<int> list;

    list.deleteFront();
    list.deleteFront();
    list.deleteFront();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(DeleteFrontTests, DeleteStringElements)
{
    LinkedList<std::string> list;

    list.insertFront("Cherry");
    list.insertFront("Banana");
    list.insertFront("Apple");

    list.deleteFront();

    EXPECT_EQ(list.size(), 2);

    EXPECT_FALSE(list.search("Apple"));
    EXPECT_TRUE(list.search("Banana"));
    EXPECT_TRUE(list.search("Cherry"));
}