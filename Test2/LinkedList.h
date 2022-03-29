#pragma once

#include <cstddef>
#include <ostream>

#include "List.h"

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    private:
        T *data;
        Node *next;
        
        Node(const T& data, Node *next = NULL);
        Node& operator=( const Node& );
        ~Node();

    friend class LinkedList<T>;
    template <typename U>
    friend std::ostream& 
        operator<<( std::ostream& stream, const LinkedList<U>& );
};

template <typename T>
class LinkedList : public List<T>
{
    private:
        Node<T> *head;
        Node<T> *tail;
        std::size_t length;

        void clear();

    public:
        LinkedList();
        LinkedList( const LinkedList& );
        ~LinkedList();
        bool operator==( const List<T>& ) const;
        bool operator!=( const List<T>& ) const;
        List<T>& operator=( const List<T>& );
        List<T>& operator+=( const T data );
        T& operator[]( std::size_t index );
        T& operator[]( std::size_t index ) const;
        List<T>& operator+( const List<T>& ) const;
        List<T>& operator+=( const List<T>& );
        void push_forward( const T );
        void push_back( const T );
        void insert( std::size_t index, const T );
        T extract_head();
        T extract_tail();
        T extract_index( std::size_t ind );
        T extract_value( T value );
        std::size_t getLength() const;

    template <typename U>
    friend LinkedList<U>& operator+=( const U& data, const LinkedList<U>& );
    template <typename U>
    friend std::ostream& 
        operator<<( std::ostream& stream, const LinkedList<U>& );
};

using namespace std;

template <typename T>
Node<T>::Node( const T& data, Node<T> *next )
{
    this->data = new T;
    *(this->data) = data;
    this->next = next;
}

template <typename T>
Node<T>::~Node()
{
    delete data;
}

template <typename T>
Node<T>& Node<T>::operator=( const Node<T>& n )
{
    delete data;
    data = new T;
    *data = *(n.data);
}

template <typename T>
LinkedList<T>::LinkedList() : head(NULL), tail(NULL), length(0) {}

template <typename T>
LinkedList<T>::LinkedList( const LinkedList<T>& l )
{
    if (l.head == NULL)
    {
        head = NULL;
        tail = NULL;
        length = 0;
        return;
    }

    head = new Node<T>(*(l.head->data));
    tail = head;
    length = 1;
    
    for (Node<T> *ptr = l.head->next; ptr != NULL; ptr = ptr->next)
    {
        tail->next = new Node<T>(*(ptr->data));
        tail = tail->next; 
        length++;
    } 
}

template <typename T>
void LinkedList<T>::clear()
{
    if (head == NULL)
    {
        return;
    }

    Node<T> *ptr = head;
    Node<T> *next = ptr->next;

    while (ptr != NULL)
    {
        delete ptr;
        ptr = next;
        if (next != NULL)
        {
            next = next->next;
        }
    }
}

template <typename T>
List<T>& LinkedList<T>::operator=( const List<T>& l )
{
    clear();
    if (l.getLength() == 0)
    {
        head = NULL;
        tail = NULL;
        length = 0;
        return *this;
    }

    head = new Node<T>(l[0]);
    tail = head;

    for (size_t ind = 1; ind < l.getLength(); ind++)
    {
        tail->next = new Node<T>(l[ind]);
        tail = tail->next;
    }
    
    length = l.getLength();

    return *this;
}

template <typename T>
bool LinkedList<T>::operator==( const List<T>& l ) const
{
    if (l.getLength() != length)
        return false;

    Node<T> *ptr1 = head;
    
    for (size_t ind = 0; ind < length; ind++)
    {
        if (*(ptr1->data) != l[ind])
        {
            return false;
        }
        ptr1 = ptr1->next;
    }

    return true;
}

template <typename T>
bool LinkedList<T>::operator!=( const List<T>& l ) const
{
    return !(*this == l);
}

template <typename T>
void LinkedList<T>::push_forward( const T data )
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
        length++;
        return;
    }
    tail->next = new Node(data);
    tail = tail->next;
    length++;
}

