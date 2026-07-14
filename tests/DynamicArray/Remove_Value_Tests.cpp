#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(RemoveTests, RemoveExistingElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.remove(20);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 30);
}

TEST(RemoveTests, RemoveFirstElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.remove(10);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 20);
    EXPECT_EQ(arr[1], 30);
}

TEST(RemoveTests, RemoveLastElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.remove(30);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(RemoveTests, RemoveNonExistingElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    EXPECT_THROW(arr.remove(100), std::runtime_error);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(RemoveTests, RemoveFromEmptyArray)
{
    DynamicArray<int> arr;

    // EXPECT_NO_THROW(arr.remove(10));
    EXPECT_THROW(arr.remove(10), std::runtime_error);

    EXPECT_EQ(arr.size(), 0);
}

TEST(RemoveTests, RemoveDuplicateElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(20);
    arr.append(30);

    arr.remove(20);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}