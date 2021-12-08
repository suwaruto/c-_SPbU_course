#include <cstddef>
#include <ostream>

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
LinkedList<T>& LinkedList<T>::operator=( const LinkedList<T>& l )
{
    clear();
    if (l.head == NULL)
    {
        head = NULL;
        tail = NULL;
        length = 0;
        return *this;
    }

    head = new Node<T>(l.head->data);
    tail = head;
    
    for (Node<T> *ptr = l.head->next; ptr != NULL; ptr = ptr->next)
    {
        tail->next = new Node<T>(ptr->data);
        tail = tail->next; 
    } 

    length = l.length;

    return *this;
}

template <typename T>
bool LinkedList<T>::operator==( const LinkedList<T>& l ) const
{
    if (l.length != length)
        return false;

    Node<T> *ptr1 = head;
    Node<T> *ptr2 = l.head;

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
bool LinkedList<T>::operator!=( const LinkedList<T>& l ) const
{
    return !(l == *this);
}

template <typename T>
void LinkedList<T>::push_forward( const T& data )
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
void LinkedList<T>::push_back( const T& data )
{
    Node<T> *ptr = head;
    head = new Node(data);
    head->next = ptr;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator+=( const T& data )
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
void LinkedList<T>::insert( const T& data, std::size_t index )
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
LinkedList<T> LinkedList<T>::operator+( const LinkedList<T>& l ) const
{
    LinkedList<T> res = *this;
    LinkedList<T> tmp = l;
    res.tail->next = tmp.head;
    res.tail = tmp.tail;
    tmp.head = NULL;
    res.length = this->length + tmp.length;
    return res;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator+=( const LinkedList<T>& l )
{
    LinkedList<T> tmp = l;
    this->tail->next = tmp.head;
    this->tail = tmp.tail;
    tmp.head = NULL;
    this->length += tmp.length;
    return *this;
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
T LinkedList<T>::extract_ind( std::size_t index )
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
LinkedList<T>::~LinkedList()
{
    clear();
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
