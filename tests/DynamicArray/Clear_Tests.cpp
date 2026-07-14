#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(ClearTests, ClearEmptyArray)
{
    DynamicArray<int> arr;

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(ClearTests, ClearSingleElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(ClearTests, ClearMultipleElements)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 10; i++)
        arr.append(i);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(ClearTests, AppendAfterClear)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr.clear();

    arr.append(30);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 30);
}

TEST(ClearTests, ClearStringArray)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(ClearTests, ClearMultipleTimes)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.clear();
    arr.clear();
    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}