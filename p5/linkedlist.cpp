#include "linkedlist.h"
#include "appt.h"
#include <iostream>


LinkedList::LinkedList(): head(NULL)
{

}

LinkedList::~LinkedList()
{
    ListNode *ptr = head;
    while (ptr)
    {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
}

LinkedList & LinkedList::operator=(const LinkedList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    ListNode *ptr = head;
    while (ptr)
    {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    ListNode *tail = NULL;

    for (ptr = rhs.head; ptr; ptr = ptr->next)
    {
        Appointment *appt = new Appointment(*(ptr->appt));
        if (!tail)
        {
            tail = new ListNode(appt, NULL);
            head = tail;
        }
        else
        {
           tail->next = new ListNode(appt, NULL); 
           tail = tail->next;
        }
    }
    return *this;
}

const Appointment * LinkedList::operator[](int idx) const
{
    ListNode *ptr = head;
    for (int i = 0; i < idx; i++)
    {
        ptr = ptr->next;
    }
    return ptr->appt;
}

Appointment *& LinkedList::operator[](int idx)
{

    ListNode *ptr = head;
    ListNode *prev = NULL;
    for (int i = 0; i < idx; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr)
    {
        if (prev)
        {
            prev->next = new ListNode(NULL, NULL);
            ptr = prev->next;
        }
        else
        {
            head = new ListNode(NULL, NULL);
            ptr = head;
        }
    }
    return ptr->appt;
}

LinkedList & LinkedList::operator+=(Appointment *&rhs)
{
    ListNode *ptr = head;
    ListNode *prev = NULL;

    if (!head)
    {
        head = new ListNode(rhs, NULL);
    }
    else
    {
        while (ptr && *(ptr->appt) < *rhs)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev)
        {
            prev->next = new ListNode(rhs, ptr);
        }
        else
        {
            head = new ListNode(rhs, ptr);
        }
    }
    return *this;
}

std::ostream & operator<<(std::ostream &os, const LinkedList &appts)
{
    
    ListNode *ptr = appts.head;
    while (ptr)
    {
        os << *ptr->appt;
        ptr = ptr->next;
    }
    return os;

}

Appointment * LinkedList::find(const char *subject) const
{
    static ListNode *lastNode;
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
    Appointment *appt = lastNode->appt;
    searched = true;
    lastNode = lastNode->next;
    return appt;
}
