# Build Log

---

## Entry 1

**Date:** July 6, 2026

**Duration:** 1 hour 30 minutes

**Goal:**


<!-- Understand the project requirements and design the overall structure of the DynamicArray. -->
Understanding project requirements and designing the overall structure of the DynamicArray.


**Problem Encountered:**
Deciding which operations should be included in the public API while keeping the interface simple and easy to remember and less confusing functions.

**What I Tried:**
- Read the project requirements carefully.
- Compared common DynamicArray operations with Python list methods.
- Selected only the most useful functions for the first implementation.

**Outcome:**
Prepared the complete list of public methods including constructor, append(), pop(), remove(), insert(), size(), capacity(), clear(), and destructor.

---

## Entry 2

**Date:** July 6, 2026

**Duration:** 1 hour

**Goal:**
Design the internal representation of the DynamicArray.

**Problem Encountered:**
Choosing the data members required for efficient implementation.

**What I Tried:**
- Studied how dynamic arrays are implemented.
- Compared storing elements in contiguous memory with linked list storage.
- Identified the minimum data members needed.

**Outcome:**
Finalized the internal structure using:
- `T* data`
- `size_t size`
- `size_t capacity`

<!-- Also decided to keep these members private for encapsulation. -->
DEcided to keep these members private for encapsulation, so that users can only access public functions and can't change private members.

---

## Entry 3

**Date:** July 6, 2026

**Duration:** 45 minutes

**Goal:**
Decide how memory resizing should work.

**Problem Encountered:**
Choosing an appropriate capacity growth strategy.

**What I Tried:**
- Compared increasing capacity by 1, 1.5×, 1.8×, and 2×.
- Considered both memory usage and number of reallocations.

**Outcome:**
Selected the doubling strategy (`capacity *= 2`) because it minimizes resizing operations and provides amortized O(1) append performance.
we can also choose 1.5x or 1.8x to reduce the unused space in the allocated memory but it will increase no of resizes. Whereas 2x factor reduces no of resizes but increase unused memory space.

---

## Entry 4

**Date:** July 6, 2026

**Duration:** 40 minutes

**Goal:**
Estimate the time complexity of each operation.

**Problem Encountered:**
Understanding why append() has amortized O(1) complexity instead of O(n).

**What I Tried:**
- Analyzed the resizing process.
- Counted insertion and copy operations over multiple appends.
- Calculated the average cost per insertion.

**Outcome:**

Prepared the complexity table and documented the amortized analysis of append(). 

Also analyzed TC of pop() and pop(index) and remove(value).

---

## Entry 5

**Date:** July 6, 2026

**Duration:** 35 minutes

**Goal:**
Identify important design decisions for the implementation.

**Problem Encountered:**
To provide random access and updation at any index we cant use linked list. Shallow copy and Double deletion in copying an object. Class supporting only the data type it was assigned in the class.

**What I Tried:**
- Compared contiguous memory with linked lists.
- Compared deep copy with shallow copy.
- Studied the Rule of Three and template-based programming.

**Outcome:**
Documented the major design decisions:
- Contiguous memory will be used so that we can easily access and upadte value by index by using memory address in O(1).
- Capacity doubling will be done in resizing on the place of 1x or 4x or 1.5x.
- Template-based implementation will be used here so that it can support different data tpyes like char, int, float.
- Deep copy using the Rule of Three to allocate different unique memory address to new object on the place of assigning same address of previous object in shallow copy.

---
<!-- 
## Entry 6

**Date:** July 6, 2026

**Duration:** 30 minutes

**Goal:**
Prepare the complete design proposal for submission.

**Problem Encountered:**
Ensuring every required section matched the assignment specification.

**What I Tried:**
- Reviewed each section against the project instructions.
- Verified the API, internal representation, complexity estimates, and design decisions.
- Added explanations wherever necessary.

**Outcome:**
Completed the design proposal and prepared it for implementation approval. -->
