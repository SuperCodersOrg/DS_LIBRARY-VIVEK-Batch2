## Specific Issue

Today's main challenge was extending the hashing mechanism so that the `HashMap` can also support user-defined data types. Another issue was improving exception safety in both `HashMap` and `DynamicArray` because they use `malloc()` and placement `new`. During testing, I also found that lookups using `std::string` keys were failing even though insertion was working correctly.

---

## Failed Attempt

At first, I expected my generic FNV-1a hash function to work for every type. However, it only worked correctly for primitive types. When I tested it with `std::string`, the generated hash values were different for insertion and lookup because I was hashing the object's internal memory instead of its characters.

I also wasn't sure whether the `HashMap` itself should know how to compare and hash user-defined objects. After reading about generic hash tables, I understood that comparison and hashing should be provided by the user through `operator==` and `hashValue()`.

While reviewing exception safety, I noticed that if object construction failed during `DynamicArray::resize()`, the newly allocated memory would not be released. I updated the implementation so that partially constructed objects are destroyed and allocated memory is freed before the exception is rethrown. The original array is only destroyed after all new objects are copied successfully.

During testing, I first thought there was a bug in `put()` or `get()`. After printing the generated hash values and bucket indices for both insertion and lookup, I found that the real problem was the hashing logic for `std::string`.

---

## Code Reference

Today's work included:

- Implemented hashing support for user-defined data types using `hashCombine()`.
- Added specialized hashing for C-style strings.
- Improved exception safety in `HashMap` and `DynamicArray`.
- Updated `DynamicArray::resize()` to correctly handle exceptions during copying.
- Wrote test cases for insertion, lookup, duplicate keys, deletion, clearing the map, and other edge cases.
- Fixed incorrect hashing for `std::string` keys.

---

## Learning Reflection

Today I understood why a generic `HashMap` should not decide how custom objects are compared or hashed. The user should provide `operator==` and `hashValue()` so the container can work with any user-defined type.

I also learned that exception safety becomes very important when working with `malloc()`, placement `new`, and explicit destructor calls. If object construction fails, every allocated resource must be cleaned up properly to avoid memory leaks.

Another useful lesson came from debugging. Instead of changing the whole implementation, checking intermediate values like hash values and bucket indices helped me find the actual problem much faster.