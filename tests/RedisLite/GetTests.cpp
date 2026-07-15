#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

TEST(RedisLiteGetTests, ExistingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "GET a\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("10"),std::string::npos);
}

TEST(RedisLiteGetTests, MissingKey)
{
    RedisCLI redis;

    std::istringstream input(
        "GET abc\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("(nil)"),std::string::npos);
}

TEST(RedisLiteGetTests, MissingArgument)
{
    RedisCLI redis;

    std::istringstream input(
        "GET\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"),std::string::npos);
}

TEST(RedisLiteGetTests, ExtraArgument)
{
    RedisCLI redis;

    std::istringstream input(
        "GET a b\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Usage"),std::string::npos);
}

TEST(RedisLiteGetTests, GetAfterUpdate)
{
    RedisCLI redis;

    std::istringstream input(
        "SET x 1\n"
        "SET x 5\n"
        "GET x\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf=std::cin.rdbuf(input.rdbuf());
    auto* coutbuf=std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("5"),std::string::npos);
}

