## Section 1 – Specific Issue

The main issue was choosing a hash function as I have to choose a hash function which also works for user defined functions. Another issue was choosing between linear probing and separate chaining for collision handling.

---

## Section 2 – Failed Attempt

Initially, I considered using linear probing for collision resolution, but as the number of stored keys increases, clustering degrades insertion and lookup performance. Therefore, I switched to Separate Chaining using singly linked lists.

I also considered using a fixed-size bucket array, but this would lead to more collisions as the HashMap grows. Instead, I chose a dynamically resizable bucket array with rehashing based on a maximum load factor of **0.75** to maintain efficient average-case performance. 

I considered using memory address for creating hash value of user defined data functions but the memory address change each time when program restarts.

---

## Section 3 – Memory Diagram

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/ba9e64c7-9307-4b26-92e3-a613965d8939" />

---

## Section 4 – Code Reference

- No implementation code was written today.
- The work focused on completing the HashMap design proposal, including the public API, internal representation, hashing strategy, collision handling, memory management, complexity analysis, and design decisions.

---

## Section 5 – Learning Reflection

Today I learned how a HashMap organizes data using buckets and resolves collisions through Separate Chaining. I also understood how generic hashing can support primitive types, strings, and user-defined classes using templates and variadic hash combination. Additionally, I also learn about manual memory management with `malloc()`, placement `new`, explicit destructor calls, and `free()`, along with why maintaining a suitable load factor improves the average-case performance of HashMap operations.