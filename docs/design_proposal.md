# Design Proposal for Dynamic Array

## Dynamic Array -
The DynamicArray stores its elements in a contiguous block of heap memory that is managed manually. Memory is allocated whenever the capacity needs to increase and is released when the DynamicArray object is destroyed. During resizing, a new memory block is created and all existing elements are copied into it before the old memory is deallocated.

Appending elements provides amortized O(1) time complexity because the array grows by doubling its capacity. Since resizing occurs only when the capacity reaches powers of two, inserting n elements requires n insertion operations and (n − 1) copy operations during all resizes, resulting in a total of 2n − 1 operations. Dividing this by n gives an average of about 2 operations per insertion, which is considered O(1) amortized time complexity.

## Section 1 – Public API

The following functions can be used by the user to interact with the `DynamicArray`.

### i) Constructor
**Purpose:** Initializes the dynamic array by setting the initial values of `data`, `size`, and `capacity`.

- **Parameters:** None
- **Return Type:** None

---

### ii) `append(T value)`
**Purpose:** Adds a new element at the end of the dynamic array.

- **Input Parameter:** Value to be inserted
- **Return Type:** `void`

---

### iii) `pop()`
**Purpose:** Removes and returns the last element of the array.

- **Input Parameter:** None
- **Return Type:** `T`

**Possible Error:** If the array is empty, no operation is performed.

---

### iv) `pop(size_t index)`
**Purpose:** Removes and returns the element at the given index.

- **Input Parameter:** Index
- **Return Type:** `T`

**Possible Error:** If the index is invalid, an out-of-range error is generated.

---

### v) `remove(T value)`
**Purpose:** Removes the first occurrence of the given value.

- **Input Parameter:** Value
- **Return Type:** `void`

**Possible Error:** If the value does not exist, a `value_not_exist` error is generated.

---

### vi) `insert(size_t index, T value)`
**Purpose:** Inserts a new element at the specified index.

- **Input Parameters:** Index, Value
- **Return Type:** `void`

---

### vii) `size()`
**Purpose:** Returns the current number of elements stored in the array.

- **Return Type:** `size_t`

---

### viii) `capacity()`
**Purpose:** Returns the total allocated capacity of the array.

- **Return Type:** `size_t`

---

### ix) `resize()`
**Purpose:** Increases the capacity when `size == capacity`.

- **Return Type:** `void`

**Note:** Internal helper function.

---

### x) `clear()` 
**Purpose:** Removes all elements from the array.

---


### xi) Destructor
**Purpose:** Releases dynamically allocated memory to prevent memory leaks.

---

# Section 2 – Internal Representation

## Template

The class uses templates so it can store any data type (`int`, `char`, `float`, `double`, etc.). Without templates, separate classes would be needed for each data type.

## Internal Structure

```cpp
template<typename T>
class DynamicArray
{
private:
    T* data;
    size_t size;
    size_t capacity;
};
```

The data members are private to provide encapsulation. Users interact with the array only through public member functions.

## Data Members

- **data** – Pointer to the first element of the dynamically allocated contiguous array.
- **size** – Current number of elements stored.
- **capacity** – Total allocated storage.

## Rule of Three

The class follows the Rule of Three:

1. Destructor
2. Copy Constructor
3. Copy Assignment Operator

A shallow copy is not used because it can cause dangling pointers and double deletion. Therefore, a deep copy is used so that each object owns its own memory.

---

# Section 3 – Complexity Estimates

| Operation | Time Complexity | Reason |
|-----------|-----------------|--------|
| `append()` | Best: **O(1)**, Amortized: **O(1)**, Worst: **O(n)** | If capacity>size then O(1), otherwise resizing is done by calling resize() . |
| `pop()` | **O(1)** | Removes the last element directly. |
| `pop(index)` | **O(n)** | Removes element by index and Remaining elements are shifted. |
| `remove(value)` | **O(n)** | Array is traversed to find the element and shifting are required. |
| `insert(index, value)` | **O(n)** | Elements are shifted to make space for the element to insert. |
| `size()` | **O(1)** | Increment size by one as element is inserted. |
| `capacity()` | **O(1)** | Returns stored variable. |
| `resize()` | **O(n)** | Allocates new memory and copies all elements. |

**Capacity Growth**

The capacity is doubled (`capacity *= 2`) whenever the array becomes full. This reduces the number of resizing operations and provides amortized **O(1)** append performance.

here we are doubling array bcoz if we double the size of array then less resizing need to perform but at large array size, memory block remain unused, we can also use **(1.5x)** or **(1.8x)** but here the space will less unused but reisizing will increase.

---

# Section 4 – Design Decisions

### Decision 1 – Contiguous Memory
**Chosen because**
- Constant-time indexing.
- Better CPU cache locality.
- Simple pointer arithmetic.

**Rejected Alternative:** Linked List

**Reason**
- O(n) indexing.
- Poor cache performance.
- Extra memory for pointers.

---

### Decision 2 – Capacity Growth
**Chosen:** `capacity *= 2`

**Reason**
- Fewer reallocations.
- Amortized O(1) append.

**Rejected:** `capacity += 1`

**Reason**
- Frequent resizing.
- Poor overall performance.

---

### Decision 3 – Template-Based Design

Templates allow one implementation to work with every data type without code duplication.

---

### Decision 4 – Deep Copy

Deep copy is used instead of shallow copy to prevent dangling pointers and double deletion.

---

