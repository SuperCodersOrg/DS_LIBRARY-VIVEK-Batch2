#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// delete existing key
TEST(RedisLiteDelTests, DeleteExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "DEL name\n"
        "GET name\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("1"), std::string::npos);
    EXPECT_NE(output.str().find("(nil)"), std::string::npos);
}

// delete non existing key 
TEST(RedisLiteDelTests, DeleteNonExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "DEL abc\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("0"), std::string::npos);
}

// missing argument
TEST(RedisLiteDelTests, MissingArgument)
{
    RedisCLI redis;

    std::istringstream input(
        "DEL\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"), std::string::npos);
}

// extra argument
TEST(RedisLiteDelTests, ExtraArguments)
{
    RedisCLI redis;

    std::istringstream input(
        "DEL a b\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"), std::string::npos);
}

// delete same key twice
TEST(RedisLiteDelTests, DeleteTwice)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "DEL a\n"
        "DEL a\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("1"), std::string::npos);
    EXPECT_NE(out.find("0"), std::string::npos);
}