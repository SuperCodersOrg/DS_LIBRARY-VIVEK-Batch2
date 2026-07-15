#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayClearTests, ClearEmptyArray)
{
    DynamicArray<int> arr;

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayClearTests, ClearSingleElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayClearTests, ClearMultipleElements)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 10; i++)
        arr.append(i);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayClearTests, AppendAfterClear)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr.clear();

    arr.append(30);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 30);
}

TEST(DynamicArrayClearTests, ClearStringArray)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayClearTests, ClearMultipleTimes)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr.clear();
    arr.clear();
    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}