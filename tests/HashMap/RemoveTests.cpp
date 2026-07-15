#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapRemoveTests, RemoveExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_TRUE(map.remove(1));

    EXPECT_FALSE(map.contains(1));
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapRemoveTests, RemoveNonExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_FALSE(map.remove(2));

    EXPECT_TRUE(map.contains(1));
    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapRemoveTests, RemoveFromEmptyMap)
{
    HashMap<int, int> map;

    EXPECT_FALSE(map.remove(10));

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapRemoveTests, RemoveMultipleKeys)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);
    map.put(3, 300);

    EXPECT_TRUE(map.remove(2));

    EXPECT_EQ(map.size(), 2);

    EXPECT_TRUE(map.contains(1));
    EXPECT_FALSE(map.contains(2));
    EXPECT_TRUE(map.contains(3));
}

TEST(HashMapRemoveTests, RemoveAllKeys)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    EXPECT_TRUE(map.remove(1));
    EXPECT_TRUE(map.remove(2));

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapRemoveTests, RemoveStringKey)
{
    HashMap<std::string, std::string> map;

    map.put("Apple", "Red");
    map.put("Banana", "Yellow");

    EXPECT_TRUE(map.remove("Apple"));

    EXPECT_FALSE(map.contains("Apple"));
    EXPECT_TRUE(map.contains("Banana"));

    EXPECT_EQ(map.size(), 1);
}