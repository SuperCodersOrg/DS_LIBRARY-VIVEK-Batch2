#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// existing key
TEST(RedisLiteExistsTests, ExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "EXISTS name\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("1"), std::string::npos);
}

// non existing key
TEST(RedisLiteExistsTests, NonExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "EXISTS abc\n"
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
TEST(RedisLiteExistsTests, MissingArgument)
{
    RedisCLI redis;

    std::istringstream input(
        "EXISTS\n"
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
TEST(RedisLiteExistsTests, ExtraArguments)
{
    RedisCLI redis;

    std::istringstream input(
        "EXISTS a b\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"), std::string::npos);
}

// exist after delete
TEST(RedisLiteExistsTests, ExistsAfterDelete)
{
    RedisCLI redis;

    std::istringstream input(
        "SET city Delhi\n"
        "DEL city\n"
        "EXISTS city\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("1"), std::string::npos);   // DEL success
    EXPECT_NE(out.rfind("0"), std::string::npos);  // EXISTS returns 0
}