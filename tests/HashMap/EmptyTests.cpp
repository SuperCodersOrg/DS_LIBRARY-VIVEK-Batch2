#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapEmptyTests, NewMapIsEmpty)
{
    HashMap<int, int> map;

    EXPECT_TRUE(map.empty());
}

TEST(HashMapEmptyTests, NotEmptyAfterInsertion)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_FALSE(map.empty());
}

TEST(HashMapEmptyTests, EmptyAfterRemovingOnlyElement)
{
    HashMap<int, int> map;

    map.put(1, 100);

    map.remove(1);

    EXPECT_TRUE(map.empty());
}

TEST(HashMapEmptyTests, EmptyAfterClear)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map.clear();

    EXPECT_TRUE(map.empty());
}

TEST(HashMapEmptyTests, NotEmptyAfterPartialRemove)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map.remove(1);

    EXPECT_FALSE(map.empty());
}

TEST(HashMapEmptyTests, EmptyAfterMultipleOperations)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map.remove(1);
    map.remove(2);

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}