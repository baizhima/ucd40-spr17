

template <typename T>
ListNode<T>::ListNode(T object, ListNode *node): object(object), next(node)
{

}

template <typename T>
ListNode<T>::~ListNode()
{
}


template <typename T>
std::ostream & operator<<(std::ostream &os, const ListNode<T> & node)
{
    os << "hahah" << std::endl;
    return os;
}
