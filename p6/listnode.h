

#ifndef LISTNODE_H
#define LISTNODE_H
#include "appt.h"

// forward declartion
template <typename T> class LinkedList;
template <typename T> class ListNode;


template <typename T>
std::ostream & operator<<(std::ostream &, const ListNode<T> &);

template<typename T>
class ListNode {

    friend class LinkedList<T>;
    friend std::ostream & operator<< <T>(std::ostream &, const ListNode<T> &);

    T        object;
    ListNode *next;

private:
    ListNode(T, ListNode *);
    ~ListNode();
};



#include "listnode.cpp"
#endif
