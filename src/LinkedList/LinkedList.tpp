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
    // while (head != nullptr)
    // {
    clear();
    // }
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
            clear();
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

    if(!newNode)
    throw std::bad_alloc();

    // new (&newNode->data) T(value);
    try
    {
        new(&newNode->data) T(value);
    }
    catch(...)
    {
        std::free(newNode);
        throw;
    }

    newNode->next = head;

    head = newNode;

    if (tail == nullptr)
    {
        tail = head;
    }

    count++;
}


// Delete Front
template<typename T>
void LinkedList<T>::deleteFront()
{
    if(head == nullptr)
        return;  // Added missing semicolon

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

        if(!newNode)
        throw std::bad_alloc();

        try
        {
            new(&newNode->data) T(value);
        }
        catch(...)
        {
            std::free(newNode);
            throw;
        }

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

    // new (&newNode->data) T(value);

    try
    {
        new(&newNode->data) T(value);
    }
    catch(...)
    {
        std::free(newNode);
        throw;
    }

    newNode->next = prev->next;

    prev->next = newNode;

    count++;
}


// search()

template<typename T>
bool LinkedList<T>::search(const T& value) const
{
    return find(value)!=nullptr;
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

// find
template<typename T>
T* LinkedList<T>::find(const T& value)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return &current->data;
        }

        current = current->next;
    }

    return nullptr;
}

//find const
template<typename T>
const T* LinkedList<T>::find(const T& value) const
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return &current->data;
        }

        current = current->next;
    }

    return nullptr;
}

//remove
//remove
template<typename T>
bool LinkedList<T>::remove(const T& value)
{
    if (head == nullptr)
        return false;

    if (head->data == value)
    {
        deleteFront();
        return true;
    }

    Node* prev = head;
    Node* current = head->next;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            prev->next = current->next;

            if (current == tail)
                tail = prev;

            current->data.~T();
            std::free(current);

            count--;

            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}

//foreach
template<typename T>
template<typename Func>
void LinkedList<T>::forEach(Func func)
{
    Node* current = head;

    while (current != nullptr)
    {
        func(current->data);
        current = current->next;
    }
}

//clear
template<typename T>
void LinkedList<T>::clear()
{
    while(head != nullptr)
    {
        deleteFront();
    }
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return count == 0;
}

//insertback
template<typename T>
void LinkedList<T>::insertBack(const T& value)
{
    Node* newNode=(Node*)std::malloc(sizeof(Node));

    if(!newNode)
        throw std::bad_alloc();

    // new(&newNode->data) T(value);
    try
    {
        new(&newNode->data) T(value);
    }
    catch(...)
    {
        std::free(newNode);
        throw;
    }

    newNode->next=nullptr;

    if(head==nullptr)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }

    count++;
}