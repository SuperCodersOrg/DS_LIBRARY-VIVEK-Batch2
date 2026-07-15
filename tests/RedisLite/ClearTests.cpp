#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// clear empty
TEST(RedisLiteClearTests, ClearEmptyStore)
{
    RedisCLI redis;

    std::istringstream input(
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("OK"), std::string::npos);
    EXPECT_NE(out.rfind("0"), std::string::npos);
}

// clear after one element
TEST(RedisLiteClearTests, ClearSingleElement)
{
    RedisCLI redis;

    std::istringstream input(
        "SET name Vivek\n"
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("OK"), std::string::npos);
    EXPECT_NE(out.rfind("0"), std::string::npos);
}

// clear multiple elements
TEST(RedisLiteClearTests, ClearMultipleElements)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "SET b 20\n"
        "SET c 30\n"
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("OK"), std::string::npos);
    EXPECT_NE(out.rfind("0"), std::string::npos);
}

// clear Twice
TEST(RedisLiteClearTests, ClearTwice)
{
    RedisCLI redis;

    std::istringstream input(
        "SET x 100\n"
        "CLEAR\n"
        "CLEAR\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("OK"), std::string::npos);
    EXPECT_NE(out.rfind("0"), std::string::npos);
}

// Insert after clear
TEST(RedisLiteClearTests, InsertAfterClear)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "CLEAR\n"
        "SET b 20\n"
        "GET b\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string out = output.str();

    EXPECT_NE(out.find("20"), std::string::npos);
    EXPECT_NE(out.rfind("1"), std::string::npos);
}