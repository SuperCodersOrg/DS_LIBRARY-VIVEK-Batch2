#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapContainsTests, EmptyMap)
{
    HashMap<int, int> map;

    EXPECT_FALSE(map.contains(10));
}

TEST(HashMapContainsTests, ExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_TRUE(map.contains(1));
}

TEST(HashMapContainsTests, NonExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);

    EXPECT_FALSE(map.contains(3));
}

TEST(HashMapContainsTests, AfterRemove)
{
    HashMap<int, int> map;

    map.put(1, 100);

    map.remove(1);

    EXPECT_FALSE(map.contains(1));
}

TEST(HashMapContainsTests, AfterUpdatingValue)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(1, 500);

    EXPECT_TRUE(map.contains(1));
    EXPECT_EQ(map.get(1), 500);
}

TEST(HashMapContainsTests, StringKeys)
{
    HashMap<std::string, std::string> map;

    map.put("Apple", "Red");
    map.put("Banana", "Yellow");

    EXPECT_TRUE(map.contains("Apple"));
    EXPECT_TRUE(map.contains("Banana"));
    EXPECT_FALSE(map.contains("Orange"));
}