#pragma once

#include <ostream>
#include <cstddef>

template <typename T>
class ArrayList
{
    public:
        ArrayList( std::size_t capacity = 16 ); 
        ArrayList( const ArrayList& l );
        ~ArrayList();
        ArrayList& operator=( const ArrayList& );
        bool operator==( const ArrayList& ) const;
        void push_forward( const T );
        void push_back( const T );
        ArrayList& operator+=( const T );
        ArrayList& operator+=( const ArrayList& );
        template <typename U>
        friend ArrayList<U>& operator+=( U, ArrayList<U>& );
        T& operator[]( size_t index );
        void insert( size_t index, const T );
        void extract_index( size_t index );
        void extract_value( T value );
        template <typename U>
            friend std::ostream& 
                operator<<( std::ostream&, const ArrayList<U>& );
        
    private:
        T *arr;
        std::size_t capacity;
        std::size_t count;

        void expand();
        void expand( size_t );
};

#include "ArrayList.tpp"
