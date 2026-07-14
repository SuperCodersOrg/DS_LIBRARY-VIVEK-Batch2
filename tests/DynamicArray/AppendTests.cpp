#include <gtest/gtest.h> 
#include "../../include/DynamicArray.h"

TEST(DynamicArrayPushBackTest, PushSingleElement)
{
    DynamicArray<int> arr;

    arr.append(10);

    EXPECT_EQ(arr.size(),1);   
    EXPECT_EQ(arr[0],10);
}

TEST(DynamicArrayPushBackTest, PushMultipleElements)
{
    DynamicArray<int> arr;

    for(int i=1;i<=5;i++)
        arr.append(i);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i+1);
}

TEST(DynamicArrayPushBackTest, PushTriggersResize)
{
    DynamicArray<int> arr(2, 0);  // size=2, capacity=2
    
    int oldCap = arr.capacity();  // oldCap = 2
    
    arr.append(1);  // size=3, should trigger resize (capacity becomes 4)
    
    EXPECT_GT(arr.capacity(), oldCap);  // 4 > 2 ✓
    EXPECT_EQ(arr.size(), 3);           // size = 3 ✓
    
    // Verify elements
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 0);
    EXPECT_EQ(arr[2], 1);
}

TEST(DynamicArrayPushBackTest, PushLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<10000;i++)
        arr.append(i);

    EXPECT_EQ(arr.size(),10000);

    for(int i=0;i<10000;i++)
        EXPECT_EQ(arr[i],i);
}

// Test 4: Append default value
TEST(AppendTests, AppendDefaultValue)
{
    DynamicArray<int> arr;

    arr.append();

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 0);
}

// Test 5: Append string elements
TEST(AppendTests, AppendStringElements)
{
    DynamicArray<std::string> arr;

    arr.append("Apple");
    arr.append("Banana");

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
}

// Test 6: Preserve insertion order
TEST(AppendTests, AppendMaintainsInsertionOrder)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 50; i++)
        arr.append(i);

    for (int i = 0; i < 50; i++)
        EXPECT_EQ(arr[i], i + 1);
}