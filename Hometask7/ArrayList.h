#pragma once

#include <ostream>
#include <cstdlib>

template <typename T> 
class ArrayList
{
    public:
        ArrayList();
        ArrayList( std::size_t capacity ); 
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
        T& operator[]( std::size_t index );
        void insert( std::size_t index, const T );
        void extract_index( std::size_t index );
        void extract_value( T value );
        template <typename U>
            friend std::ostream& 
                operator<<( std::ostream&, const ArrayList<U>& );

        std::size_t getLength();
        
    private:
        std::size_t capacity;
        std::size_t count;

        void expand();
        void expand( size_t );
        T* arr;
};

using namespace std;

template <typename T>
ArrayList<T>::ArrayList()
{
    this->capacity = 4;
    count = 0;
    arr = new T[capacity];
}

template <typename T>
ArrayList<T>::ArrayList( size_t capacity )
{
    this->capacity = capacity;
    count = 0;
    arr = new T[capacity];
}

template <typename T>
void copy( size_t count, T* dst, T* src)
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
    copy(count, arr, l.arr);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] arr;
}

template <typename T>
size_t ArrayList<T>::getLength()
{
    return count;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=( const ArrayList<T>& l )
{
    capacity = l.capacity;
    count = l.count;
    delete[] arr;
    arr = new T[capacity];
    copy(count, arr, l.arr);
    
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
    for (size_t i = 0; i < l.count; i++)
    {
        arr[count + i] = l.arr[i];
    }
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
void ArrayList<T>::extract_index( size_t index )
{
    if (index < 0 || index >= count)
    {
        return;
    }

    copy(count-- - index - 1, arr + index, arr + index + 1);
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
