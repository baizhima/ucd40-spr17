#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listnode.h"

class LinkedList {
    ListNode *head;
public:
    LinkedList();
    ~LinkedList();
    LinkedList & operator=(const LinkedList &);
    const Appointment * operator[](int i) const;
    Appointment *& operator[](int i);
    LinkedList & operator+=(Appointment *&);
    friend std::ostream & operator<<(std::ostream &, const LinkedList &);
    Appointment * find(const char *subject) const;
};

#endif
