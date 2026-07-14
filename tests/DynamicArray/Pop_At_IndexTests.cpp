#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"


TEST(PopAtIndexTests, PopFirstElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr.pop(0), 10);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 20);
    EXPECT_EQ(arr[1], 30);
}

TEST(PopAtIndexTests, PopMiddleElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);

    EXPECT_EQ(arr.pop(1), 20);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 30);
    EXPECT_EQ(arr[2], 40);
}

TEST(PopAtIndexTests, PopLastElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr.pop(2), 30);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(PopAtIndexTests, PopOnlyElement)
{
    DynamicArray<int> arr;

    arr.append(99);

    EXPECT_EQ(arr.pop(0), 99);
    EXPECT_EQ(arr.size(), 0);
}

TEST(PopAtIndexTests, InvalidIndexThrows)
{
    DynamicArray<int> arr;

    arr.append(10);

    EXPECT_THROW(arr.pop(1), std::out_of_range);
    EXPECT_THROW(arr.pop(100), std::out_of_range);
}

TEST(PopAtIndexTests, PopStringElement)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");
    arr.append("Cherry");

    EXPECT_EQ(arr.pop(1), "Banana");

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Cherry");
}