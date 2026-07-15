#include <gtest/gtest.h>
#include "../../include/HashMap1.h"

TEST(HashMapCopyConstructorTests, CopyEmptyMap)
{
    HashMap<int, int> original;

    HashMap<int, int> copy(original);

    EXPECT_TRUE(copy.empty());
    EXPECT_EQ(copy.size(), 0);
}

TEST(HashMapCopyConstructorTests, CopySingleElement)
{
    HashMap<int, int> original;

    original.put(1, 100);

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.size(), 1);
    EXPECT_TRUE(copy.contains(1));
    EXPECT_EQ(copy.get(1), 100);
}

TEST(HashMapCopyConstructorTests, CopyMultipleElements)
{
    HashMap<int, int> original;

    for (int i = 0; i < 10; i++)
        original.put(i, i * 10);

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.size(), original.size());

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(copy.get(i), i * 10);
}

TEST(HashMapCopyConstructorTests, OriginalModificationDoesNotAffectCopy)
{
    HashMap<int, int> original;

    original.put(1, 100);

    HashMap<int, int> copy(original);

    original.put(1, 500);

    EXPECT_EQ(copy.get(1), 100);
    EXPECT_EQ(original.get(1), 500);
}

TEST(HashMapCopyConstructorTests, CopyModificationDoesNotAffectOriginal)
{
    HashMap<int, int> original;

    original.put(1, 100);

    HashMap<int, int> copy(original);

    copy.put(1, 999);

    EXPECT_EQ(original.get(1), 100);
    EXPECT_EQ(copy.get(1), 999);
}

TEST(HashMapCopyConstructorTests, CopyStringMap)
{
    HashMap<std::string, std::string> original;

    original.put("Apple", "Red");
    original.put("Banana", "Yellow");

    HashMap<std::string, std::string> copy(original);

    EXPECT_EQ(copy.size(), 2);
    EXPECT_EQ(copy.get("Apple"), "Red");
    EXPECT_EQ(copy.get("Banana"), "Yellow");
}