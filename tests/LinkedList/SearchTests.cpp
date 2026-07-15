#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListSearchTests, SearchInEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}


TEST(LinkedListSearchTests, SearchExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(20));
}


TEST(LinkedListSearchTests, SearchNonExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_FALSE(list.search(30));
}

TEST(LinkedListSearchTests, SearchFirstAndLastElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(30));
}

TEST(LinkedListSearchTests, SearchDuplicateValues)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(20));
}

TEST(LinkedListSearchTests, SearchStringValues)
{
    LinkedList<std::string> list;

    list.insertBack("Apple");
    list.insertBack("Banana");

    EXPECT_TRUE(list.search("Apple"));
    EXPECT_TRUE(list.search("Banana"));
    EXPECT_FALSE(list.search("Cherry"));
}