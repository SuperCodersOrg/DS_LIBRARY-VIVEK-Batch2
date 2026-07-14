#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayConstructorTest, DefaultConstructor)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), 0);
}

TEST(DynamicArrayConstructorTest, CapacityValueConstructor)
{
    DynamicArray<int> arr(5, 100);

    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr.capacity(), 5);

    for(int i = 0; i < arr.size(); i++)
    {
        EXPECT_EQ(arr[i], 100);
    }
}

TEST(DynamicArrayConstructorTest, CapacityOne)
{
    DynamicArray<int> arr(1, 7);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 7);
}