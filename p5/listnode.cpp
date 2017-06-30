
#include "listnode.h"


ListNode::ListNode(Appointment *appt, ListNode *node): appt(appt), next(node)
{

}

ListNode::~ListNode()
{
    delete appt;
}

