template<typename T>
Vector<T>::Vector(int sz): size(sz), count(0), array(new T[sz])
{

}

template<typename T>
Vector<T>::~Vector()
{
    delete []array;
}

template<typename T>
int Vector<T>::getCount() const
{
    return count;
}

template<typename T>
const T & Vector<T>::operator[](int idx) const
{
    return array[idx];
}

template<typename T>
T & Vector<T>::operator[](int idx)
{
    return array[idx];
}

template<typename T>
int Vector<T>::operator+=(const T &item)
{
    int pos = 0;
    for (; pos < count; pos++)
    {
        if (item < array[pos])
        {
            break;
        }
        if (item == array[pos])
        {
            return pos;
        }
    }
    for (int i = count; i > pos; i--)
    {
        array[i] = array[i-1];
    }
    array[pos] = item;
    count++;
    if (count == size) {
        T *newArray = new T[2 * size];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        size *= 2;
        delete[] array;
        array = newArray;
    }
    return pos;

}
