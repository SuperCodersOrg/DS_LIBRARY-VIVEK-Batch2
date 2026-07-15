#include "../../include/RedisLite.h"


int main()
{
    RedisCLI redis;

    redis.run();

    return 0;
}

// Commands to run Redis Lite
// g++ src/RedisLite/Main.cpp src/RedisLite/RedisLite.cpp -o Main
// ./Main