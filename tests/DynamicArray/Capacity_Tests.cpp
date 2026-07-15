#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayCapacityTests, InitialCapacity)
{
    DynamicArray<int> arr;

    EXPECT_GE(arr.capacity(), 0);
}

TEST(DynamicArrayCapacityTests, CapacityNeverLessThanSize)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 50; ++i)
        arr.append(i);

    EXPECT_GE(arr.capacity(), arr.size());
}

TEST(DynamicArrayCapacityTests, CapacityIncreasesAfterResize)
{
    DynamicArray<int> arr;

    size_t oldCapacity = arr.capacity();

    while (arr.capacity() == oldCapacity)
        arr.append(1);

    EXPECT_GT(arr.capacity(), oldCapacity);
}

TEST(DynamicArrayCapacityTests, CapacityAfterClear)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 20; ++i)
        arr.append(i);

    size_t oldCapacity = arr.capacity();

    arr.clear();

    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), oldCapacity);
}

TEST(DynamicArrayCapacityTests, StringArrayCapacity)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    EXPECT_GE(arr.capacity(), arr.size());
}

