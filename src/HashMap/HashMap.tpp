
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

// // Rehash when load factor exceeds threshold
// template<typename K, typename V>
// void HashMap<K, V>::rehash()
// {
//     // Save the old bucket array and count
//     DynamicArray<Node*> oldBuckets = buckets;
//     size_t oldBucketCount = bucketCount;
    
//     // Double the bucket count
//     size_t newBucketCount = bucketCount * 2;
    
//     // Create new bucket array with null pointers
//     bucketCount = newBucketCount;
//     buckets = DynamicArray<Node*>();
    
//     // Initialize all buckets to nullptr
//     for (size_t i = 0; i < bucketCount; i++)
//         buckets.append(nullptr);
    
//     // Reset element count and reinsert all elements
//     elementCount = 0;
    
//     // Traverse all old buckets
//     for (size_t i = 0; i < oldBucketCount; i++)
//     {
//         Node* current = oldBuckets[i];
        
//         // Traverse each linked list
//         while (current != nullptr)
//         {
//             Node* next = current->next;
            
//             // Insert node into new bucket array
//             put(current->key, current->value);
            
//             // Move to the next node (will be deleted by oldBuckets destructor)
//             current = next;
//         }
//     }
    
// }

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
    maxLoadFactor = 0.75f;
    
    // Initialize bucket array with null pointers
    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);
}

// Copy Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other)
{
    // Copy simple member variables
    bucketCount = other.bucketCount;
    elementCount = 0;
    maxLoadFactor = other.maxLoadFactor;
    
    // Initialize bucket array with null pointers
    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);
    
    // Deep copy all nodes from other
    for (size_t i = 0; i < bucketCount; i++)
    {
        Node* current = other.buckets[i];
        
        while (current != nullptr)
        {
            // Insert a copy of the key-value pair
            put(current->key, current->value);
            current = current->next;
        }
    }
}

// Assignment Operator
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap& other)
{
    // Check for self-assignment
    if (this == &other)
        return *this;
    
    // Clear existing contents
    clear();
    
    // Copy member variables
    bucketCount = other.bucketCount;
    elementCount = 0;
    maxLoadFactor = other.maxLoadFactor;
    
    // Reinitialize bucket array
    buckets = DynamicArray<Node*>();
    for (size_t i = 0; i < bucketCount; i++)
        buckets.append(nullptr);
    
    // Deep copy all nodes from other
    for (size_t i = 0; i < bucketCount; i++)
    {
        Node* current = other.buckets[i];
        
        while (current != nullptr)
        {
            put(current->key, current->value);
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

