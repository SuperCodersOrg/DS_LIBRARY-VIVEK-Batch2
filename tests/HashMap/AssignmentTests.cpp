#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapAssignmentOperatorTests, AssignEmptyMap)
{
    HashMap<int, int> original;

    HashMap<int, int> copy;

    copy = original;

    EXPECT_TRUE(copy.empty());
    EXPECT_EQ(copy.size(), 0);
}

TEST(HashMapAssignmentOperatorTests, AssignSingleElement)
{
    HashMap<int, int> original;

    original.put(1, 100);

    HashMap<int, int> copy;

    copy = original;

    EXPECT_EQ(copy.size(), 1);
    EXPECT_TRUE(copy.contains(1));
    EXPECT_EQ(copy.get(1), 100);
}

TEST(HashMapAssignmentOperatorTests, AssignMultipleElements)
{
    HashMap<int, int> original;

    for (int i = 0; i < 10; i++)
        original.put(i, i * 10);

    HashMap<int, int> copy;

    copy = original;

    EXPECT_EQ(copy.size(), original.size());

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(copy.get(i), i * 10);
}

TEST(HashMapAssignmentOperatorTests, SelfAssignment)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map = map;

    EXPECT_EQ(map.size(), 2);
    EXPECT_EQ(map.get(1), 100);
    EXPECT_EQ(map.get(2), 200);
}

TEST(HashMapAssignmentOperatorTests, DeepCopyAfterAssignment)
{
    HashMap<int, int> original;

    original.put(1, 100);

    HashMap<int, int> copy;

    copy = original;

    copy.put(1, 999);

    EXPECT_EQ(original.get(1), 100);
    EXPECT_EQ(copy.get(1), 999);
}

TEST(HashMapAssignmentOperatorTests, OverwriteExistingMap)
{
    HashMap<int, int> original;

    original.put(1, 100);
    original.put(2, 200);

    HashMap<int, int> copy;

    copy.put(10, 1000);
    copy.put(20, 2000);

    copy = original;

    EXPECT_EQ(copy.size(), 2);

    EXPECT_TRUE(copy.contains(1));
    EXPECT_TRUE(copy.contains(2));

    EXPECT_FALSE(copy.contains(10));
    EXPECT_FALSE(copy.contains(20));

    EXPECT_EQ(copy.get(1), 100);
    EXPECT_EQ(copy.get(2), 200);
}