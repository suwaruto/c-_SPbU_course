#pragma once

#include <cstddef>
#include <ostream>

template<typename T>
class CursorList;

template <typename T>
class Node
{
    private:
        T *data;
        Node *next;

        Node();
        Node( const T& data, Node *next = NULL );
        Node& operator=( const Node& );
        ~Node();

    friend class CursorList<T>;
    template <typename U>
    friend std::ostream& 
        operator<<( std::ostream& stream, const CursorList<U>& );
};

template <typename T>
class CursorList
{
    private:
        Node<T> *head;
        Node<T> *tail;
        std::size_t link_count;
        std::size_t arr_count;
        std::size_t capacity;
        Node<T> *arr;

        void copy_arr( const Node<T> *src_head );
        void push_empty_list( const T& );
        void expand();
        void expand( std::size_t );

    public:
        CursorList( std::size_t capacity = 4 );
        CursorList( const CursorList& );
        ~CursorList();
        bool operator==( const CursorList& ) const;
        bool operator!=( const CursorList& ) const;
        CursorList& operator=( const CursorList& );
        CursorList& operator+=( const T& data );
        T& operator[]( std::size_t index );
        CursorList operator+( const CursorList& ) const;
        CursorList& operator+=( const CursorList& );
        void push_forward( const T& );
        void push_back( const T& );
        void insert( const T&, std::size_t index );
        T extract_head();
        T extract_tail();
        T extract_ind( std::size_t ind );

    template <typename U>
    friend std::ostream& 
        operator<<( std::ostream& stream, const CursorList<U>& );
};

#include "CursorList.tpp"
