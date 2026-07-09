#include "../../include/LinkedList.h"

// Constructor

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}


// Destructor

template<typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        deleteFront();
    }
}


// Copy Constructor

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head = nullptr;
    tail = nullptr;
    count = 0;

    Node* current = other.head;

    while (current != nullptr)
    {
        insert(count, current->data);
        current = current->next;
    }
}


// Assignment Operator

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if (this != &other)
    {
        while (head != nullptr)
        {
            deleteFront();
        }

        Node* current = other.head;

        while (current != nullptr)
        {
            insert(count, current->data);
            current = current->next;
        }
    }

    return *this;
}

// insertFront()

template<typename T>
void LinkedList<T>::insertFront(const T& value)
{

    Node* newNode = (Node*)std::malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        return;
    }

    new (&newNode->data) T(value);

    newNode->next = head;

    head = newNode;

    if (tail == nullptr)
    {
        tail = head;
    }

    count++;
}


// deleteFront()

template<typename T>
void LinkedList<T>::deleteFront()
{
    if (head == nullptr)
    {
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    temp->data.~T();

    std::free(temp);

    count--;
}


// insert()

template<typename T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    if (index > count)
    {
        return;
    }

    if (index == 0)
    {
        insertFront(value);
        return;
    }

    if (index == count)
    {
        Node* newNode = (Node*)std::malloc(sizeof(Node));

        if (newNode == nullptr)
        {
            return;
        }

        new (&newNode->data) T(value);

        newNode->next = nullptr;

        tail->next = newNode;

        tail = newNode;

        count++;

        return;
    }

    Node* prev = head;

    for (size_t i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }

    Node* newNode = (Node*)std::malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        return;
    }

    new (&newNode->data) T(value);

    newNode->next = prev->next;

    prev->next = newNode;

    count++;
}


// search()

template<typename T>
bool LinkedList<T>::search(const T& value) const
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}


// size()

template<typename T>
size_t LinkedList<T>::size() const
{
    return count;
}


// print()

template<typename T>
void LinkedList<T>::print() const
{
    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->data;

        if (current->next != nullptr)
        {
            std::cout << " -> ";
        }

        current = current->next;
    }

    std::cout << std::endl;
}