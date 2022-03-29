#pragma once

#include "List.h"

template <typename T> 
class ArrayList : public List<T>
{
    public:
        ArrayList( std::size_t capacity = 4 ); 
        ArrayList( const ArrayList& l );
        ~ArrayList();
        List<T>& operator=( const List<T>& );
        bool operator==( const List<T>& ) const;
        void push_forward( const T );
        void push_back( const T );
        List<T>& operator+=( const T );
        List<T>& operator+=( const List<T>& );
        List<T>& operator+( const List<T>& ) const;
        template <typename U>
        friend ArrayList<U>& operator+=( U, ArrayList<U>& );
        T& operator[]( size_t index );
        T& operator[]( size_t index ) const;
        void insert( size_t index, const T );
        T extract_index( size_t index );
        T extract_value( T value );
        template <typename U>
            friend std::ostream& 
                operator<<( std::ostream&, const ArrayList<U>& );

        std::size_t getLength() const;
        
    private:
        std::size_t capacity;
        std::size_t count;

        void expand();
        void expand( size_t );
        T* arr;
};

using namespace std;

template <typename T>
ArrayList<T>::ArrayList( size_t capacity )
{
    this->capacity = capacity;
    count = 0;
    arr = new T[capacity];
}

template <typename T>
void copy( size_t count, T* dst, const T* src )
{
    for (int i = 0; i < count; i++)
    {
        dst[i] = src[i];
    }
}

template <typename T>
void copy( size_t count, T* dst, const List<T>& src )
{
    for (int i = 0; i < count; i++)
    {
        dst[i] = src[i];
    }
}

template <typename T>
ArrayList<T>::ArrayList( const ArrayList<T>& l )
{
    capacity = l.capacity;
    count = l.count;
    arr = new T[capacity];
    copy(count, arr, l);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] arr;
}

template <typename T>
size_t ArrayList<T>::getLength() const
{
    return count;
}

template <typename T>
List<T>& ArrayList<T>::operator=( const List<T>& l )
{
    capacity = l.getLength();
    count = l.getLength();
    delete[] arr;
    arr = new T[capacity];
    copy(count, arr, l);
    
    return *this;
}

template <typename T>
bool ArrayList<T>::operator==( const List<T>& l ) const
{
    if (count != l.getLength())
    {
        return false;
    }

    for (size_t ind = 0; ind < count; ind++)
    {
        if (arr[ind] != l[ind])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
ostream& operator<<( ostream& stream, const ArrayList<T>& l )
{
    stream << "[" << l.count << "/" << l.capacity << "] {";
    if (l.count > 0)
    {
        for (size_t ind = 0; ind < l.count - 1; ind++)
        {
            stream << l.arr[ind] << "; ";
        }
        stream << l.arr[l.count - 1];
    }
    stream << "}";
    return stream;
}

template <typename T>
void ArrayList<T>::expand()
{
    capacity *= 2;
    T* tmp = new T[capacity];
    copy(count, tmp, arr);
    delete[] arr;
    arr = tmp;
}

template <typename T>
void ArrayList<T>::expand( size_t size )
{
    capacity += size;
    T* tmp= new T[capacity];
    copy(count, tmp, arr);
    delete[] arr;
    arr = tmp;
}

template <typename T>
void ArrayList<T>::push_back( T obj )
{
    if (count >= capacity)
    {
        expand();
    }
    arr[count++] = obj;
}

template <typename T>
List<T>& ArrayList<T>::operator+=( const T obj )
{
    push_back(obj);
    return *this;
}

template <typename T>
ArrayList<T>& operator+=( const T obj, ArrayList<T>& l )
{
    l.push_forward(obj);
    return l;
}

template <typename T>
List<T>& ArrayList<T>::operator+=( const List<T>& l )
{
    if (count + l.getLength() > capacity)
    {
        expand(l.getLength());
    }
    for (size_t i = 0; i < l.getLength(); i++)
    {
        arr[count + i] = l[i];
    }
    count += l.getLength();
    return *this;
}

template <typename T>
List<T>& ArrayList<T>::operator+( const List<T>& l ) const
{
    static ArrayList<T> res = *this;
    res += l;
    return res;
}

template <typename T>
T& ArrayList<T>::operator[]( size_t index ) 
{
    if (index < 0)
    {
        throw "Out of list bounds.";
    }
    if (index >= count)
    {
        throw "Out of list bounds.";
    }
    return arr[index];
}

template <typename T>
T& ArrayList<T>::operator[]( size_t index ) const
{
    if (index < 0)
    {
        throw "Out of list bounds.";
    }
    if (index >= count)
    {
        throw "Out of list bounds.";
    }
    return arr[index];
}

template <typename T>
void ArrayList<T>::push_forward( T obj )
{
    if (count >= capacity)
    {
        expand();
    }
    T* tmp = new T[capacity];
    tmp[0] = obj;
    copy(count++, tmp + 1, arr);
    delete[] arr;
    arr = tmp;
}

template <typename T>
void ArrayList<T>::insert( size_t index, T obj )
{
    if (count >= capacity)
    {
        expand();
    }
    if (index >= count)
    {
        push_back(obj);
    }
    else
    {
        T* tmp = new T[capacity];
        tmp[index] = obj;
        copy(index, tmp, arr);
        copy(count - index, tmp + index + 1, arr + index);
        delete[] arr; 
        arr = tmp;
        count++;
    }
}

template <typename T>
T ArrayList<T>::extract_index( size_t index )
{
    if (index < 0 || index >= count)
    {
        throw "Out of list bounds.";
    }

    T res = arr[index];

    copy(count-- - index - 1, arr + index, arr + index + 1);
    return res;
}

template <typename T>
T ArrayList<T>::extract_value( T value )
{
    if (count <= 0)
    {
        throw "Search by value is not possible: list is empty.";
    }

    for (size_t index = 0; index < count; index++)
    {
        if (value == arr[index])
        {
            return extract_index(index);
        }
    }
    throw "An element with value was not found."; 
}
