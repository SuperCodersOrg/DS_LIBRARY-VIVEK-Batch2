#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapClearTests, ClearEmptyMap)
{
    HashMap<int, int> map;

    EXPECT_NO_THROW(map.clear());

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapClearTests, ClearSingleElement)
{
    HashMap<int, int> map;

    map.put(1, 100);

    map.clear();

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
    EXPECT_FALSE(map.contains(1));
}

TEST(HashMapClearTests, ClearMultipleElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 10; i++)
        map.put(i, i * 10);

    map.clear();

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);

    for (int i = 0; i < 10; i++)
        EXPECT_FALSE(map.contains(i));
}

TEST(HashMapClearTests, InsertAfterClear)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    map.clear();

    map.put(3, 300);

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.contains(3));
    EXPECT_FALSE(map.contains(1));
    EXPECT_EQ(map.get(3), 300);
}

TEST(HashMapClearTests, MultipleClearCalls)
{
    HashMap<int, int> map;

    map.put(1, 100);

    map.clear();
    map.clear();
    map.clear();

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapClearTests, ClearStringMap)
{
    HashMap<std::string, std::string> map;

    map.put("Apple", "Red");
    map.put("Banana", "Yellow");

    map.clear();

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);

    EXPECT_FALSE(map.contains("Apple"));
    EXPECT_FALSE(map.contains("Banana"));
}

