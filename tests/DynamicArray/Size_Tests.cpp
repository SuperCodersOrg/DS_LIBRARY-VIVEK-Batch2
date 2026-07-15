#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArraySizeTests, EmptyArraySizeIsZero)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArraySizeTests, SizeAfterAppendingElements)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr.size(), 3);
}

TEST(DynamicArraySizeTests, SizeAfterRemovingElements)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.pop();

    EXPECT_EQ(arr.size(), 2);
}

TEST(DynamicArraySizeTests, SizeAfterClear)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

