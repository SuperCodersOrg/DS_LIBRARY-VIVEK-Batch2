#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapPutTests, InsertSingleElement)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.contains(1));
    EXPECT_EQ(map.get(1), 100);
}

TEST(HashMapPutTests, InsertMultipleElements)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);
    map.put(3, 300);

    EXPECT_EQ(map.size(), 3);

    EXPECT_EQ(map.get(1), 100);
    EXPECT_EQ(map.get(2), 200);
    EXPECT_EQ(map.get(3), 300);
}

TEST(HashMapPutTests, UpdateExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(1, 500);

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(1), 500);
}

TEST(HashMapPutTests, InsertStringKeyValue)
{
    HashMap<std::string, std::string> map;

    map.put("Apple", "Red");
    map.put("Banana", "Yellow");

    EXPECT_EQ(map.size(), 2);

    EXPECT_EQ(map.get("Apple"), "Red");
    EXPECT_EQ(map.get("Banana"), "Yellow");
}

TEST(HashMapPutTests, InsertManyElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 100; i++)
        map.put(i, i * 10);

    EXPECT_EQ(map.size(), 100);

    for (int i = 0; i < 100; i++)
        EXPECT_EQ(map.get(i), i * 10);
}

TEST(HashMapPutTests, InsertNegativeKeys)
{
    HashMap<int, int> map;

    map.put(-1, 10);
    map.put(-2, 20);

    EXPECT_EQ(map.size(), 2);

    EXPECT_EQ(map.get(-1), 10);
    EXPECT_EQ(map.get(-2), 20);
}