

#ifndef LISTNODE_H
#define LISTNODE_H
#include "appt.h"

class LinkedList;

class ListNode {
    Appointment *appt;
    ListNode *next;

    friend class LinkedList;
    friend std::ostream & operator<<(std::ostream &, const LinkedList &);

private:
    ListNode(Appointment *, ListNode *);
    ~ListNode();
};

#endif
