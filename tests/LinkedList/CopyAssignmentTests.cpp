#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"


TEST(LinkedListAssignmentOperatorTests, AssignEmptyList)
{
    LinkedList<int> original;

    LinkedList<int> copy;

    copy = original;

    EXPECT_TRUE(copy.empty());
}

TEST(LinkedListAssignmentOperatorTests, AssignSingleElement)
{
    LinkedList<int> original;

    original.insertBack(10);

    LinkedList<int> copy;

    copy = original;

    EXPECT_TRUE(copy.search(10));
}

TEST(LinkedListAssignmentOperatorTests, AssignMultipleElements)
{
    LinkedList<int> original;

    for(int i=1;i<=5;i++)
        original.insertBack(i);

    LinkedList<int> copy;

    copy = original;

    EXPECT_EQ(copy.size(),5);

    for(int i=1;i<=5;i++)
        EXPECT_TRUE(copy.search(i));
}

TEST(LinkedListAssignmentOperatorTests, SelfAssignment)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);

    list = list;

    EXPECT_EQ(list.size(),2);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
}

TEST(LinkedListAssignmentOperatorTests, DeepCopyAfterAssignment)
{
    LinkedList<int> original;

    original.insertBack(10);

    LinkedList<int> copy;

    copy = original;

    copy.remove(10);

    EXPECT_TRUE(original.search(10));
    EXPECT_FALSE(copy.search(10));
}

TEST(LinkedListAssignmentOperatorTests, OverwriteExistingList)
{
    LinkedList<int> original;

    original.insertBack(1);
    original.insertBack(2);

    LinkedList<int> copy;

    copy.insertBack(100);
    copy.insertBack(200);

    copy = original;

    EXPECT_EQ(copy.size(),2);

    EXPECT_TRUE(copy.search(1));
    EXPECT_TRUE(copy.search(2));

    EXPECT_FALSE(copy.search(100));
}