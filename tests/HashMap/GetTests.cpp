#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapGetTests, GetExistingKey)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_EQ(map.get(1), 100);
}

TEST(HashMapGetTests, GetMultipleKeys)
{
    HashMap<int, int> map;

    map.put(1, 100);
    map.put(2, 200);
    map.put(3, 300);

    EXPECT_EQ(map.get(1), 100);
    EXPECT_EQ(map.get(2), 200);
    EXPECT_EQ(map.get(3), 300);
}

TEST(HashMapGetTests, GetNonExistingKeyThrows)
{
    HashMap<int, int> map;

    map.put(1, 100);

    EXPECT_THROW(map.get(2), std::out_of_range);
}

TEST(HashMapGetTests, ModifyValueUsingGet)
{
    HashMap<int, int> map;

    map.put(1, 100);

    map.get(1) = 500;

    EXPECT_EQ(map.get(1), 500);
}

TEST(HashMapGetTests, ConstGet)
{
    HashMap<int, int> temp;

    temp.put(10, 999);

    const HashMap<int, int>& map = temp;

    EXPECT_EQ(map.get(10), 999);
}

TEST(HashMapGetTests, GetStringValue)
{
    HashMap<std::string, std::string> map;

    map.put("Apple", "Red");
    map.put("Banana", "Yellow");

    EXPECT_EQ(map.get("Apple"), "Red");
    EXPECT_EQ(map.get("Banana"), "Yellow");
}