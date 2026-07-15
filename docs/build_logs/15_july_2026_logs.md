# Build Log

---

## Entry 1

**Date:** July 15, 2026

**Duration:** 2 hours

**Goal:** Write the design proposal for Redis Lite.

**Problem Encountered:**

- Before starting the implementation, I need to decide what methods will be recquired for implementation of Redis Lite and how Redis Lite would work. I had already understood the basic architecture, but I needed to organize the design into a proper proposal so that the implementation would follow a well-defined structure.

**What I Tried:**

- I prepared a design proposal describing the overall architecture of Redis Lite. I documented the main components, their responsibilities, Which methods will be supported, and how different data structures interact with each other. I also included the memory organization and memory diagram.

**Outcome:**

- The design proposal gave a clear roadmap for implementation.
---

## Entry 2

**Date:** July 15, 2026

**Duration:** 2.5 hours

**Goal:** Implement the Redis Lite functionality.

**Problem Encountered:**

- After completing the design, I started the Implementation. While implementing Redis Lite, I had to make sure different components such as the command interface, HashMap, and underlying data structures worked together correctly without breaking the overall design

**What I Tried:**

- I implemented the core functionality of Redis Lite according to the design proposal. I connected the different components so that commands could access and modify data through the HashMap.

**Outcome:**

- I successfully completed the implementation of Redis Lite. The main components now work together correctly.

---

## Entry 3

**Date:** July 15, 2026

**Duration:** 2 hours

**Goal:** Write unit test cases for Redis Lite.

**Problem Encountered:**

- After implementing Redis Lite, I wanted to verify that all commands and functionalities worked correctly. 

**What I Tried:**

- I wrote unit test cases using Google Test to verify the Redis Lite implementation. The tests covered different commands and common operations, including normal use cases, invalid inputs, and edge cases. After writing the tests, I executed the test suite and checked that the results matched the expected behavior.

**Outcome:**

- I wrote approx 6 test cases for each method in Dyanmic Array and Similarly in Linked List. 
- Also checked all methods on many edge cases and exceptions to know my code is handling exceptions or not.

---