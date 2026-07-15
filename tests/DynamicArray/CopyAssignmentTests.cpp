#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayCopyAssignmentTests, AssignEmptyArray)
{
    DynamicArray<int> original;

    DynamicArray<int> copy;

    copy = original;

    EXPECT_EQ(copy.size(),0);
}

TEST(DynamicArrayCopyAssignmentTests, AssignSingleElement)
{
    DynamicArray<int> original;

    original.append(10);

    DynamicArray<int> copy;

    copy = original;

    EXPECT_EQ(copy[0],10);
}

TEST(DynamicArrayCopyAssignmentTests, AssignMultipleElements)
{
    DynamicArray<int> original;

    for(int i=0;i<10;i++)
        original.append(i);

    DynamicArray<int> copy;

    copy = original;

    EXPECT_EQ(copy.size(),10);

    for(int i=0;i<10;i++)
        EXPECT_EQ(copy[i],i);
}

TEST(DynamicArrayCopyAssignmentTests, SelfAssignment)
{
    DynamicArray<int> arr;

    arr.append(10);
    arr.append(20);

    arr = arr;

    EXPECT_EQ(arr.size(),2);
    EXPECT_EQ(arr[0],10);
    EXPECT_EQ(arr[1],20);
}

TEST(DynamicArrayCopyAssignmentTests, DeepCopyAfterAssignment)
{
    DynamicArray<int> original;

    original.append(10);

    DynamicArray<int> copy;

    copy = original;

    copy[0] = 500;

    EXPECT_EQ(original[0],10);
    EXPECT_EQ(copy[0],500);
}

TEST(DynamicArrayCopyAssignmentTests, OverwriteExistingArray)
{
    DynamicArray<int> original;

    original.append(1);
    original.append(2);

    DynamicArray<int> copy;

    copy.append(100);
    copy.append(200);

    copy = original;

    EXPECT_EQ(copy.size(),2);
    EXPECT_EQ(copy[0],1);
    EXPECT_EQ(copy[1],2);
}

