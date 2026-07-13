## Specific Issue

The main issues today were understanding how C++ header guards work, managing object destruction correctly while implementing `pop(index)` and `remove(value)` in the Dynamic Array, and improving the Linked List destructor to avoid writing the same deletion logic twice.

---

## Failed Attempt

At first, I was not sure why header guards (`#ifndef`, `#define`, and `#endif`) were needed. After learning about the structure of C++ header files, I understood that they prevent the same header file from being included multiple times during compilation.

While implementing `pop(index)` and `remove(value)` in the Dynamic Array, I initially thought that every object moved during shifting should have its destructor called. After studying object lifetime and doing a few dry runs, I realized that assignment only copies values into existing objects. Only the last object, whose lifetime actually ends after shifting, needs its destructor to be called.

For the Linked List, I first wrote all the node deletion logic directly inside the destructor. Although it worked, the same logic could be useful in other functions. So, I moved the deletion code into a reusable `deleteFront()` function and updated the destructor to repeatedly call it until the list became empty.

---

## Code Reference

Today's implementation included:

- Added header guards (`#ifndef`, `#define`, and `#endif`) to header files.
- Implemented `pop(index)` and `remove(value)` for the Dynamic Array with correct object lifetime management.
- Refactored the Linked List destructor to use the reusable `deleteFront()` function instead of duplicating the deletion logic.

---

## Learning Reflection

Today I learned how C++ header guards prevent multiple inclusion of the same header file during compilation. I also understood how object lifetime works when removing elements from a manually managed Dynamic Array, and why only the last removed object needs its destructor to be called. Finally, I learned that moving repeated code into a reusable function, like `deleteFront()`, makes the code cleaner, easier to maintain, and easier to reuse.