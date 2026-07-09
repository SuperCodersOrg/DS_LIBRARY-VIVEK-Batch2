#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib> // For malloc and free
#include <new>     // For placement new

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList& other);

    // Assignment Operator
    LinkedList& operator=(const LinkedList& other);

    // Public API Methods
    void insertFront(const T& value);
    void deleteFront();
    void insert(size_t index, const T& value);
    bool search(const T& value) const;
    size_t size() const;
    void print() const;
};

// Include implementation file for templates
#include "../src/LinkedList/LinkedList.tpp"

#endif // LINKEDLIST_H