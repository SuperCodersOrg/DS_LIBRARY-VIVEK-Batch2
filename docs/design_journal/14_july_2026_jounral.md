## Specific Issue

Today I worked on understanding Redis Lite as I dont know how Redis Lite works. I also had to learn how to use CMake and Google Test because I had never worked with them before. After setting up the testing environment, I wanted to verify my DynamicArray and LinkedList implementations by writing unit tests.

---

## Failed Attempt

I started by studying the basic architecture of Redis Lite. I created a memory diagram to understand how different components are organized. The diagram showed the difference between stack and heap memory, how the RedisCLI object contains the HashMap, how the HashMap manages the bucket array, and how each bucket stores a linked list of nodes.

Next, I learned how CMake and Google Test work. With the help of ChatGPT, I configured the project using CMake and integrated Google Test. After completing the setup, I successfully ran a sample test to verify that the testing environment was working correctly.

Finally, I wrote unit tests for my DynamicArray and LinkedList implementations. I created test cases for the important methods and checked different scenarios, including normal operations, boundary conditions, edge cases, and exception handling, to make sure the implementations behaved correctly.

---

## Code Reference

Today's work included:

- Studied the basic architecture of Redis Lite.
- Created a memory diagram to understand the project's memory flow.
- Learned and configured CMake for the project.
- Integrated Google Test into the project.
- Wrote unit tests for DynamicArray.
- Wrote unit tests for LinkedList.
- Verified normal operations, edge cases, and exception handling using the test suite.

---

## Learning Reflection

- Creating the memory diagram helped me understand how Redis Lite is organized and how different components interact with each other.
- I also learned the basics of CMake and Google Test. Setting up the build system and testing Code on test suites.
- Learned how test suites are used and many different test cases are run in one go on the place of running individually for each one.