#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// valid set
TEST(RedisLiteSetTests, ValidSet)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "GET name\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("OK"), std::string::npos);
    EXPECT_NE(output.str().find("Vivek"), std::string::npos);
}

// update existing key
TEST(RedisLiteSetTests, UpdateExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "SET age 20\n"
        "SET age 21\n"
        "GET age\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("21"),std::string::npos);
}

// missing value
TEST(RedisLiteSetTests, MissingValue)
{
    RedisCLI redis;

    std::istringstream input(
        "SET age\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"),std::string::npos);
}

// extra arguments
TEST(RedisLiteSetTests, ExtraArguments)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a b c\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"),std::string::npos);
}

// lowercase command
TEST(RedisLiteSetTests, LowerCaseSet)
{
    RedisCLI redis;

    std::istringstream input(
        "set city Delhi\n"
        "get city\n"
        "exit\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Delhi"),std::string::npos);
}