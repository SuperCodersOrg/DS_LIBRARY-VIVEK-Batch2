#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(LinkedListCopyConstructorTests, CopyEmptyList)
{
    LinkedList<int> original;

    LinkedList<int> copy(original);

    EXPECT_TRUE(copy.empty());
}

TEST(LinkedListCopyConstructorTests, CopySingleElement)
{
    LinkedList<int> original;

    original.insertBack(10);

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.size(),1);
    EXPECT_TRUE(copy.search(10));
}

TEST(LinkedListCopyConstructorTests, CopyMultipleElements)
{
    LinkedList<int> original;

    for(int i=1;i<=5;i++)
        original.insertBack(i);

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.size(),5);

    for(int i=1;i<=5;i++)
        EXPECT_TRUE(copy.search(i));
}

TEST(LinkedListCopyConstructorTests, DeepCopy)
{
    LinkedList<int> original;

    original.insertBack(10);

    LinkedList<int> copy(original);

    original.remove(10);

    EXPECT_TRUE(copy.search(10));
    EXPECT_FALSE(original.search(10));
}

TEST(LinkedListCopyConstructorTests, CopyStringList)
{
    LinkedList<std::string> original;

    original.insertBack("Apple");
    original.insertBack("Banana");

    LinkedList<std::string> copy(original);

    EXPECT_TRUE(copy.search("Apple"));
    EXPECT_TRUE(copy.search("Banana"));
}

TEST(LinkedListCopyConstructorTests, IndependentLists)
{
    LinkedList<int> original;

    original.insertBack(1);

    LinkedList<int> copy(original);

    copy.insertBack(2);

    EXPECT_EQ(original.size(),1);
    EXPECT_EQ(copy.size(),2);
}