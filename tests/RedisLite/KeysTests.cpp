#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// keys on empty
TEST(RedisLiteKeysTests, EmptyStore)
{
    RedisCLI redis;

    std::istringstream input(
        "KEYS\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("(empty)"), std::string::npos);
}


// single key
TEST(RedisLiteKeysTests, SingleKey)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "KEYS\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("name"), std::string::npos);
}

// multiple key
TEST(RedisLiteKeysTests, MultipleKeys)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "SET city Delhi\n"
        "SET age 21\n"
        "KEYS\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("name"), std::string::npos);
    EXPECT_NE(out.find("city"), std::string::npos);
    EXPECT_NE(out.find("age"), std::string::npos);
}

// keys after delete
TEST(RedisLiteKeysTests, AfterDelete)
{
    RedisCLI redis;

    std::istringstream input(
        "SET apple 10\n"
        "SET banana 20\n"
        "DEL apple\n"
        "KEYS\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    // Deleted key should not appear
    EXPECT_EQ(out.find("apple"), std::string::npos);

    // Remaining key should appear
    EXPECT_NE(out.find("banana"), std::string::npos);
}

// keys after clear
TEST(RedisLiteKeysTests, AfterClear)
{
    RedisCLI redis;

    std::istringstream input(
        "SET x 1\n"
        "SET y 2\n"
        "CLEAR\n"
        "KEYS\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("(empty)"), std::string::npos);
}