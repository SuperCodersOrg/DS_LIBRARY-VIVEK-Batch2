#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(OperatorBracketTests, AccessValidElements)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

TEST(OperatorBracketTests, ModifyElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    arr[0] = 99;

    EXPECT_EQ(arr[0], 99);
}

TEST(OperatorBracketTests, AccessFirstAndLastElement)
{
    DynamicArray<int> arr;

    arr.append(5);
    arr.append(10);
    arr.append(15);

    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[arr.size() - 1], 15);
}

TEST(OperatorBracketTests, InvalidIndexThrows)
{
    DynamicArray<int> arr;

    arr.append(10);

    EXPECT_THROW(arr[1], std::out_of_range);
    EXPECT_THROW(arr[100], std::out_of_range);
}

TEST(OperatorBracketTests, ConstAccess)
{
    DynamicArray<int> temp;

    temp.append(10);
    temp.append(20);

    const DynamicArray<int>& arr = temp;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(OperatorBracketTests, StringElements)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    EXPECT_EQ(arr[0], "Apple");

    arr[1] = "Cherry";

    EXPECT_EQ(arr[1], "Cherry");
}