template <typename T>
void LinkedList<T>::push_back( const T data )
{
    Node<T> *ptr = head;
    head = new Node(data);
    head->next = ptr;
}

template <typename T>
List<T>& LinkedList<T>::operator+=( const T data )
{
    push_forward(data);
    return *this;
}

template <typename T>
LinkedList<T>& operator+=( const T& data, LinkedList<T>& l )
{
    l.push_back(data);
    return l;
}

template <typename T>
T& LinkedList<T>::operator[]( std::size_t index )
{
    Node<T>* resptr = head;
    for (std::size_t i = 0; i < index; i++)
    {
        if (resptr->next == NULL)
        {
            break;
        }
        resptr = resptr->next;
    }

    return *(resptr->data);
}

template <typename T>
T& LinkedList<T>::operator[]( std::size_t index ) const
{
    Node<T>* resptr = head;
    for (std::size_t i = 0; i < index; i++)
    {
        if (resptr->next == NULL)
        {
            break;
        }
        resptr = resptr->next;
    }

    return *(resptr->data);
}

template <typename T>
void LinkedList<T>::insert( std::size_t index, const T data )
{
    if (head == NULL || index == 0)
    {
        push_back(data);
        return;
    }

    if (index >= length)
    {
        push_forward(data);
        return;
    }

    Node<T> *prev = head;
    Node<T> *cur = head->next;

    for (std::size_t i = 0; i < index - 1; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = new Node(data);
    prev->next->next = cur;
    length++;
}

template <typename T>
List<T>& LinkedList<T>::operator+=( const List<T>& l )
{
    for (size_t ind = 0; ind < l.getLength(); ind++)
    {
        this->tail->next = new Node(l[ind]);
        this->tail = this->tail->next;
        this->length++;
    }
    return *this;
}

template <typename T>
List<T>& LinkedList<T>::operator+( const List<T>& l ) const
{
    static LinkedList<T> res = *this;
    res += l;
    return res;
}

template <typename T>
T LinkedList<T>::extract_head()
{
    if (head == NULL)
    {
        throw "Can not extract an element: list is empty";
    }

    Node<T> *ptr = head->next;
    T data = *(head->data);
    delete head;
    length--;
    head = ptr;
    return data;
}

template <typename T>
T LinkedList<T>::extract_tail()
{
    if (head == NULL)
    {
        throw "Can not extract an element by index: list is empty";
    }
    if (head == tail)
    {
        return extract_head();
    }

    Node<T> *ptr = head;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    T data = *(ptr->next->data);
    delete ptr->next;
    length--;
    tail = ptr;
    tail->next = NULL;
    return data;
}

template <typename T>
T LinkedList<T>::extract_index( std::size_t index )
{
    if (head == NULL)
    {
        throw "Can not extract an element by index: list is empty";
    }

    if (index == 0)
    {
        return extract_head();
    }

    if (index >= length - 1)
    {
        return extract_tail();
    }

    Node<T> *prev = NULL;
    Node<T> *cur = head;

    for (std::size_t i = 0; i < index; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    T data = *(cur->data);
    delete cur;
    length--;
    return data;
}

template <typename T>
T LinkedList<T>::extract_value( T value )
{
    if (head == NULL)
    {
        throw "Can not extract an element by value: list is empty";
    }

    Node<T>* prev = head;
    Node<T> *cur = head;

    while (cur != NULL)
    {
        if (*(cur->data) == value)
        {
            prev->next = cur->next;
            T data = *(cur->data);
            delete cur;
            length--;
            return data;
        }
        prev = cur;
        cur = cur->next;
    }

    throw "An element with value wasn't found.";
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
size_t LinkedList<T>::getLength() const
{
    return length;
}

template <typename T>
std::ostream& operator<<( std::ostream& stream, const LinkedList<T>& l )
{
    stream << "[ ";
    for (Node<T> *ptr = l.head; ptr != l.tail; ptr = ptr->next)
    {
        stream << *(ptr->data) << ", ";
    }
    stream << *(l.tail->data) << " ]";

    return stream;
}
