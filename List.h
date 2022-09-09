#pragma once

#include "Node.h"
#include <iostream>
#include <initializer_list>

using namespace std;

template<class T>
class List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:
    List();

    List(const initializer_list<T>& list);

    List(const List& obj);

    List(List&& obj);

    ~List();

    List& operator = (const List& obj);
    List& operator = (List&& obj);

    void push_back(const T& val);
    void push_front(const T& val);
    void push_index(const T& val, int index);
    


    void pop_front();
    void pop_back();
    void pop_index(int index);
    void pop_index_several(int index, int amount);

    int getSize() const;
    void print() const;
};

template<class T>
void List<T>::push_back(const T& val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template<class T>
inline void List<T>::push_front(const T& val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setNext(head);
        head = tmp;
    }
    size++;
}

template<class T>
inline void List<T>::push_index(const T& val, int index)
{
    if (index < 0 && index > size)
        return;
    if (index == 0)
        push_front(val);
    else if (index == size)
        push_back(val);
    else
    {
        auto tmp = new Node<T>(val);
        auto cur = head;
        while (index - 1 != 0)
        {
            cur = cur->getNext();
            index--;
        }
        tmp->setNext(cur->getNext());
        cur->setNext(tmp);
    }
    size++;
}


template<class T>
int List<T>::getSize() const
{
    return size;
}

template<class T>
void List<T>::print() const
{
    auto cur = head;
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

template<class T>
void List<T>::pop_front()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    auto tmp = head;
    head = head->getNext();
    delete tmp;
    size--;
}

template<class T>
inline void List<T>::pop_back()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    auto tmp = tail;
    tail = head;
    int count = size - 2;
    while (count != 0)
    {
        tail = tail->getNext();
        count--;
    }
    tail->setNext(nullptr);
    delete tmp;
    size--;
}

template<class T>
inline void List<T>::pop_index(int index)
{

    if (index < 0 && index > size)
        return;
    if (index == 0)
        pop_front();
    else if (index == size)
        pop_back();
    else
    {
        auto cur = head;
        while (index - 2 != 0)
        {
            cur = cur->getNext();
            index--;
        }
        auto tmp = cur->getNext();
        cur->setNext(tmp->getNext());
        delete tmp;
    }
    size--;
}

template<class T>
inline void List<T>::pop_index_several(int index, int amount)
{
    if (index < 0 && index > size && amount == 0)
        return;
    if (index == 0)
    {
        for (int i = 0; i < amount;i++)
        {
            pop_front();
        }
    }
    else if (index == size)
        pop_back();
    else
    {
        auto cur = head;
        while (index - 1 != 0)
        {
            cur = cur->getNext();
            index--;
        }
        auto tmp = cur->getNext();
        for (int i = 0; i < amount-1;i++)
        {
            auto tmp1 = tmp;
            tmp = tmp->getNext();
            delete tmp1;
            
        }
        cur->setNext(tmp->getNext());
        delete tmp;
    }
    size -= amount;
}

template<class T>
List<T>::~List()
{
    while (size != 0)
        pop_front();
}

template<class T>
inline List<T>& List<T>::operator=(const List& obj)
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    auto cur = obj.head;
    if (obj.head != nullptr)
    {
        while (cur != nullptr)
        {
            push_back(cur->getData());
            cur = cur->getNext();
        }
    }
    else cur = nullptr;
    return *this;
}

template<class T>
inline List<T>& List<T>::operator=(List&& obj)
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
    return *this;
}

template<class T>
List<T>::List(const List& obj)
{
    auto cur = obj.head;
    while (cur != nullptr)
    {
        push_back(cur->getData());
        cur = cur->getNext();
    }
}

template<class T>
List<T>::List(List&& obj)
{
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
}

template<class T>
List<T>::List(const initializer_list<T>& list)
{
    for (auto item : list)
    {
        push_back(item);
    }
}

template<class T>
List<T>::List() = default;



