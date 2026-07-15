#include <gtest/gtest.h>
#include <sstream>
#include "../../include/RedisLite.h"

// count empty
TEST(RedisLiteCountTests, EmptyStore)
{
    RedisCLI redis;

    std::istringstream input(
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("0"), std::string::npos);
}

// count after one set
TEST(RedisLiteCountTests, OneElement)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("1"), std::string::npos);
}

// count after multiple set
TEST(RedisLiteCountTests, MultipleElements)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "SET b 20\n"
        "SET c 30\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("3"), std::string::npos);
}

// count after delete
TEST(RedisLiteCountTests, AfterDelete)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "SET b 20\n"
        "DEL a\n"
        "COUNT\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("1"), std::string::npos);
}

// count after clear
TEST(RedisLiteCountTests, AfterClear)
{
    RedisCLI redis;

    std::istringstream input(
        "SET a 10\n"
        "SET b 20\n"
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