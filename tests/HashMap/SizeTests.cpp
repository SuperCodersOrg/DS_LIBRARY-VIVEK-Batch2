#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapSizeTests, NewMapSizeIsZero)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapSizeTests, SizeAfterSingleInsertion)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTests, SizeAfterMultipleInsertions)
{
    HashMap<int, int> map;

    for (int i = 0; i < 10; i++)
        map.put(i, i * 10);

    EXPECT_EQ(map.size(), 10);
}

TEST(HashMapSizeTests, SizeAfterRemove)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);
    map.put(3, 300);

    map.remove(2);

    EXPECT_EQ(map.size(), 2);
}

TEST(HashMapSizeTests, SizeAfterClear)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map.clear();

    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapSizeTests, SizeAfterUpdatingExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(1, 500);

    EXPECT_EQ(map.size(), 1);
}