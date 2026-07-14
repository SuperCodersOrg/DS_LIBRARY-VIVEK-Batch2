#include <gtest/gtest.h> 
#include "../../include/LinkedList.h"

TEST(ForEachTests, EmptyList)
{
    LinkedList<int> list;

    int sum = 0;

    list.forEach([&](int value)
    {
        sum += value;
    });

    EXPECT_EQ(sum, 0);
}

TEST(ForEachTests, SumElements)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    int sum = 0;

    list.forEach([&](int value)
    {
        sum += value;
    });

    EXPECT_EQ(sum, 60);
}

TEST(ForEachTests, ModifyElements)
{
    LinkedList<int> list;

    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);

    list.forEach([](int& value)
    {
        value *= 10;
    });

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}


TEST(ForEachTests, VisitEveryElement)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.insertBack(i);

    int count = 0;

    list.forEach([&](int)
    {
        count++;
    });

    EXPECT_EQ(count, 5);
}

TEST(ForEachTests, StringElements)
{
    LinkedList<std::string> list;

    list.insertBack("A");
    list.insertBack("B");
    list.insertBack("C");

    std::string result;

    list.forEach([&](const std::string& value)
    {
        result += value;
    });

    EXPECT_EQ(result, "ABC");
}

TEST(ForEachTests, TraversalOrder)
{
    LinkedList<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    std::vector<int> values;

    list.forEach([&](int value)
    {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 3);

    EXPECT_EQ(values[0], 10);
    EXPECT_EQ(values[1], 20);
    EXPECT_EQ(values[2], 30);
}