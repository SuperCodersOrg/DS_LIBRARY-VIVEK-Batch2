# Design Proposal – LinkedList

# Section 1 – Public API

<!-- The LinkedList is a linear data structure where each element is stored in a separate node allocated dynamically on the heap. Every node contains a value and a pointer to the next node. Unlike a DynamicArray, elements are not stored contiguously, making insertion and deletion efficient without shifting elements. -->

The LinkedList is a linear data structure in which each element is stored inside a separate node allocated on the heap. Every node stores a value of type T and a pointer to the next node. Using templates allows the same LinkedList implementation to work with different data types such as int, float, char, or std::string without modifying the source code.

 Unlike a DynamicArray, the elements are not stored in contiguous memory, allowing efficient insertion and deletion without shifting existing elements.


The proposed public interface is:

| Method | Description |
|---------|-------------|
| `void insertFront(const T& value)` | Inserts a new node at the beginning of the list. |
| `void deleteFront()` | Removes the first node if the list is not empty. |
| `void insert(size_t index, const T& value)` | Inserts a new node at the specified index position, if the index is (0 <=index <= size ) . |
| `bool search(const T& value) const` | Searches for a value and returns `true` if found, otherwise `false`.|
| `size_t size() const` | Returns the current number of nodes in the list. |
| `void print() const` | Displays all elements of the list from head to tail. |

<!-- ### API Design Justification

The API includes all operations required by the assignment while keeping the interface simple. It demonstrates insertion, deletion, traversal, searching, and size retrieval without introducing unnecessary functions. -->

---

# Section 2 – Internal Representation

The LinkedList is implemented as a **singly linked list**.

Each node is dynamically allocated on the heap using **malloc()** and released using **free()**.


```cpp
template<typename T>
class LinkedList
{
private:

    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t count;

public:

    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList& other);

    LinkedList& operator=(const LinkedList& other);

    void insertFront(const T& value);

    void deleteFront();

    void insert(size_t index, const T& value);

    bool search(const T& value) const;

    size_t size() const;

    void print() const;
};
```

The LinkedList maintains three private members:

```cpp
Node* head;
Node* tail;
size_t count;
```

- **head** points to the first node.
- **tail** points to the last node.
- **count** stores the total number of nodes.

Initially,

```text
head = nullptr
tail = nullptr
count = 0
```

### Memory Layout
<img width="1748" height="899" alt="image" src="https://github.com/user-attachments/assets/fa0d75cb-107f-4b0f-85d8-1b7c62c65039" />


### Rule of Three
<!-- 
Since the LinkedList owns dynamically allocated memory, it follows the Rule of Three.

- **Destructor:** Traverses the list and frees every allocated node.
- **Copy Constructor:** Performs a deep copy by creating new nodes.
- **Assignment Operator:** Frees existing memory before creating a deep copy.

Deep copying ensures each LinkedList owns its own memory and prevents dangling pointers and double-free errors. -->

Since the LinkedList allocates memory dynamically, it follows the Rule of Three.

####  Handling Templates with `malloc()` and `free()`

Since the LinkedList is implemented as a template, it can store both primitive and complex data types. However, `malloc()` only allocates raw memory and does **not** automatically call the constructor of an object. For complex types such as `std::string`, this would leave the object uninitialized. To solve this, **placement new** is used to manually invoke the constructor after memory allocation.

Similarly, `free()` only releases the allocated memory and does **not** call the object's destructor. Therefore, Before releasing memory with free(), the Node destructor is explicitly invoked. This automatically destroys the stored T object and any other members, ensuring proper cleanup before the raw memory is deallocated.

#### Destructor
<!-- 
The destructor traverses the entire list from the head and frees every node one by one using free() until no nodes remain. This ensures that every heap allocation is properly released and prevents memory leaks. -->

The destructor traverses the list from the head. For each node, it first explicitly invokes the Node destructor to destroy the stored object, then releases the raw memory using free(). This ensures that both object destruction and memory deallocation are performed correctly, preventing resource leaks.

#### Copy Constructor

