# Design Proposal – HashMap

---

# Section 1 – Public API

The **HashMap** stores data as **key-value pairs**, where every key is unique and is used to efficiently retrieve its corresponding value.

The HashMap is implemented as a template so that it can store different key and value types.

The public interface is intentionally kept minimal while providing all essential operations.

| Method | Description |
|---------|-------------|
| `void put(const K& key, const V& value)` | Inserts a new key-value pair or updates the existing value if the key already exists. |
| `V& get(const K& key)` | Returns a reference to the value associated with the specified key. The key must exist in the HashMap. |
| `const V& get(const K& key) const` | Returns a constant reference to the value associated with the specified key. |
| `bool contains(const K& key) const` | Returns `true` if the key exists in the HashMap. |
| `bool remove(const K& key)` | Removes the key-value pair if it exists. |
| `int size() const` | Returns the number of stored key-value pairs. |
| `bool empty() const` | Returns `true` if the HashMap contains no elements. |
| `void clear()` | Removes all key-value pairs from the HashMap. |

---

# Section 2 – Internal Representation

The HashMap uses **Separate Chaining** to resolve collisions.

The bucket array is implemented using the project's **DynamicArray**, where each bucket stores a pointer to the first node of a singly linked list.

Each node stores

- Key
- Value
- Pointer to the next node

```cpp
template<typename K, typename V>
class HashMap
{
private:

    struct Node
    {
        K key;
        V value;
        Node* next;
    };

    DynamicArray<Node*> buckets;

    int bucketCount;

    int elementCount;

    float maxLoadFactor;

    unsigned int hash(const K& key) const;

    void rehash();

    Node* findNode(const K& key) const;

public:

    HashMap();

    HashMap(const HashMap&);

    HashMap& operator=(const HashMap&);

    ~HashMap();

    void put(const K& key, const V& value);

    V& get(const K& key);

    const V& get(const K& key) const;

    bool contains(const K& key) const;

    bool remove(const K& key);

    void clear();

    int size() const;

    bool empty() const;
};
```

---

## Internal Data Members

```cpp
DynamicArray<Node*> buckets;

int bucketCount;

int elementCount;

float maxLoadFactor;
```

- **buckets** stores the bucket array.
- **bucketCount** stores the current number of buckets.
- **elementCount** stores the total number of key-value pairs.
- **maxLoadFactor** stores the load factor threshold used before rehashing.

---

## Memory Layout

Each bucket points to the head of a singly linked list.

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/ba9e64c7-9307-4b26-92e3-a613965d8939" />


---

## Generic Hashing Strategy

The HashMap is implemented as a generic template and therefore must support primitive data types, strings, and user-defined classes using a common hashing mechanism. Regardless of the key type, the objective of hashing is to generate a single unsigned integer hash value that can be mapped to a bucket within the hash table.

The hashing framework is implemented using function templates. A generic hashing function determines the appropriate hashing algorithm according to the type of the key. Primitive data types such as `int`, `char`, `float`, and `double` are processed using specialized hashing functions implemented by the library. Strings are processed using a polynomial rolling hash, while user-defined classes are hashed by recursively hashing the values that represent their state and combining the resulting hash values into a single hash.

---

## Variadic Hash Combination

To support objects containing multiple data members, the hashing framework provides a helper function based on **Variadic Templates**.

```cpp
template<typename... Args>
unsigned int combineHash(const Args&... values);
```

The variadic template allows the function to accept any number of values without requiring multiple overloaded implementations.

For each argument, the generic hashing framework invokes the appropriate hashing function according to its type. Primitive data types are processed using their specialized hash functions, strings are processed using the string hashing algorithm, and user-defined classes are recursively hashed using the same framework. The resulting hash values are then combined using polynomial accumulation to generate a single hash value representing the complete object.

Since `combineHash()` accepts a variable number of arguments, it can combine the hash values of objects containing any number of data members without requiring separate implementations for different object sizes.

---

## Bucket Index Computation

After the final hash value has been generated, the corresponding bucket index is computed using

```cpp
bucketIndex = hashValue % bucketCount;
```

The modulo operation maps every generated hash value to a valid bucket within the HashMap. If multiple keys produce the same bucket index, the collision is resolved using **Separate Chaining**, where all colliding elements are stored in the linked list associated with that bucket.

---
### Memory Management

