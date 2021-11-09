#include <cstdlib>
#include <cstring> //memcpy
#include <ostream>

#include "ArrayList.h"

using namespace std;

template <typename T>
ArrayList<T>::ArrayList( size_t capacity )
{
    this->capacity = capacity;
    count = 0;
    arr = (T *)malloc(sizeof(T) * capacity);
}

template <typename T>
ArrayList<T>::ArrayList( const ArrayList<T>& l )
{
    capacity = l.capacity;
    count = l.count;
    arr = (T *)malloc(sizeof(T) * capacity);
    memcpy(arr, l.arr, sizeof(T) * capacity);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    free(arr);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=( const ArrayList<T>& l )
{
    capacity = l.capacity;
    count = l.count;
    arr = (T *)realloc(arr, sizeof(T) * capacity);
    memcpy(arr, l.arr, sizeof(T) * capacity);
    
    return *this;
}

template <typename T>
bool ArrayList<T>::operator==( const ArrayList<T>& l ) const
{
    if (count != l.count)
    {
        return false;
    }

    for (size_t ind = 0; ind < count; ind++)
    {
        if (arr[ind] != l.arr[ind])
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
    arr = (T *)realloc(arr, capacity * sizeof(T));
}

template <typename T>
void ArrayList<T>::expand( size_t size )
{
    capacity += size;
    arr = (T *)realloc(arr, capacity * sizeof(T));
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
ArrayList<T>& ArrayList<T>::operator+=( const T obj )
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
ArrayList<T>& ArrayList<T>::operator+=( const ArrayList<T>& l )
{
    if (count + l.count > capacity)
    {
        expand(l.count);
    }
    memcpy(arr + count, l.arr, l.count * sizeof(T));
    count += l.count;
    return *this;
}

template <typename T>
T& ArrayList<T>::operator[]( size_t index )
{
    if (index < 0)
    {
        index = 0;
    }
    if (index >= count)
    {
        index = count;
        if (count > capacity)
        {
            expand();
        }
        count++;
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
    memmove(arr + 1, arr, (count++) * sizeof(T));
    arr[0] = obj;
}

template <typename T>
void ArrayList<T>::insert( size_t index, T obj )
{
    if (count >= capacity)
    {
        expand();
    }
    memmove(arr + index + 1, arr + index, (count++ - index) * sizeof(T));
    arr[index] = obj;
}

template <typename T>
void ArrayList<T>::extract_index( size_t index )
{
    if (index < 0 || index >= count)
    {
        return;
    }

    memmove(arr + index, arr + index + 1, (count-- - index - 1) * sizeof(T));
}

template <typename T>
void ArrayList<T>::extract_value( T value )
{
    if (count <= 0)
    {
        return;
    }

    for (size_t index = 0; index < count; index++)
    {
        if (value == arr[index])
        {
            extract_index(index);
            return;
        }
    }
}
