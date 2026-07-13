# Build Log

---

## Entry 1

**Date:** July 13, 2026

**Duration:** 2 hours

**Goal:** Implement a proper hashing mechanism for user-defined data types.

**Problem Encountered:**

- My generic FNV-1a hash function worked correctly for primitive data types but failed when I tried to use user-defined classes as keys in the `HashMap`. I also discovered that `std::string` keys produced inconsistent hash values because the generic hash function was hashing the object's internal memory instead of its actual characters. I was also confused about whether the `HashMap` should define object comparison and hashing logic or whether that responsibility should belong to the user.

**What I Tried:**

- I studied how generic hash tables support custom data types and learned about recursive template functions. I implemented a reusable `hashCombine()` function that combines the hash values of multiple data members. I also added specialized hash functions for C-style strings so that the characters are hashed instead of the pointer addresses. Finally, I explored how users can create their own `hashValue()` function by combining the important fields of their custom classes.

**Outcome:**

- I learned that a generic `HashMap` should not decide how two custom objects are compared. Instead, the user must overload `operator==` and implement a corresponding `hashValue()` function using the same data members. This helped me understand how generic data structures remain reusable while allowing users to define comparison and hashing behavior for their own classes.

---

## Entry 2

**Date:** July 13, 2026

**Duration:** 1.5 hours

**Goal:** Improve the exception safety of `HashMap` and `DynamicArray`.

**Problem Encountered:**

- Since both data structures use `malloc()` and placement `new` for manual memory management, I found that exceptions during object construction could lead to memory leaks. I also noticed that `DynamicArray::resize()` could leave the array in an inconsistent state if copying elements failed before all new objects were constructed successfully.

**What I Tried:**

- I reviewed every allocation and object construction step and added proper `try-catch` blocks to release allocated memory whenever an exception occurred. I also modified the `resize()` function so that old elements are destroyed only after all new elements have been copied successfully, ensuring that the original array remains valid if an exception is thrown.

**Outcome:**

- The `HashMap` and `DynamicArray` became more robust against exceptions and memory leaks. I also gained a much better understanding of object lifetime, manual memory management, and why exception safety is important when working with `malloc()`, placement `new`, and explicit destructors.

---

## Entry 3

**Date:** July 13, 2026

**Duration:** 2 hours

**Goal:** Test and debug the `HashMap` implementation.

**Problem Encountered:**

- After completing the implementation, I created several test cases to verify insertion, retrieval, duplicate key updates, deletion, clearing the map, and other edge cases. While testing, I found that lookups using `std::string` keys failed even though the key had been inserted successfully. At first, I assumed there was a problem in my insertion or searching logic.

**What I Tried:**

- To identify the exact cause, I added debugging statements inside `put()` and `get()` to print the generated hash values and bucket indices. I compared the hash values generated during insertion and retrieval and traced the execution step by step until I found where the behavior started to differ.

**Outcome:**

- I discovered that the issue was caused by my generic hash function hashing the raw memory representation of `std::string` instead of its character sequence. This debugging process taught me the importance of validating intermediate values before assuming the entire implementation is incorrect. It also improved my debugging skills and reinforced the value of writing comprehensive test cases for both normal and edge-case scenarios.

---