# Build Log

---

## Entry 1

**Date:** July 7, 2026

**Duration:** 1 hour

**Goal:**

Design the internal representation of the LinkedList.

**Problem Encountered:**

what to choose in between single linked list and doubly linked list.

**What I Tried:**

- Studied the implementation of singly and doubly linked lists.
- Compared maintaining only a head pointer versus maintaining both head and tail.
- Considered the cost of computing the list size by traversal.

**Outcome:**

Finalized the internal structure using:
- `Node* head`
- `Node* tail`
- `size_t count`

Also decided to keep these members private for encapsulation so users cannot directly modify the internal structure.

---

## Entry 2

**Date:** July 7, 2026

**Duration:** 50 minutes

**Goal:**

Decide how nodes should be allocated and released from memory.

**Problem Encountered:**

Using `malloc()` with template classes only allocating memory, it was not calling constructor and `free()` with template classes only deallocating memory but not calling destructor.

**What I Tried:**

- Studied how `malloc()` allocates only raw memory.
- Learned how placement `new` constructs an object in allocated memory.
- Studied explicit destructor calls before using `free()`.

**Outcome:**

Decided to:
- Allocate memory using `malloc()`.
- Construct nodes using placement `new`.
- Explicitly invoke the `Node` destructor before calling `free()`.

This ensures correct behavior for both primitive and non-primitive data types.

---

## Entry 3

**Date:** July 7, 2026

**Duration:** 45 minutes

**Goal:**

Analyze the time complexity of each LinkedList operation.

**Problem Encountered:**

Accessing and inserting on last element take O(n) TC.

**What I Tried:**

- Used `Tail` pointer which stores the address of last node in linked list.

**Outcome:**

Also Prepared the complexity table of all operations of Linked list:
- `insertFront()` — O(1)
- `deleteFront()` — O(1)
- `insert(index)` — O(n) and O(1) in case of front and end.
- `search()` — O(n)
- `size()` — O(1)
- `print()` — O(n)

---

