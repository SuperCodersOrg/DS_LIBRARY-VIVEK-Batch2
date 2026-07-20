#include "../../include/Queue.h"

template<typename T>
void Queue<T>::enqueue(const T& value)
{
    list.insertBack(value);
}

template<typename T>
void Queue<T>::dequeue()
{
    if (list.empty())
        throw std::out_of_range("Queue is empty");

    list.deleteFront();
}

template<typename T>
T& Queue<T>::front()
{
    if (list.empty())
        throw std::out_of_range("Queue is empty");

    // Requires LinkedList::front()
    return *list.find(*list.find(*list.find(nullptr)));
}