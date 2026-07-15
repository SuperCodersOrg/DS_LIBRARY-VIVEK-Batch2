#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapConstructorTests, NewMapIsEmpty)
{
    HashMap<int, int> map;

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapConstructorTests, ContainsReturnsFalse)
{
    HashMap<int, int> map;

    EXPECT_FALSE(map.contains(10));
}

TEST(HashMapConstructorTests, GetFromEmptyThrows)
{
    HashMap<int, int> map;

    EXPECT_THROW(map.get(10), std::out_of_range);
}

TEST(HashMapConstructorTests, RemoveFromEmptyMap)
{
    HashMap<int, int> map;

    EXPECT_FALSE(map.remove(10));

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapConstructorTests, ClearEmptyMap)
{
    HashMap<int, int> map;

    EXPECT_NO_THROW(map.clear());

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapConstructorTests, StringKeyValueConstructor)
{
    HashMap<std::string, std::string> map;

    EXPECT_TRUE(map.empty());
    EXPECT_EQ(map.size(), 0);

    EXPECT_FALSE(map.contains("Apple"));
}