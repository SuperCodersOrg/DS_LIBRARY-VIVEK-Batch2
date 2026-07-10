# Build Log

---

## Entry 1

**Date:** July 9, 2026

**Duration:** 1 hour

**Goal:** Write implementation of Dynamic Array.

**Problem Encountered:**

- I had no idea how and why header guards are used.

**What I Tried:**

- Researched the internal structure of .h file and Learned about #ifndef, #define, and #endif and why they are used.

**Outcome:**
- Understood that the .h file contains the class declaration, data members, function declarations, required #include statements, and header guards.
- Learned that #ifndef, #define, and #endif are header guards that stop the same header file from being included more than once.

---

## Entry 2

**Date:** July 9, 2026

**Duration:** 1.5 hour

**Goal:** Implement pop(index) and remove(value) functions in Dynamic array.

**Problem Encountered:**

- While implmenting pop(index) and remove() by value, I was confused about which object's destructor should be called after shifting elements. Initially, I thought every shifted object should be destroyed.

**What I Tried:**

- Studied object lifetime during assignment and Dry ran deletion using small examples.

**Outcome:**

- Learned that assignment only overwrites object values. Only the last object's lifetime ends after shifting, so only its destructor should be called on the place of calling each object's desttructor.

---

## Entry 3

**Date:** July 9, 2026

**Duration:** 1.5 hour

**Goal:** Implementation of Linked List.

**Problem Encountered:**

- I was writing the logic to delete all nodes directly inside the destructor. The same logic could be needed in other functions, but it was not reusable.

**What I Tried:**

- Created a reusable `deleteFront()` function to delete one node at a time. Updated the destructor to repeatedly call `deleteFront()` until the list became empty.


**Before**

```cpp
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = head;

    while(current != nullptr)
    {
        Node* nextNode = current->next;

        current->data.~T();
        std::free(current);

        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
}
```

**After**

```cpp
template<typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        deleteFront();
    }
}
```


**Outcome:**

- It makes the deletion logic reusable and it also makes destructor function simple. Removed duplicate deletion logic from the destructor. Reused the `deleteFront()` function for memory cleanup. 

---