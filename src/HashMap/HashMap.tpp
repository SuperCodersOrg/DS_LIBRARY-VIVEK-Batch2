
#include "../../include/HashMap.h"

// FNV-1 Hash Function (64-bit)


// FNV-1 constants (64-bit)
static const size_t FNV_OFFSET_BASIS = 0xcbf29ce484222325ULL;
static const size_t FNV_PRIME = 0x100000001b3ULL;

// FNV-1 hash for primitive types
template<typename K>
size_t fnv1HashPrimitive(const K& value)
{
    size_t hash = FNV_OFFSET_BASIS;
    
    // Treat the primitive as a sequence of bytes
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&value);
    size_t size = sizeof(K);
    
    // FNV-1 hash algorithm
    for (size_t i = 0; i < size; i++)
    {
        hash ^= bytes[i];
        hash *= FNV_PRIME;
    }
    
    return hash;
}


// HashMap Implementation


// Hash function for the HashMap (primitive types only)
template<typename K, typename V>
size_t HashMap<K, V>::hash(const K& key) const
{
    // Use FNV-1 hash for primitive types
    return fnv1HashPrimitive(key);
}

// Find a node with the given key (returns nullptr if not found)
template<typename K, typename V>
typename HashMap<K, V>::Node* HashMap<K, V>::findNode(const K& key) const
{
    // Return nullptr if no buckets exist
    if (bucketCount == 0)
        return nullptr;
    
    // Compute bucket index
    size_t hashValue = hash(key);
    size_t index = hashValue % bucketCount;
    
    // Traverse the linked list in that bucket
    Node* current = buckets[index];
    
    while (current != nullptr)
    {
        // Check if keys match (works for primitive types)
        if (current->key == key)
            return current;
        
        current = current->next;
    }
    
    // Key not found
    return nullptr;
}

template<typename K, typename V>
void HashMap<K, V>::rehash()
{
    DynamicArray<Node*> oldBuckets = buckets;
    size_t oldBucketCount = bucketCount;

    bucketCount *= 2;

    buckets = DynamicArray<Node*>();

    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);

    // Don't change elementCount.
    // We are only moving nodes.

    for (size_t i = 0; i < oldBucketCount; i++)
    {
        Node* current = oldBuckets[i];

        while (current != nullptr)
        {
            Node* next = current->next;

            size_t index = hash(current->key) % bucketCount;

            // Insert node at the beginning of the new bucket
            current->next = buckets[index];
            buckets[index] = current;

            current = next;
        }
    }
}


// Constructors, Destructor, and Assignment

// Default Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap()
{
    // Initialize member variables
    bucketCount = 8;                // Start with 8 buckets
    elementCount = 0;
    loadFactor = 0.75f;
    
    // Initialize bucket array with null pointers
    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);
}


// Copy Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other)
{
    bucketCount = other.bucketCount;
    elementCount = other.elementCount;
    loadFactor = other.loadFactor;

    // Create bucket array
    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);

    // Deep copy every bucket
    for (size_t i = 0; i < bucketCount; i++)
    {
        Node* current = other.buckets[i];
        Node** tail = &buckets[i];

        while (current != nullptr)
        {
            Node* newNode = (Node*)std::malloc(sizeof(Node));

            if (newNode == nullptr)
                throw std::bad_alloc();

            new (&newNode->key) K(current->key);
            new (&newNode->value) V(current->value);

            newNode->next = nullptr;

            *tail = newNode;
            tail = &newNode->next;

            current = current->next;
        }
    }
}


// Assignment Operator
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap& other)
{
    if (this == &other)
        return *this;

    clear();

    bucketCount = other.bucketCount;
    elementCount = other.elementCount;
    loadFactor = other.loadFactor;

    buckets = DynamicArray<Node*>();

    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);

    // Deep copy every bucket
    for (size_t i = 0; i < bucketCount; i++)
    {
        Node* current = other.buckets[i];
        Node** tail = &buckets[i];

        while (current != nullptr)
        {
            Node* newNode = (Node*)std::malloc(sizeof(Node));

            if (newNode == nullptr)
                throw std::bad_alloc();

            new (&newNode->key) K(current->key);
            new (&newNode->value) V(current->value);

            newNode->next = nullptr;

            *tail = newNode;
            tail = &newNode->next;

            current = current->next;
        }
    }

    return *this;
}

