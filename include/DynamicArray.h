#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <cstdlib>
#include <new>
#include <stdexcept>

template<typename T>
class DynamicArray
{
private:
    T* data;   //data
    size_t sz;   //size
    size_t cap;  //capacity

    void resize();

public:
    // Constructors & Destructor
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    // API Methods
    void append(const T& value);
    T pop();
    T pop(size_t index);
    void insert(size_t index, const T& value);
    void remove(const T& value);
    // Random Access
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void clear();

    // Getters
    size_t size() const;
    size_t capacity() const;
};

// Crucial: Include the implementation file at the bottom
#include "../src/DynamicArray/DynamicArray.tpp"

#endif // DYNAMICARRAY_HPP