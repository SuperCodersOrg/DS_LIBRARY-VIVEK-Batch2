
// HashMap.tpp (Implementation File)

#include "../../include/HashMap.h" // Makes the IDE linter happy!

// Hash function for the HashMap
template<typename K, typename V>
size_t HashMap<K, V>::hash(const K& key) const {
    return hashValue(key);
}

// Find a node
template<typename K, typename V>
typename HashMap<K, V>::Node* HashMap<K, V>::findNode(const K& key) const {
    if (bucketCount == 0) return nullptr;
    
    size_t index = hash(key) % bucketCount;
    Node* current = buckets[index];
    
    while (current != nullptr) {
        if (current->key == key) return current;
        current = current->next;
    }
    return nullptr;
}

// Rehash (Exception Safe)
template<typename K, typename V>
void HashMap<K, V>::rehash() {
    size_t newBucketCount = bucketCount * 2;
    DynamicArray<Node*> newBuckets;

    // Allocate fully before modifying class state to prevent corruption
    for (size_t i = 0; i < newBucketCount; i++) {
        newBuckets.append(nullptr);
    }

    // Move nodes to the new array
    for (size_t i = 0; i < bucketCount; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* next = current->next;
            size_t index = hash(current->key) % newBucketCount;

            current->next = newBuckets[index];
            newBuckets[index] = current;
            current = next;
        }
    }

    // Commit changes
    buckets = newBuckets;
    bucketCount = newBucketCount;
}

// Default Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap() {
    bucketCount = 8;
    elementCount = 0;
    loadFactor = 0.75f;
    for (size_t i = 0; i < bucketCount; i++) buckets.append(nullptr);
}

// Copy Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other) {
    bucketCount = other.bucketCount;
    elementCount = other.elementCount;
    loadFactor = other.loadFactor;

    for (size_t i = 0; i < bucketCount; i++) buckets.append(nullptr);

    for (size_t i = 0; i < bucketCount; i++) {
        Node* current = other.buckets[i];
        Node** tail = &buckets[i];

        while (current != nullptr) {
            // Node* newNode = (Node*)std::malloc(sizeof(Node));
            // if (!newNode) throw std::bad_alloc();

            // new (&newNode->key) K(current->key);
            // new (&newNode->value) V(current->value);
            // newNode->next = nullptr;
            Node* newNode = (Node*)std::malloc(sizeof(Node));
            if (!newNode)
                throw std::bad_alloc();

            try
            {
                new (&newNode->key) K(current->key);

                try
                {
                    new (&newNode->value) V(current->value);
                }
                catch (...)
                {
                    newNode->key.~K();
                    throw;
                }
            }
            catch (...)
            {
                std::free(newNode);
                clear();
                throw;
            }

            newNode->next = nullptr;

            *tail = newNode;
            tail = &newNode->next;
            current = current->next;
        }
    }
}

// Assignment Operator
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap& other) {
    if (this == &other) return *this;
    
    clear();
    bucketCount = other.bucketCount;
    elementCount = other.elementCount;
    loadFactor = other.loadFactor;

    buckets = DynamicArray<Node*>();
    for (size_t i = 0; i < bucketCount; i++) buckets.append(nullptr);

    for (size_t i = 0; i < bucketCount; i++) {
        Node* current = other.buckets[i];
        Node** tail = &buckets[i];

        while (current != nullptr) {
            Node* newNode = (Node*)std::malloc(sizeof(Node));
            if (!newNode)
                throw std::bad_alloc();

            try
            {
                new (&newNode->key) K(current->key);

                try
                {
                    new (&newNode->value) V(current->value);
                }
                catch (...)
                {
                    newNode->key.~K();
                    throw;
                }
            }
            catch (...)
            {
                std::free(newNode);
                clear();
                throw;
            }

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
HashMap<K, V>::~HashMap() {
    clear();
}

// Put
template<typename K, typename V>
void HashMap<K, V>::put(const K& key, const V& value) {
    std::cout << "PUT hash = " << hash(key)
          << " index = " << hash(key) % bucketCount << std::endl;

    Node* existing = findNode(key);
    if (existing != nullptr) {
        existing->value.~V();
        new (&existing->value) V(value);
        return;
    }
    
    if (static_cast<float>(elementCount + 1) / bucketCount > loadFactor) {
        rehash();
    }
    
    size_t index = hash(key) % bucketCount;
    // Node* newNode = (Node*)std::malloc(sizeof(Node));
    // if (!newNode) throw std::bad_alloc();
    
    // new (&newNode->key) K(key);
    // new (&newNode->value) V(value);
    
    // newNode->next = buckets[index];
    // buckets[index] = newNode;
    // elementCount++;
    Node* newNode = (Node*)std::malloc(sizeof(Node));
    if (!newNode)
        throw std::bad_alloc();

    try
    {
        new (&newNode->key) K(key);

        try
        {
            new (&newNode->value) V(value);
        }
        catch (...)
        {
            newNode->key.~K();
            throw;
        }
    }
    catch (...)
    {
        std::free(newNode);
        throw;
    }

    newNode->next = buckets[index];
    buckets[index] = newNode;
    elementCount++;
}

// Get (Mutable)
template<typename K, typename V>
V& HashMap<K, V>::get(const K& key) {
    std::cout << "GET hash = " << hash(key)
          << " index = " << hash(key) % bucketCount << std::endl;
          
    Node* node = findNode(key);
    if (!node) throw std::out_of_range("Key not found in HashMap");
    return node->value;
}

// Get (Const)
template<typename K, typename V>
const V& HashMap<K, V>::get(const K& key) const {
    Node* node = findNode(key);
    if (!node) throw std::out_of_range("Key not found in HashMap");
    return node->value;
}

// Contains
template<typename K, typename V>
bool HashMap<K, V>::contains(const K& key) const {
    return findNode(key) != nullptr;
}

// Remove
template<typename K, typename V>
bool HashMap<K, V>::remove(const K& key) {
    if (bucketCount == 0) return false;
    
    size_t index = hash(key) % bucketCount;
    if (!buckets[index]) return false;
    
    Node* current = buckets[index];
    if (current->key == key) {
        buckets[index] = current->next;
        current->key.~K();
        current->value.~V();
        std::free(current);
        elementCount--;
        return true;
    }
    
    Node* prev = current;
    current = current->next;
    
    while (current != nullptr) {
        if (current->key == key) {
            prev->next = current->next;
            current->key.~K();
            current->value.~V();
            std::free(current);
            elementCount--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Clear
template<typename K, typename V>
void HashMap<K, V>::clear() {
    for (size_t i = 0; i < bucketCount; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* next = current->next;
            current->key.~K();
            current->value.~V();
            std::free(current);
            current = next;
        }
        buckets[i] = nullptr;
    }
    elementCount = 0;
}

// Size
template<typename K, typename V>
size_t HashMap<K, V>::size() const { 
    return elementCount; 
}

//Empty
template<typename K, typename V>
bool HashMap<K, V>::empty() const { 
    return elementCount == 0; 
}