The project requires dynamic memory allocation using **malloc()** and **free()**.

Since **malloc()** only allocates raw memory, Placement New is used to construct the key and value objects.

```cpp
Node* node = (Node*)malloc(sizeof(Node));

new (&node->key) K(key);

new (&node->value) V(value);

node->next = nullptr;
```

Before releasing memory with **free()**, the destructors of both objects are explicitly invoked.

```cpp
node->key.~K();

node->value.~V();

free(node);
```

This guarantees correct construction and destruction of user-defined objects.

---

### Rule of Three

Since the HashMap owns dynamically allocated memory, it follows the **Rule of Three**.

### Destructor

The destructor traverses every bucket, destroys every node, explicitly invokes the destructors of the stored key and value, and finally releases all allocated memory.



### Copy Constructor

The copy constructor performs a **deep copy**.

A new bucket array is allocated and every node from the source HashMap is recreated independently.

Both HashMaps own completely separate memory.



### Assignment Operator

The assignment operator first checks for self-assignment.

If the objects are different, the existing contents are destroyed, memory is released, a new bucket array is allocated, and every node is copied from the source HashMap.

This prevents shallow copying, dangling pointers, and double-free errors.

---

# Section 3 – Complexity Analysis

| Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|-----------|--------------|------------|-------------|
| **put()** | **O(1)** | **O(1)** | **O(n)** | Computes the hash and locates the bucket instantly. The best case occurs when the bucket is empty or the node is the first item in the chain. The worst case occurs when all elements collide into a single bucket, requiring a full linear scan before insertion. |
| **get()** | **O(1)** | **O(1)** | **O(n)** | Directly computes the hash and jumps to the corresponding bucket. The best case occurs when the target element is at the head of the chain. In the worst case, all elements are in one bucket, requiring traversal of the entire chain. |
| **contains()** | **O(1)** | **O(1)** | **O(n)** | Same lookup process as **get()**. The best case finds the element immediately at the head of the chain, while the worst case searches through all **n** elements in a heavily collided bucket. |
| **remove()** | **O(1)** | **O(1)** | **O(n)** | Computes the hash, locates the appropriate bucket, and unlinks the node. The best case removes the first node instantly. In the worst case, it traverses the entire chain to locate the target node before removing it. |
| **size()** | **O(1)** | **O(1)** | **O(1)** | Always executes in constant time because it simply returns an internally maintained element count. No bucket traversal is required. |
| **empty()** | **O(1)** | **O(1)** | **O(1)** | Checks whether the internal element counter is equal to zero. This is a simple constant-time comparison. |
| **clear()** | **O(n)** | **O(n)** | **O(n)** | Visits every bucket and every node in the hash table to remove all entries and free memory. The time complexity is proportional to the total number of stored elements (**n**), regardless of their distribution. |

Rehashing is an internal operation whose complexity is **O(n)** because every stored element must be inserted into the new bucket array.

---

# Section 4 – Design Decisions

## 1. Separate Chaining

**Chosen:** Separate Chaining using singly linked lists.

**Reason**

Separate Chaining provides simple insertion and deletion while handling collisions naturally. Each bucket grows independently without affecting other buckets.

**Rejected**

Linear probing is rejected as the no of keys increases, all the allocated keys made cluster of acquired slots and that's why insertion and searching operation become TC O(n).

---

## 2. Dynamic Bucket Array

**Chosen**

The bucket array is dynamically allocated using the project's DynamicArray.

**Reason**

A dynamic bucket array allows the HashMap to expand as additional elements are inserted, reducing collision frequency.
**Rejected**

A fixed-size bucket array does not expand as per elements are inserted, making more collisons.

---

## 3. Load Factor

**Chosen**

Maximum Load Factor = **0.75**

**Reason**

Keeping the load factor below this threshold minimizes collisions while maintaining average-case **O(1)** insertion, lookup, and deletion performance.

**Rejected**

Rejected 1.5 and 2.0 because the hash collisions will increase and traversal time will also increase which takes insertion, lookup and deletion TC to O(n).

---

## 4. Manual Memory Management

**Chosen**

Memory is managed using
`malloc()`,
Placement New,
Explicit destructor calls,
`free()`

**Reason**

As the malloc() and free don't call the constructor and destructor respectively that's why placement new and free is used to call constructor and destructor.
