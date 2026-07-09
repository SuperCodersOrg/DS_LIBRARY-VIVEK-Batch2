# Build Log

---

## Entry 1

**Date:** July 8, 2026

**Duration:** 1.5 hour

**Problem Encountered:**

Inserting keys with same hash value overwrite the previous key value pair.

**What I Tried:**

- I tried Linear Probing method to insert hash value of keys on the basis of next empty slot in the hash table.
- Also tried Separate chaining method to insert hash value of keys on the same slot as nodes of single linked list.

**Outcome:**
- Choosing linear probing increases insertion, searching and lookup TC = O(n).
- Decided to use **Separate Chaining** with singly linked lists because it simplifies insertion and deletion while allowing buckets to grow independently.

---

## Entry 2

**Date:** July 8, 2026

**Duration:** 1.5 hour

**Goal:**

Design a generic hashing framework for different key types.

**Problem Encountered:**

The HashMap needed to support primitive data types, strings, and user-defined classes using a common hashing mechanism.

**What I Tried:**

- Tried hashing by taking memory address of user defined function.
- Studied specialized hashing functions for primitive data types.
- Studied about the polynomial rolling hash for strings.
- Explored variadic templates to combine hash values of multiple data members. And recursive hashing for user-defined objects.

**Outcome:**
- Decided to use specialized hash function for primitive data types and polynomial rolling hashing for strings, and using recursive hashing and variadic templates for user defined functions.
- Using memory address in hash function gives each time different hash value as memory address change everytime program restarts.
---

## Entry 3

**Date:** July 8, 2026

**Duration:** 45 minutes

**Goal:**

Decide how HashMap nodes should be allocated and released from memory.

**Problem Encountered:**

Using `malloc()` only allocates raw memory and does not invoke constructors, while `free()` does not invoke destructors.

**What I Tried:**

- Studied Placement New for object construction.
- Learned explicit destructor invocation before deallocation.

**Outcome:**

- Decided to Allocate nodes using `malloc()`, Construct the key and value using Placement New. Explicitly call the destructors of both objects before using `free()`. This ensures correct handling of primitive and user-defined data types.

---

## Entry 4

**Date:** July 8, 2026

**Duration:** 40 minutes

**Goal:**

Determine an appropriate load factor and resizing strategy.

**Problem Encountered:**

Choosing a load factor that minimizes collisions without causing excessive memory usage.

**What I Tried:**

- Compared different load factor thresholds such as 0.75, 1.5, and 2.0.
- Analyzed how increasing the load factor affects collision frequency.
- Studied the rehashing process used in standard hash table implementations.

**Outcome:**

- Selects maximum Load Factor = **0.75** , as it maintains average case O(1) TC for insertion, lookup and deletion.
- Rehashing doubles the bucket count whenever the load factor exceeds the threshold (0.75).
- When we choose load factor as 1.5 or 2 the collision frequency increases and the overall lookup, insertion, and deletion TC becomes O(n).

---