// Destructor
template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
    // Clear all nodes and free memory
    clear();
}



// Public API Implementation


// Insert or update a key-value pair
template<typename K, typename V>
void HashMap<K, V>::put(const K& key, const V& value)
{
    // Check if key already exists
    Node* existing = findNode(key);
    
    if (existing != nullptr)
    {
        // Update existing value
        existing->value.~V();                  // Destroy old value
        new (&existing->value) V(value);       // Construct new value
        return;
    }
    
    // Check if rehashing is needed
    float currentLoadFactor = static_cast<float>(elementCount + 1) / bucketCount;
    if (currentLoadFactor > loadFactor)
    {
        rehash();
    }
    
    // Compute bucket index
    size_t hashValue = hash(key);
    size_t index = hashValue % bucketCount;
    
    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if (newNode == nullptr)
        throw std::bad_alloc();
    
    // Construct key and value using placement new
    new (&newNode->key) K(key);
    new (&newNode->value) V(value);
    
    // Insert at the front of the linked list
    newNode->next = buckets[index];
    buckets[index] = newNode;
    
    // Increment element count
    elementCount++;
}

// Get a mutable reference to the value for the given key
template<typename K, typename V>
V& HashMap<K, V>::get(const K& key)
{
    Node* node = findNode(key);
    
    if (node == nullptr)
        throw std::out_of_range("Key not found in HashMap");
    
    return node->value;
}

// Get a const reference to the value for the given key
template<typename K, typename V>
const V& HashMap<K, V>::get(const K& key) const
{
    Node* node = findNode(key);
    
    if (node == nullptr)
        throw std::out_of_range("Key not found in HashMap");
    
    return node->value;
}

// Check if a key exists in the HashMap
template<typename K, typename V>
bool HashMap<K, V>::contains(const K& key) const
{
    return findNode(key) != nullptr;
}

// Remove a key-value pair by key
template<typename K, typename V>
bool HashMap<K, V>::remove(const K& key)
{
    // Return false if no buckets exist
    if (bucketCount == 0)
        return false;
    
    // Compute bucket index
    size_t hashValue = hash(key);
    size_t index = hashValue % bucketCount;
    
    // Handle empty bucket
    if (buckets[index] == nullptr)
        return false;
    
    // Check if the first node matches
    Node* current = buckets[index];
    
    if (current->key == key)
    {
        // Remove the first node
        buckets[index] = current->next;
        
        // Destroy objects and free memory
        current->key.~K();
        current->value.~V();
        free(current);
        
        elementCount--;
        return true;
    }
    
    // Traverse the list to find the node to remove
    Node* prev = current;
    current = current->next;
    
    while (current != nullptr)
    {
        if (current->key == key)
        {
            // Unlink the node
            prev->next = current->next;
            
            // Destroy objects and free memory
            current->key.~K();
            current->value.~V();
            free(current);
            
            elementCount--;
            return true;
        }
        
        prev = current;
        current = current->next;
    }
    
    // Key not found
    return false;
}

// Clear all key-value pairs from the HashMap
template<typename K, typename V>
void HashMap<K, V>::clear()
{
    // Traverse all buckets
    for (size_t i = 0; i < bucketCount; i++)
    {
        Node* current = buckets[i];
        
        // Traverse and delete all nodes in this bucket
        while (current != nullptr)
        {
            Node* next = current->next;
            
            // Destroy objects and free memory
            current->key.~K();
            current->value.~V();
            free(current);
            
            current = next;
        }
        
        // Set bucket to nullptr
        buckets[i] = nullptr;
    }
    
    // Reset element count
    elementCount = 0;
}

// Return the number of key-value pairs
template<typename K, typename V>
size_t HashMap<K, V>::size() const
{
    return elementCount;
}

// Check if the HashMap is empty
template<typename K, typename V>
bool HashMap<K, V>::empty() const
{
    return elementCount == 0;
}