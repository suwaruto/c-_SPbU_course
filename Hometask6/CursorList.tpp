#include <cstddef>

template <typename T>
Node<T>::Node( const T& data, Node *next )
{
    this->data = new T;
    *(this->data) = data;
    this->next = next;
}

template <typename T>
Node<T>::Node() : data(NULL), next(NULL)
{
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
    next = NULL;
    return *this;
}

template <typename T>
CursorList<T>::CursorList( std::size_t capacity )
{
    arr = new Node<T>[capacity];
    this->capacity = capacity;
    head = NULL;
    tail = head;
    link_count = 0;
    arr_count = 0;
}

/*
template <typename T>
void CursorList<T>::copy_arr( const Node<T> *src_head )
{
    if (link_count > 0)
    {
        const Node<T> *n = src_head;
        std::size_t i = 0;
        while (i < link_count - 1)
        {
            arr[i] = *n;
            n = n->next;
            arr[i].next = &arr[i + 1];
            i++;
        }
        arr[i] = *n;
    }
}
*/

template <typename T>
void CursorList<T>::copy_arr( const Node<T> *src_head )
{
    delete[] arr;
    arr = new Node<T>[capacity];
    head = tail = NULL;
    link_count = 0;

    const Node<T> *n = src_head;
    while (n != NULL)
    {
        arr[link_count] = *n;
        arr[link_count].next = arr + link_count + 1;
        link_count++;
        n = n->next;
    }

    if (link_count > 0)
    {
        arr[link_count - 1].next = NULL;
        head = arr;
        tail = arr + link_count - 1;
    }  

    arr_count = link_count;
}

template <typename T>
CursorList<T>::CursorList( const CursorList<T>& l )
{
    arr = NULL;
    capacity = l.capacity;

    copy_arr(l.head);
}

template <typename T>
CursorList<T>::~CursorList()
{
    delete[] arr;
}

template <typename T>
bool CursorList<T>::operator==( const CursorList<T>& l ) const
{
    if (link_count != l.link_count)
    {
        return false;
    }
    if (link_count == 0)
    {
        return true;
    }

    Node<T> ptr1 = head;
    Node<T> ptr2 = l.head;

    while (ptr1 != NULL)
    {
        if (*(ptr1->data) != *(ptr2->data))
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

template <typename T>
bool CursorList<T>::operator!=( const CursorList<T>& l ) const
{
    return !(*this == l);
}

template <typename T>
CursorList<T>& CursorList<T>::operator=( const CursorList<T>& l )
{
    capacity = l.capacity;

    copy_arr(l.head);
    return *this;
}

template <typename T>
void CursorList<T>::expand()
{
    CursorList<T> tmp = *this;
    tmp.capacity *= 2;
    tmp.copy_arr(head);
    *this = tmp;
}

template <typename T>
void CursorList<T>::expand( std::size_t size )
{
    CursorList<T> tmp = *this;
    tmp.capacity += size;
    tmp.copy_arr(head);
    *this = tmp;
}

/*
template <typename T>
void CursorList<T>::expand()
{
    Node<T> src[capacity] = arr;
    capacity *= 2;
    Node<T> *old_head = head;
    arr = new Node<T>[capacity];
    head = &arr[0];
    tail = head;

    copy_arr(old_head);

    delete[] old_arr;
}*/

template <typename T>
void CursorList<T>::push_empty_list( const T& data )
{
    if (capacity == 0)
    {
        expand(1);
    }
        
    head = tail = &arr[0];
    delete tail->data;
    tail->data = new T;
    *(tail->data) = data;
    link_count++;
    arr_count++;
}

template <typename T>
void CursorList<T>::push_back( const T& data )
{
    if (arr_count == capacity)
    {
        expand();
    }
    if (head == NULL)
    {
        push_empty_list(data);
    }
    else
    {
        tail->next = &arr[arr_count++];
        tail = tail->next;
        delete tail->data;
        tail->data = new T;
        *(tail->data) = data;
        link_count++;
    }
}

template <typename T>
void CursorList<T>::push_forward( const T& data )
{
    if (arr_count == capacity)
    {
        expand();
    }
    if (head == NULL)
    {
        push_empty_list(data);
    }
    else
    {
        arr[arr_count].next = head;
        head = &arr[arr_count++];
        delete head->data;
        head->data = new T;
        *(head->data) = data;
        link_count++;
    }
}

template <typename T>
std::ostream& operator<<( std::ostream& stream, const CursorList<T>& l )
{
    stream << "[ ";
    for (Node<T> *ptr = l.head; ptr != l.tail; ptr = ptr->next)
    {
        stream << *(ptr->data) << ", ";
    }
    stream << *(l.tail->data) << " ]";

    return stream;
}

template <typename T>
void CursorList<T>::insert( const T& data, std::size_t index )
{
    if (arr_count == capacity)
    {
        expand();
    }

    if (link_count == 0 || index == 0)
    {
        push_forward(data);
        return;
    }

    if (index >= link_count)
    {
        push_back(data);
        return;
    }

    Node<T> *prev = head;
    Node<T> *cur = head->next;

    for (std::size_t i = 0; i < index - 1; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    arr[arr_count].data = new T;
    *(arr[arr_count].data) = data;
    arr[arr_count].next = cur;
    prev->next = &arr[arr_count++];
    link_count++;
}

template <typename T>
CursorList<T>& CursorList<T>::operator+=( const T& data )
{
    push_back(data);
    return *this;
}

template <typename T>
T& CursorList<T>::operator[]( std::size_t index )
{
    if (head == NULL)
    {
        throw "Can not return value: list is empty";
    }

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
CursorList<T> CursorList<T>::operator+( const CursorList<T>& l ) const
{
    CursorList<T> res(link_count + l.link_count);
    tail->next = l.head;
    res.copy_arr(head);
    tail->next = NULL;
    
    return res;
}

template <typename T>
CursorList<T>& CursorList<T>::operator+=( const CursorList<T>& l )
{
    Node<T> *ptr = l.head;
    while (ptr != NULL)
    {
        push_back(*(ptr->data));
        ptr = ptr->next;
    }

    return *this;
}

template <typename T>
T CursorList<T>::extract_head()
{
    if (head == NULL)
    {
        throw "Can not extract an element: list is empty";
    }

    T data = *(head->data);
    head->next;
    head = head->next;
    link_count--;
    return data;
}

template <typename T>
T CursorList<T>::extract_tail()
{
    if (tail == NULL)
    {
        throw "Can not extract an element: list is empty";
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
    ptr->next = NULL;
    tail = ptr;
    link_count--;
    return data;
}

template <typename T>
T extract_ind( std::size_t ind );
{
    if (head == NULL)
    {
        throw "Can not extract an element by index: list is empty";
    }

    if (index == 0)
    {
        return extract_head();
    }

    if (index >= link_count - 1)
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
    link_count--;
    return data;
}
