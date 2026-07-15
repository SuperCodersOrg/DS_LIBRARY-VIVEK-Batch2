
// HashMap.tpp (Implementation File)

#include "../../include/HashMap.h" // Makes the IDE linter happy!

// Hash function for the HashMap
template<typename K, typename V>
size_t HashMap<K, V>::hash(const K& key) const {
    return hashValue(key);
}


template<typename K,typename V>
typename HashMap<K,V>::Node*
HashMap<K,V>::findNode(const K& key)
{
    if(bucketCount==0)
        return nullptr;

    Node temp;

    temp.key=key;

    size_t index=hash(key)%bucketCount;

    return buckets[index].find(temp);
}

template<typename K,typename V>
const typename HashMap<K,V>::Node*
HashMap<K,V>::findNode(const K& key) const
{
    if(bucketCount==0)
        return nullptr;

    Node temp;

    temp.key=key;

    size_t index=hash(key)%bucketCount;

    return buckets[index].find(temp);
}

template<typename K,typename V>
void HashMap<K,V>::rehash()
{
    size_t newBucketCount=bucketCount*2;

    DynamicArray< LinkedList<Node> > newBuckets;

    for(size_t i=0;i<newBucketCount;i++)
        newBuckets.append(LinkedList<Node>());

    for(size_t i=0;i<bucketCount;i++)
    {
        buckets[i].forEach([&](const Node& entry)
        {
            size_t index=hash(entry.key)%newBucketCount;

            newBuckets[index].insertFront(entry);
        });
    }

    buckets=newBuckets;

    bucketCount=newBucketCount;
}

// Default Constructor
template<typename K, typename V>
HashMap<K, V>::HashMap() {
    bucketCount = 8;
    elementCount = 0;
    loadFactor = 0.75f;
    for (size_t i = 0; i < bucketCount; i++) buckets.append(LinkedList<Node>());
}


template<typename K,typename V>
HashMap<K,V>::HashMap(const HashMap& other)
{
    bucketCount=other.bucketCount;

    elementCount=other.elementCount;

    loadFactor=other.loadFactor;

    buckets=other.buckets;
}

template<typename K,typename V>
HashMap<K,V>& HashMap<K,V>::operator=(const HashMap& other)
{
    if(this==&other)
        return *this;

    bucketCount=other.bucketCount;

    elementCount=other.elementCount;

    loadFactor=other.loadFactor;

    buckets=other.buckets;

    return *this;
}

// Destructor
template<typename K, typename V>
HashMap<K, V>::~HashMap() {
    clear();
}

template<typename K,typename V>
void HashMap<K,V>::put(const K& key,const V& value)
{
    if(static_cast<float>(elementCount+1)/bucketCount>loadFactor)
        rehash();

    size_t index=hash(key)%bucketCount;

    Node temp;
    temp.key=key;
    // temp.value is uninitialized but that's fine since we're only comparing keys

    Node* existing = buckets[index].find(temp);

    if(existing != nullptr)
    {
        existing->value = value;
        return;
    }

    Node newEntry;
    newEntry.key = key;
    newEntry.value = value;

    buckets[index].insertFront(newEntry);

    elementCount++;
}

template<typename K,typename V>
V& HashMap<K,V>::get(const K& key)
{
    Node* entry=findNode(key);

    if(!entry)
        throw std::out_of_range("Key not found");

    return entry->value;
}


template<typename K,typename V>
const V& HashMap<K,V>::get(const K& key) const
{
    const Node* entry=findNode(key);

    if(!entry)
        throw std::out_of_range("Key not found");

    return entry->value;
}

template<typename K,typename V>
bool HashMap<K,V>::contains(const K& key) const
{
    return findNode(key)!=nullptr;
}

template<typename K,typename V>
bool HashMap<K,V>::remove(const K& key)
{
    size_t index=hash(key)%bucketCount;

    Node temp;

    temp.key=key;

    if(buckets[index].remove(temp))
    {
        elementCount--;

        return true;
    }

    return false;
}

template<typename K,typename V>
void HashMap<K,V>::clear()
{
    for(size_t i=0;i<bucketCount;i++)
        buckets[i].clear();

    elementCount=0;
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

//for each
template<typename K, typename V>
template<typename Func>
void HashMap<K, V>::forEach(Func func)
{
    for (size_t i = 0; i < bucketCount; i++)
    {
        buckets[i].forEach([&](Node& entry)
        {
            func(entry.key, entry.value);
        });
    }
}