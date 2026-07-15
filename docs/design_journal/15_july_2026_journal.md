## Specific Issue

Today's goal was to complete the design and implementation of Redis Lite. Before writing the code, I needed a proper design proposal that clearly explained how the different components would work together. After the implementation, I also wanted to verify that all functionalities worked correctly by writing unit tests.

---

## Failed Attempt

I started by writing the design proposal for Redis Lite. I documented the overall architecture, the responsibilities of the main components, and how data flows through the system. This helped me create a clear plan before beginning the implementation.

Once the design was complete, I implemented the core functionality of Redis Lite. I connected the different components, including the command interface and the underlying HashMap, so that commands could store, retrieve, and manage data correctly. While implementing, I tested the program step by step to make sure each component worked as expected.

After completing the implementation, I wrote unit tests using Google Test. I created test cases for the main Redis Lite operations and verified that they produced the expected output. I also tested edge cases and invalid inputs to ensure the implementation handled different scenarios correctly.

---

## Code Reference

Today's work included:

- Wrote the design proposal for Redis Lite.
- Implemented the core functionality of Redis Lite.
- Connected the command interface with the underlying data structures.
- Wrote unit tests using Google Test.
- Tested normal operations, edge cases, and invalid inputs.
- Verified that the implementation worked correctly through the test suite.

---

## Learning Reflection

- Creating the memory diagram helped me understand how Redis Lite is organized and how different components interact with each other.
- I also learned the basics of CMake and Google Test. Setting up the build system and testing Code on test suites.
- Learned how test suites are used and many different test cases are run in one go on the place of running individually for each one.