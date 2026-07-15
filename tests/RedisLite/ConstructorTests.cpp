#include <gtest/gtest.h>
#include "RedisLite.h"

TEST(ConstructorTests, ConstructorCreatesObject)
{
    RedisCLI redis;

    SUCCEED();
}