The copy constructor performs a deep copy by creating completely new nodes and copying the values from the source list. Both lists become independent and own separate memory.

<!-- 
The assignment operator first checks for self-assignment. It then frees every allocated node using free() before performing a deep copy of the source list. This guarantees correct memory ownership and prevents leaks.

A shallow copy would only copy the `head` and `tail` pointers, causing two LinkedList objects to share the same nodes. When either object is destroyed, the second object would contain dangling pointers and eventually perform a double deletion. Therefore, deep copying is necessary to ensure each LinkedList object owns its own memory safely. -->

#### Assignment Operator

The assignment operator first checks for self-assignment. It then traverses the existing list, explicitly destroys every node, releases its memory using `free()`, and finally performs a deep copy of the source list by allocating and constructing new nodes. This guarantees correct memory ownership while preventing memory leaks and double deletion.

A shallow copy would only copy the `head` and `tail` pointers, causing two LinkedList objects to reference the same nodes. Destroying either object would leave the other with dangling pointers and eventually result in double deletion or memory corruption. Therefore, deep copying is necessary to ensure that each LinkedList object owns its own dynamically allocated memory safely.

---

# Section 3 – Complexity Estimates

| Operation | Best | Average | Worst | Explanation |
|------------|------|---------|--------|-------------|
| `insertFront()` | O(1) | O(1) | O(1) | Updates the head pointer directly. |
| `deleteFront()` | O(1) | O(1) | O(1) | Removes the first node by updating the head pointer. |
| `insert(index)` | O(1) | O(n) | O(n) | Requires traversal to reach middle positions O(n). However, boundary insertions at the front (index 0) or the back (index == count) can be optimized to O(1) using the head and tail pointers. |
| `search()` | O(1) | O(n) | O(n) | Nodes are checked sequentially until found. |
| `size()` | O(1) | O(1) | O(1) | Returns the maintained count variable. |
| `print()` | O(n) | O(n) | O(n) | Visits every node once. |

**Future Improvement:** 
Although the current API does not include an insertion-at-end function, maintaining a `tail` pointer allows such an operation to be implemented in **O(1)** time in the future. Without a tail pointer, insertion at the end would require traversing the entire list, resulting in **O(n)** complexity.


---

# Section 4 – Design Decisions

### 1. Singly Linked List

**Chosen:** Singly linked list because it supports all required operations with less memory.

**Rejected:** Doubly linked list because backward traversal is not required and maintaining an extra pointer increases memory usage and implementation complexity.

---

### 2. Head and Tail Pointers

**Chosen:** Both `head` and `tail` pointers are maintained. The `head` enables constant-time front operations, while the `tail` allows future insertion-at-end operations in **O(1)** time.

**Rejected:** Using only a head pointer would require traversing the entire list for any future append operation, resulting in **O(n)** complexity.

---

### 3. Count Variable

**Chosen:** A `count` variable is maintained so `size()` executes in **O(1)** time.

**Rejected:** Traversing the list every time `size()` is called would increase the complexity to **O(n)**.

---

### 4. Dynamic Memory Allocation

**Chosen:** Nodes are allocated using **malloc()** and released using **free()**, providing complete control over heap memory and supporting dynamic growth.

**Rejected:** A fixed-size array cannot grow dynamically and requires shifting elements during insertion and deletion.

---

### 5. Deep Copy

**Chosen:** Deep copying creates new nodes for every copied object, ensuring independent ownership of memory.

**Rejected:** Shallow copying shares node pointers, leading to dangling pointers, memory corruption, and double-free errors.

---

### 6. Template-Based Design

**Chosen**: The LinkedList is implemented as a template class (template<typename T>) so it can store any data type without rewriting the implementation.

**Rejected**: Implementing the LinkedList only for int would require creating separate implementations for other data types, increasing code duplication and reducing reusability.

---
<!-- 
## Overall Design

This design keeps the LinkedList simple, memory-efficient, and easy to maintain. Using a singly linked structure with **head**, **tail**, and **count** provides efficient front operations, constant-time size retrieval, and supports future enhancements while maintaining safe manual memory management. -->
