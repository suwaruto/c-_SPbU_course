#pragma once

#include <ostream>
#include <cstdlib>

template <typename T> 
class List
{
    public:
        virtual ~List() {};
        virtual List& operator=( const List& ) = 0;
        virtual bool operator==( const List& ) const = 0;
        virtual void push_forward( const T ) = 0;
        virtual void push_back( const T ) = 0;
        virtual List& operator+=( const T ) = 0;
        virtual List& operator+=( const List& ) = 0;
        virtual List& operator+( const List& ) const = 0;
        virtual T& operator[]( size_t index ) const = 0;
        virtual T& operator[]( size_t index ) = 0;
        virtual void insert( size_t index, const T ) = 0;
        virtual T extract_index( size_t index ) = 0;
        virtual T extract_value( T value ) = 0;
        template <typename U>
            friend std::ostream& 
                operator<<( std::ostream&, const List<U>& );

        virtual std::size_t getLength() const = 0;
};

template <typename T>
std::ostream& operator<<( std::ostream& stream, const List<T>& l )
{
    stream << "[" << l.getLength() << "] {";
    if (l.getLength() > 0)
    {
        for (size_t ind = 0; ind < l.getLength() - 1; ind++)
        {
            stream << l[ind] << "; ";
        }
        stream << l[l.getLength() - 1];
    }
    stream << "}";
    return stream;
}
