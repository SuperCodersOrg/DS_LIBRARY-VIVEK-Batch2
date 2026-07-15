#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstdlib>    // For std::malloc, std::free
#include <new>        // For placement new
#include <stdexcept>  // For std::out_of_range, std::bad_alloc
#include <string>
#include "DynamicArray.h" 
#include "LinkedList.h"

// =================== Hash Utilities ===================

const size_t FNV_OFFSET_BASIS = 0xcbf29ce484222325ULL;
const size_t FNV_PRIME = 0x100000001b3ULL;

// Default hash function (primitive types)
template<typename T>
size_t hashValue(const T& value) {
    size_t hash = FNV_OFFSET_BASIS;
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&value);
    for (size_t i = 0; i < sizeof(T); i++) {
        hash ^= bytes[i];
        hash *= FNV_PRIME;
    }
    return hash;
}

// C-string hash (const char*)
template<>
inline size_t hashValue<const char*>(const char* const& str) {
    size_t hash = FNV_OFFSET_BASIS;
    const char* ptr = str;
    while (*ptr) {
        hash ^= static_cast<unsigned char>(*ptr);
        hash *= FNV_PRIME;
        ++ptr;
    }
    return hash;
}

// C-string hash (char*)
template<>
inline size_t hashValue<char*>(char* const& str) {
    size_t hash = FNV_OFFSET_BASIS;
    const char* ptr = str;
    while (*ptr) {
        hash ^= static_cast<unsigned char>(*ptr);
        hash *= FNV_PRIME;
        ++ptr;
    }
    return hash;
}

template<>
inline size_t hashValue<std::string>(const std::string& str)
{
    size_t hash = FNV_OFFSET_BASIS;

    for (size_t i = 0; i < str.size(); i++)
    {
        hash ^= static_cast<unsigned char>(str[i]);
        hash *= FNV_PRIME;
    }

    return hash;
}

// Variadic hash combine for custom objects
template<typename T>
size_t hashCombine(const T& value) {
    return hashValue(value);
}

template<typename T, typename... Args>
size_t hashCombine(const T& first, const Args&... rest) {
    return hashValue(first) ^ (hashCombine(rest...) << 1);
}

// =================== HashMap Class ===================

template <typename K, typename V>
class HashMap {
private:
    struct Node {
        K key;
        V value;

        bool operator==(const Node& other) const
        {
            return key == other.key;
        }
    };

    DynamicArray< LinkedList<Node> >buckets;
    size_t bucketCount;
    size_t elementCount;
    float loadFactor;

    size_t hash(const K& key) const;
    void rehash();
    // Node* findNode(const K& key) const;`7
    Node* findNode(const K& key);
    const Node* findNode(const K& key) const;

public:
    HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);
    ~HashMap();

    void put(const K& key, const V& value);
    V& get(const K& key);
    const V& get(const K& key) const;
    bool contains(const K& key) const;
    bool remove(const K& key);
    void clear();
    size_t size() const;
    bool empty() const;
    template<typename Func>
    void forEach(Func func);
};

// Include the implementation at the bottom of the header
#include "../src/HashMap/HashMap.tpp" 

#endif // HASHMAP_H