#include "linkedlist.h"
#include "appt.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(): head(NULL)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *ptr = head;
    while (ptr)
    {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
}

template <typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    ListNode<T> *ptr = head;
    while (ptr)
    {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    ListNode<T> *tail = NULL;
    for (ptr = rhs.head; ptr; ptr = ptr->next)
    {
        T object = ptr->object->clone();
        if (!tail)
        {
            tail = new ListNode<T>(object, NULL);
            head = tail;
        }
        else
        {
           tail->next = new ListNode<T>(object, NULL); 
           tail = tail->next;
        }
    }
    return *this;
}

template <typename T>
const T LinkedList<T>::operator[](int idx) const
{
    ListNode<T> *ptr = head;
    for (int i = 0; i < idx; i++)
    {
        ptr = ptr->next;
    }
    return ptr->object;
}

template <typename T>
LinkedList<T> & LinkedList<T>::operator+=(T &rhs)
{
    ListNode<T> *ptr = head;
    ListNode<T> *prev = NULL;

    if (!head)
    {
        head = new ListNode<T>(rhs, NULL);
    }
    else
    {
        while (ptr && *(ptr->object) < *rhs)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev)
        {
            prev->next = new ListNode<T>(rhs, ptr);
        }
        else
        {
            head = new ListNode<T>(rhs, ptr);
        }
    }
    return *this;
}


template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkedList<T> &objects)
{
    int count = 0 ;
    ListNode<T> *ptr = objects.head;
    while (ptr)
    {
        ptr->object->write(os);
        os << std::endl;
        ptr = ptr->next;
        count++;
    }
    return os;

}

template <typename T>
T LinkedList<T>::find(const char *subject) const
{
    static ListNode<T> *lastNode;
    static bool searched;
    if (!lastNode && !searched)
    {
        lastNode = head;
    }
    if (!lastNode)
    {
        searched = false;
        return NULL;
    }
    T object = lastNode->object;
    searched = true;
    lastNode = lastNode->next;
    return object;
}
