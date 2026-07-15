#include <gtest/gtest.h> 
#include "../../include/DynamicArray.h"


TEST(DynamicArrayPopTests, PopSingleElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    EXPECT_EQ(arr.pop(), 10);
    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayPopTests, PopReturnsLastElement)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr.pop(), 30);
    EXPECT_EQ(arr.size(), 2);
}

TEST(DynamicArrayPopTests, MultipleConsecutivePops)
{
    DynamicArray<int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    EXPECT_EQ(arr.pop(), 3);
    EXPECT_EQ(arr.pop(), 2);
    EXPECT_EQ(arr.pop(), 1);

    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayPopTests, PopPreservesRemainingElements)
{
    DynamicArray<int> arr;

    arr.append(5);
    arr.append(10);
    arr.append(15);

    arr.pop();

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 10);
}

TEST(DynamicArrayPopTests, PopFromEmptyArrayThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.pop(), std::out_of_range);
}

TEST(DynamicArrayPopTests, PopStringElement)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    EXPECT_EQ(arr.pop(), "Banana");
    EXPECT_EQ(arr.size(), 1); 
    EXPECT_EQ(arr[0], "Apple");
}