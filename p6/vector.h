
#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{

public:
   Vector(int size);
   ~Vector();
   int getCount() const;
   const T & operator[](int i) const;
   T & operator[](int i);
   int operator+=(const T &);


private:
    int size;
    int count;
    T *array;
     
}; 


#include "vector.cpp"
#endif

