#include "../../include/DynamicArray.h"

// Private Helper
template<typename T>
void DynamicArray<T>::resize()
{
    size_t newCap = (cap == 0) ? 1 : cap * 2;
    T* newData = (T*)std::malloc(sizeof(T) * newCap);

    if (newData == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < sz; i++)
    {
        new(&newData[i]) T(data[i]);
        data[i].~T();
    }

    std::free(data);
    data = newData;
    cap = newCap;
}

// Default Constructor
template<typename T>
DynamicArray<T>::DynamicArray()
{
    sz = 0;
    cap = 0;
    data = nullptr;;

    // if (data == nullptr)
    //     throw std::bad_alloc();
}

// Copy Constructor
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    sz = other.sz;
    cap = other.cap;
    data = (T*)std::malloc(sizeof(T) * cap);

    if (data == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < sz; i++)
        new(&data[i]) T(other.data[i]);
}

// Copy Assignment Operator
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < sz; i++)
        data[i].~T();

    std::free(data);

    sz = other.sz;
    cap = other.cap;
    data = (T*)std::malloc(sizeof(T) * cap);

    if (data == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < sz; i++)
        new(&data[i]) T(other.data[i]);

    return *this;
}

// Destructor
template<typename T>
DynamicArray<T>::~DynamicArray()
{
    for (int i = 0; i < sz; i++)
        data[i].~T();

    std::free(data);
}

// Append
template<typename T>
void DynamicArray<T>::append(const T& value)
{
    if (sz == cap)
        resize();

    new(&data[sz]) T(value);
    sz++;
}

// Pop (Last Element)
template<typename T>
T DynamicArray<T>::pop()
{
    if (sz == 0)
        throw std::out_of_range("Array Empty");

    sz--;
    T value = data[sz];
    data[sz].~T();
    return value;
}

// // Pop (By Index)
// template<typename T>
// T DynamicArray<T>::pop(int index)
// {
//     if (index < 0 || index >= sz)
//         throw std::out_of_range("Invalid Index");

//     T value = data[index];
//     // data[index].~T();

//     // for (int i = index; i < sz - 1; i++)
//     // {
//     //     new(&data[i]) T(data[i + 1]);
//     //     data[i + 1].~T();
//     // }

//     // sz--;

//     for (int i = index; i < sz - 1; i++)
//     {
//         data[i] = data[i + 1];
//     }

//     sz--;
//     data[sz].~T();
//     return value;
// }

template<typename T>
T DynamicArray<T>::pop(size_t index)
{
    // Check if the index is valid
    if (index >= sz)
        throw std::out_of_range("Invalid Index");

    // Save the value to return later
    T value = data[index];

    // Shift all elements one position to the left
    for (int i = index; i < sz - 1; i++)
    {
        data[i] = data[i + 1];
    }

    // Decrease the logical size
    sz--;

    // Destroy the now-unused last object
    data[sz].~T();

    // Return the removed value
    return value;
}

// Insert
template<typename T>
void DynamicArray<T>::insert(size_t index, const T& value)
{
    if (index > sz)
        throw std::out_of_range("Invalid Index");

    if (index == sz)
    {
        append(value);
        return;
    }

    if (sz == cap)
        resize();

    new(&data[sz]) T(data[sz - 1]);

    for (int i = sz - 1; i > index; i--)
        data[i] = data[i - 1];

    data[index] = value;
    sz++;
}

// Remove
template<typename T>
void DynamicArray<T>::remove(const T& value)
{
    for (int i = 0; i < sz; i++)
    {
        if (data[i] == value)
        {
            pop(i);
            return;
        }
    }
    throw std::runtime_error("Value not found");
}

// Clear
template<typename T>
void DynamicArray<T>::clear()
{
    for (int i = 0; i < sz; i++)
        data[i].~T();

    sz = 0;
}

// Size Getters
template<typename T>
size_t DynamicArray<T>::size() const
{
    return sz;
}

template<typename T>
size_t DynamicArray<T>::capacity() const
{
    return cap;
}

// operator[] (Non-const)
template<typename T>
T& DynamicArray<T>::operator[](size_t index)
{
    if (index >= sz)
        throw std::out_of_range("Invalid Index");

    return data[index];
}
