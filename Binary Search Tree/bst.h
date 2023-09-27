#pragma once

#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>

#include "vectorsetoperations.h"

  template <typename T>
  class Set;

  template <typename T>
  class Node
  {
    private: 
      Node *left;
      Node *right;
      T data;

      Node( T );
      ~Node( );
      bool isLeaf( );
    
    friend class Set<T>;
    template <typename U>
      friend std::ostream& operator<<( std::ostream& stream, const Set<U>& s );
    template <typename U>
      friend Set<U> sortedVectorToSet( std::vector<U>& src );
  };

  template <typename T>
  class Set
  {
    private:
      Node<T> *head;
      std::size_t length;
      Node<T> *lookForNode( T element, char& pos ); 
      void free();
      void copy( const Set<T>& src );

    public:
      Set( );
      ~Set( );
      Set( const Set<T>& src );
      bool isIn( T data ) const;
      void addElement( T data );
      std::vector<T> toSortedVector() const;
      Set<T> operator=( const Set<T>& src );

    template <typename U>
      friend std::ostream& operator<<( std::ostream& stream, const Set<U>& s );
    template <typename U>
      friend Set<U> sortedVectorToSet( std::vector<U>& src );
    template <typename U>
      friend Set<U> GetIntersection( const Set<U>& s1, const Set<U>& s2 );
    template <typename U>
      friend Set<U> GetUnion( const Set<U>& s1, const Set<U>& s2 );
    template <typename U>
      friend Set<U> GetDifference( const Set<U>& s1, const Set<U>& s2 );
  };

template <typename T>
Node<T>::Node( T data )
{
  this->data = data;
  left = NULL;
  right = NULL;
}

template <typename T>
Node<T>::~Node( )
{
}

template <typename T>
bool Node<T>::isLeaf( )
{
  return (this->left == NULL) && (this->right == NULL);
}

template <typename T>
Set<T>::Set( )
{
  head = NULL;
  length = 0;
}

template <typename T>
Node<T> *Set<T>::lookForNode( T data, char &pos )
{
  Node<T> *res = head;
  while (true)
  {
    if (res->data == data)
    {
      pos = 0;
      return res;
    }
    else if (res->data > data)
    {
      if (res->left == NULL)
      {
        pos = -1;
        return res;
      }
      else
        res = res->left; 
    }
    else if (res->data < data)
    {
      if (res->right == NULL)
      {
        pos = 1;
        return res;
      }
      else
        res = res->right;
    }
  }
}

template <typename T>
void Set<T>::addElement( T data )
{
  if (this->head == NULL)
  {
    head = new Node(data);
    length++;
    return;
  }
  char pos = 0; 
  Node<T> *insertAt = lookForNode(data, pos);
  if (pos == -1)
  {
    length++;
    insertAt->left = new Node(data);
  }
  if (pos == 1)
  {
    length++;
    insertAt->right = new Node(data);
  }
  if (pos == 0)
    ;
}

template <typename T>
bool Set<T>::isIn( T data ) const
{
    if (head == NULL)
      return false;
    char pos = 0;
    Node<T> *tmp = lookForNode(data, pos);
    if (pos == 0) return true; else return false;
}

template <typename T>
std::vector<T> Set<T>::toSortedVector() const
{
  std::vector<T> res;
  std::stack<Node<T> *> st;
  st.push(head);
  while (!st.empty())
  {
    Node<T> * cur = st.top();
    while (cur != NULL)
    {
      cur = cur->left;
      st.push(cur);
    }
    st.pop();
    if (!st.empty() && st.top() != NULL)
    {
      cur = st.top();
      res.push_back(cur->data);
      st.pop();
      st.push(cur->right);
    }
  }
  return res;
}

template <typename T>
Set<T> sortedVectorToSet( std::vector<T>& src )
{
  Set<T> res;
  if (src.empty())
    return res;
  std::queue<std::pair<Node<T> *, std::pair<int, int>>> q;

  int first = 0, last = src.size() - 1, mid = (first + last) >> 1;
  res.head = new Node(src[mid]);
  res.length++;
  q.push({res.head, {first, mid - 1}});
  q.push({res.head, {mid + 1, last}});

  while (!q.empty())
  {
    std::pair<Node<T> *, std::pair<int, int>> cur = q.front(); 
    q.pop();

    Node<T> *parent = cur.first;
    first = cur.second.first;
    last = cur.second.second;

    if (first <= last && parent != NULL)
    {
      mid = (first + last) >> 1;
      Node<T> *child = new Node(src[mid]);

      if (src[mid] < parent->data)
        parent->left = child;
      else
        parent->right = child;
      res.length++;

      q.push({child, {first, mid - 1}});
      q.push({child, {mid + 1, last}});
    }
  }

  return res;
}

template <typename T>
Set<T> GetIntersection( const Set<T>& s1, const Set<T>& s2 )
{
  std::vector<T> v = intersect(s1.toSortedVector(), s2.toSortedVector());

  return sortedVectorToSet(v);
}

template <typename T>
Set<T> GetUnion( const Set<T>& s1, const Set<T>& s2 )
{
  std::vector<T> v = unite(s1.toSortedVector(), s2.toSortedVector());

  return sortedVectorToSet(v);
}

template <typename T>
Set<T> GetDifference( const Set<T>& s1, const Set<T>& s2 )
{
  std::vector<T> v = substract(s1.toSortedVector(), s2.toSortedVector());

  return sortedVectorToSet(v);
}

template <typename T>
std::ostream& operator<<( std::ostream& stream, const Set<T>& s )
{
  std::stack<Node<T> *> st;
  stream << '[' << s.length << ']' << '{';
  st.push(s.head);
  while (!st.empty())
  {
    Node<T> * cur = st.top();
    while (cur != NULL)
    {
      cur = cur->left;
      st.push(cur);
    }
    st.pop();
    if (!st.empty() && st.top() != NULL)
    {
      stream << st.top()->data << " ; ";
      cur = st.top();
      st.pop();
      st.push(cur->right);
    }
  }
  stream << '}';
  return stream;
}

template <typename T>
void Set<T>::copy( const Set<T>& src )
{
  free();
  if (src.head == NULL)
    return;
  std::queue<std::pair<Node<T> *, Node<T> *>> q;
  head = new Node(src.head->data);
  length++;
  q.push({src.head, head});

  while (!q.empty())
  {
    std::pair<Node<T> *, Node<T> *> cur = q.front();
    q.pop();

    if (cur.first->left != NULL)
    {
      cur.second->left = new Node(cur.first->left->data);
      length++;
      q.push({cur.first->left, cur.second->left});
    }

    if (cur.first->right != NULL)
    {
      cur.second->right = new Node(cur.first->right->data);
      length++;
      q.push({cur.first->right, cur.second->right});
    }
  }
}

template <typename T>
Set<T>::Set( const Set<T>& src )
{
  head = NULL;
  copy(src); 
}

template <typename T>
Set<T> Set<T>::operator=( const Set<T>& src )
{
  copy(src);
  return *this;
}

template <typename T>
void Set<T>::free()
{
  length = 0;
  if (head == NULL)
    return;
  std::queue<Node<T> *> q;
  q.push(head);
  head = NULL;

  while (!q.empty())
  {
    Node<T> *cur = q.front();
    q.pop();
    if (cur != NULL)
    {
      q.push(cur->left);
      q.push(cur->right);
      delete cur;
    }
  }
}

template <typename T>
Set<T>::~Set( )
{
  free();
}
