#pragma once

#include <cstddef>
#include <ostream>

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    private:
        T data;
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
class LinkedList
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
        bool operator==( const LinkedList& ) const;
        bool operator!=( const LinkedList& ) const;
        LinkedList& operator=( const LinkedList& );
        LinkedList& operator+=( const T& data );
        T& operator[]( std::size_t index );
        LinkedList operator+( const LinkedList& ) const;
        LinkedList& operator+=( const LinkedList& );
        void push_forward( const T& );
        void push_back( const T& );
        void insert( const T&, std::size_t index );
        T extract_head();
        T extract_tail();
        T extract_ind( std::size_t ind );

    template <typename U>
    friend LinkedList<U>& operator+=( const U& data, const LinkedList<U>& );
    template <typename U>
    friend std::ostream& 
        operator<<( std::ostream& stream, const LinkedList<U>& );
};

#include "LinkedList.tpp"
