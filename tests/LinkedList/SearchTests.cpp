#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(SearchTests, SearchInEmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}


TEST(SearchTests, SearchExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(20));
}


TEST(SearchTests, SearchNonExistingElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    EXPECT_FALSE(list.search(30));
}

TEST(SearchTests, SearchFirstAndLastElement)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(30));
}

TEST(SearchTests, SearchDuplicateValues)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(20);
    list.insertBack(30);

    EXPECT_TRUE(list.search(20));
}

TEST(SearchTests, SearchStringValues)
{
    LinkedList<std::string> list;

    list.insertBack("Apple");
    list.insertBack("Banana");

    EXPECT_TRUE(list.search("Apple"));
    EXPECT_TRUE(list.search("Banana"));
    EXPECT_FALSE(list.search("Cherry"));
}