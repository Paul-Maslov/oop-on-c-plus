#pragma once

template <class T>
class Node
{
    T data;
    Node<T>* next = nullptr;
public:
    Node(const T& val);
    T getData()const;
    Node<T>* getNext()const;
    void setData(const T& val);
    void setNext(Node<T>* n);
};

template<class T>
Node<T>::Node(const T& val)
{
    data = val;
}
template<class T>
T Node<T>::getData() const
{
    return data;
}
template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}
template<class T>
void Node<T>::setData(const T& val)
{
    data = val;
}
template<class T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}
