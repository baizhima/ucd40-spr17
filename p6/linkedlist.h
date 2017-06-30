#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listnode.h"

template <typename T>
class LinkedList;

template <typename T>
std::ostream & operator<<(std::ostream &, const LinkedList<T> &);

template <typename T>
class LinkedList {
    ListNode<T> *head;
public:
    LinkedList();
    ~LinkedList();
    LinkedList & operator=(const LinkedList &);
    const T operator[](int i) const;
    LinkedList & operator+=(T &);
    friend std::ostream & operator<< <T>(std::ostream &, const LinkedList<T> &);
    T find(const char *subject) const;
};

#include "linkedlist.cpp"

#endif
