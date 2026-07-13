## Specific Issue

While implementing the `HashMap`, I had to design a generic hashing function that works for all primitive data types. I also faced challenges while implementing rehashing without causing memory leaks, understanding memory ownership between `HashMap` and `DynamicArray`, writing an efficient copy constructor and copy assignment operator, and understanding why both const and non-const versions of `get()` are needed.

---

## Failed Attempt

Initially, I wrote separate FNV-1a hash functions for each primitive data type such as `int` and `char`. This made the code repetitive and difficult to maintain. After learning how data is stored in memory, I replaced them with a single template function that hashes the raw bytes of any primitive type using `reinterpret_cast`.

While implementing rehashing, I first used `put()` to insert every element into the new bucket array. I also assumed that copying `DynamicArray<Node*>` would automatically free the old nodes. After reviewing the copy constructor and destructor of `DynamicArray` and tracing the lifetime of every allocated node, I realized that `DynamicArray` only manages the array of pointers, not the nodes themselves. I fixed the memory leak by moving the existing nodes into the new bucket array instead of creating new ones.

For the copy constructor and copy assignment operator, I initially copied all elements using `put()`. Although it worked correctly, it recalculated the hash value and performed unnecessary checks for every element. I improved the implementation by directly creating new nodes while copying, which made the copy process more efficient.

Finally, I thought having both const and non-const versions of `get()` was unnecessary. After studying STL containers, I understood that the const version only allows reading the stored value, while the non-const version allows modifying it. This makes the interface safer and follows standard C++ practices.

---

## Code Reference

Today's implementation included:

- Implemented a generic FNV-1a hash function using templates and `reinterpret_cast`.
- Implemented `rehash()` by moving existing nodes into a new bucket array.
- Implemented the `HashMap` copy constructor and copy assignment operator using direct node creation.
- Added both const and non-const versions of the `get()` function.
- Verified memory ownership between `HashMap` and `DynamicArray`.

---

## Learning Reflection

Today I learned how the FNV-1a hash function works by processing data one byte at a time and how `reinterpret_cast` can be used to access the raw bytes of primitive data types. I also gained a better understanding of memory ownership in pointer-based containers and learned that `DynamicArray<Node*>` only manages the pointer array, while the `HashMap` is responsible for creating and deleting the actual nodes.

Another important lesson was that directly copying nodes is more efficient than reinserting them using `put()`, because it avoids unnecessary hashing and lookups. Finally, I learned why providing both const and non-const versions of `get()` is important for writing safer and more standard C++ code.