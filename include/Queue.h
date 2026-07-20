#ifndef QUEUE_H
#define QUEUE_H

#include "../../include/LinkedList.h"
#include <stdexcept>

template<typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue() = default;
    ~Queue() = default;

    // Insert at rear
    void enqueue(const T& value);

    // Remove from front
    void dequeue();

    // Front element
    T& front();
    const T& front() const;

    // Utilities
    bool empty() const;
    size_t size() const;
    void print() const;
};

#include "../src/Queue/Queue.tpp"

#endif