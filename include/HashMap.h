#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <new>
#include <stdexcept>

#include "DynamicArray.h"

template <typename K, typename V>
class HashMap{
    private:
        struct Node{
            K key;
            V value;
            Node* next;
        };

    DynamicArray<Node*> buckets;
    // size_t buckets;
    size_t bucketCount;
    size_t elementCount;
    float loadFactor;

    //Pvt helper methods

    size_t hash(const K& key) const;
    void rehash();
    Node* findNode(const K& key) const;

    public:
        //constructor
        HashMap();
        
        //Copy constructor
        HashMap(const HashMap& other);

        //Copy assignment operator
        HashMap& operator=(const HashMap& other);

        //destructor
        ~HashMap();

        //Public API
        void put(const K& key, const V& value);
        V& get(const K& key);
        const V& get(const K& key) const;
        bool contains(const K& key) const;
        bool remove(const K& key);
        void clear();
        size_t size() const;
        bool empty()const;

};

#include "../src/HashMap/HashMap.tpp" 

#endif