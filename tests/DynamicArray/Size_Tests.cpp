#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(SizeTests, EmptyArraySizeIsZero)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(SizeTests, SizeAfterAppendingElements)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr.size(), 3);
}

TEST(SizeTests, SizeAfterRemovingElements)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.pop();

    EXPECT_EQ(arr.size(), 2);
}

TEST(SizeTests, SizeAfterClear)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
}

