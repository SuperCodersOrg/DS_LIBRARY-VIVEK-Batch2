#include <gtest/gtest.h>
#include <sstream>
#include "RedisLite.h"

// Exit command
TEST(RunTests, ExitCommand)
{
    RedisCLI redis;

    std::istringstream input("EXIT\n");
    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Goodbye!"), std::string::npos);
}

// Set then Get
TEST(RunTests, SetAndGet)
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

// Exists
TEST(RunTests, ExistsCommand)
{
    RedisCLI redis;

    std::istringstream input(
        "SET city Delhi\n"
        "EXISTS city\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("1"), std::string::npos);
}

// DEL
TEST(RunTests, DeleteCommand)
{
    RedisCLI redis;

    std::istringstream input(
        "SET age 21\n"
        "DEL age\n"
        "GET age\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("(nil)"), std::string::npos);
}

// Clear
TEST(RunTests, ClearCommand)
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

    EXPECT_NE(output.str().find("0"), std::string::npos);
}

// Unknown
TEST(RunTests, UnknownCommand)
{
    RedisCLI redis;

    std::istringstream input(
        "HELLO\n"
        "EXIT\n");

    std::ostringstream output;

    auto* cinbuf = std::cin.rdbuf(input.rdbuf());
    auto* coutbuf = std::cout.rdbuf(output.rdbuf());

    redis.run();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    EXPECT_NE(output.str().find("Unknown Command"), std::string::npos);
}