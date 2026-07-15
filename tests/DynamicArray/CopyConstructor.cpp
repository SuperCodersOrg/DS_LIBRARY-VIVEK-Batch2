#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayCopyConstructorTests, CopyEmptyArray)
{
    DynamicArray<int> original;

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(), 0);
}

TEST(DynamicArrayCopyConstructorTests, CopySingleElement)
{
    DynamicArray<int> original;

    original.append(10);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(), 1);
    EXPECT_EQ(copy[0], 10);
}

TEST(DynamicArrayCopyConstructorTests, CopyMultipleElements)
{
    DynamicArray<int> original;

    for(int i=1;i<=5;i++)
        original.append(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());

    for(int i=0;i<5;i++)
        EXPECT_EQ(copy[i], original[i]);
}

TEST(DynamicArrayCopyConstructorTests, DeepCopy)
{
    DynamicArray<int> original;

    original.append(10);

    DynamicArray<int> copy(original);

    original[0] = 100;

    EXPECT_EQ(copy[0], 10);
    EXPECT_EQ(original[0], 100);
}

TEST(DynamicArrayCopyConstructorTests, StringArray)
{
    DynamicArray<std::string> original;

    original.append("Apple");
    original.append("Banana");

    DynamicArray<std::string> copy(original);

    EXPECT_EQ(copy[0], "Apple");
    EXPECT_EQ(copy[1], "Banana");
}

TEST(DynamicArrayCopyConstructorTests, CapacityPreserved)
{
    DynamicArray<int> original;

    for(int i=0;i<20;i++)
        original.append(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.capacity(), original.capacity());
}