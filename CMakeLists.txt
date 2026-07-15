cmake_minimum_required(VERSION 3.16)

cmake_policy(SET CMP0135 NEW)

project(DS_LIBRARY)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

add_executable(runTests

    tests/DynamicArray/ConstructorTests.cpp
    tests/DynamicArray/AppendTests.cpp
    tests/DynamicArray/PopTests.cpp
    tests/DynamicArray/Pop_At_IndexTests.cpp
    tests/DynamicArray/Remove_Value_Tests.cpp
    tests/DynamicArray/Operator_Brackets_Tests.cpp
    tests/DynamicArray/Clear_Tests.cpp
    tests/DynamicArray/Size_Tests.cpp
    tests/DynamicArray/Capacity_Tests.cpp
    tests/DynamicArray/CopyConstructor.cpp
    tests/DynamicArray/CopyAssignmentTests.cpp

    tests/LinkedList/InsertFrontTests.cpp
    tests/LinkedList/DeleteFrontTests.cpp
    tests/LinkedList/SearchTests.cpp
    tests/LinkedList/SizeTests.cpp
    tests/LinkedList/FindTests.cpp
    tests/LinkedList/RemoveTests.cpp
    tests/LinkedList/ForEachTests.cpp
    tests/LinkedList/ClearTests.cpp
    tests/LinkedList/Empty_Tests.cpp
    tests/LinkedList/InsertBackTests.cpp
    tests/LinkedList/Constructor_Tests.cpp
    tests/LinkedList/CopyConstructorTests.cpp
    tests/LinkedList/CopyAssignmentTests.cpp

    tests/HashMap/ConstructorTests.cpp
    tests/HashMap/PutTests.cpp
    tests/HashMap/GetTests.cpp
    tests/HashMap/ContainsTests.cpp
    tests/HashMap/RemoveTests.cpp
    tests/HashMap/ClearTests.cpp
    tests/HashMap/SizeTests.cpp
    tests/HashMap/EmptyTests.cpp
    tests/HashMap/CopyConstructorTests.cpp
    tests/HashMap/AssignmentTests.cpp

    src/RedisLite/RedisLite.cpp
    tests/RedisLite/ConstructorTests.cpp
    tests/RedisLite/RunTests.cpp
    tests/RedisLite/SetTests.cpp
    tests/RedisLite/GetTests.cpp
    tests/RedisLite/DelTests.cpp
    tests/RedisLite/ExistsTests.cpp
    tests/RedisLite/CountTests.cpp
    tests/RedisLite/ClearTests.cpp
    tests/RedisLite/KeysTests.cpp

)

target_include_directories(runTests PRIVATE include)

target_link_libraries(runTests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runTests)