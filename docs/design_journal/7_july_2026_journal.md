## Section 1 – Specific Issue

malloc() was only allocating memory but not calling constructor and also same for destructor. 

---

## Section 2 – Failed Attempt

Initially, I considered using a Doubly Linked List, but since the required API does not need backward traversal, I switched to a Singly Linked List to reduce memory usage and implementation complexity.

I also considered maintaining only a `head` pointer, but later added a `tail` pointer to support efficient future extensions such as insertion at the end.

---

## Section 3 – Memory Diagram

<img width="1748" height="899" alt="image" src="https://github.com/user-attachments/assets/fa0d75cb-107f-4b0f-85d8-1b7c62c65039" />

---

## Section 4 – Code Reference

- No implementation code was written today.
- The work focused on completing the Linked List design proposal, including the API, internal representation, Rule of Three, complexity analysis, and design decisions.

---

## Section 5 – Learning Reflection

Today I learned how templates make a data structure reusable for both primitive and user-defined types. I also learned that `malloc()` only allocates raw memory and does not call constructors, so placement `new` is required for object construction, while destructors must be called explicitly before `free()`. Additionally, I understood why a Singly Linked List is sufficient for the current requirements and how maintaining `head`, `tail`, and `count` improves efficiency and future extensibility.