# Build Log

---

## Entry 1

**Date:** July 10, 2026

**Duration:** 2 hours

**Goal:** Implement FNV-1a hash function for primitive data types.

**Problem Encountered:**

- At first, I wrote separate hash functions for each primitive data type like `int`, `char`, etc. This would have made the code repetitive and difficult to maintain.
- I was also confused about why `reinterpret_cast` was needed and how an integer could be treated as a sequence of bytes.

**What I Tried:**

- Learned how data is stored in memory and studied how `reinterpret_cast` changes the way memory is viewed without changing the actual data.
- Replaced the separate hash functions with a single template function that works for all primitive data types.

**Outcome:**

- Learned that one template function can hash all primitive data types by reading their bytes.
- Understood that the FNV-1a hash function processes one byte at a time instead of the whole value.
- Learned that `reinterpret_cast<const unsigned char*>` lets me access the raw bytes of any primitive type, making the hash function generic and reusable.

---

## Entry 2

**Date:** July 10, 2026

**Duration:** 2.5 hours

**Goal:** Implement rehashing in the HashMap.

**Problem Encountered:**

- At first, I used `put()` to insert every element again during rehashing. I thought copying the bucket array into another `DynamicArray<Node*>` would automatically free the old nodes.

**What I Tried:**

- Reviewed the copy constructor and destructor of my `DynamicArray`.
- Traced every allocated node step by step to see when its memory was actually freed.

**Outcome:**

- Learned that `DynamicArray<Node*>` only manages the array of pointers, not the nodes they point to.
- Found a memory leak because the old nodes were never deleted.
- Fixed the problem by moving the existing nodes into the new bucket array instead of creating new ones.

---

## Entry 3

**Date:** July 10, 2026

**Duration:** 1.5 hours

**Goal:** Implement the copy constructor and copy assignment operator for the HashMap.

**Problem Encountered:**

- My first implementation copied all elements using `put()`. Although it worked, it performed extra hashing and unnecessary checks for every element.

**What I Tried:**

- Studied how deep copying is usually done for linked data structures.
- Implemented direct node creation while copying.

**Outcome:**

- Learned that copying data directly is faster than inserting it again through `put()`.
- Improved the performance of both the copy constructor and assignment operator.

---

## Entry 4

**Date:** July 10, 2026

**Duration:** 1 hour

**Goal:** Understand memory ownership in `HashMap` and `DynamicArray`.

**Problem Encountered:**

- I was confused about whether my `DynamicArray` copy constructor was doing a deep copy or a shallow copy when storing `Node*`.

**What I Tried:**

- Reviewed how templates work with pointer types.
- Compared my implementation with the behavior of `std::vector<Node*>`.

**Outcome:**

- Learned that `DynamicArray` makes a deep copy of the pointer array, but it only copies the pointer values, not the actual objects.
- Understood that the `HashMap` is responsible for creating and deleting all nodes.

---

## Entry 5

**Date:** July 10, 2026

**Duration:** 45 minutes

**Goal:** Understand why `get()` has two versions.

**Problem Encountered:**

- I thought writing both the const and non-const versions of `get()` was unnecessary.

**What I Tried:**

- Studied how STL containers like `std::vector` provide separate functions for const and non-const objects.

**Outcome:**

- Learned that the non-const version allows modifying the value, while the const version only allows reading it.
- Understood how const overloading helps make the class safer and follows standard C++ practices.

---