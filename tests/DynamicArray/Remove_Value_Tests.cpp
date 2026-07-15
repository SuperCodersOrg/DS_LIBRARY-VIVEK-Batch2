#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayRemoveTests, RemoveExistingElement)
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

TEST(DynamicArrayRemoveTests, RemoveFirstElement)
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

TEST(DynamicArrayRemoveTests, RemoveLastElement)
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

TEST(DynamicArrayRemoveTests, RemoveNonExistingElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    EXPECT_THROW(arr.remove(100), std::runtime_error);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(DynamicArrayRemoveTests, RemoveFromEmptyArray)
{
    DynamicArray<int> arr;

    // EXPECT_NO_THROW(arr.remove(10));
    EXPECT_THROW(arr.remove(10), std::runtime_error);

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayRemoveTests, RemoveDuplicateElement)
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