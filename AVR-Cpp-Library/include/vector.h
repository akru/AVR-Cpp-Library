#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class vector
{
public:
  vector(T value, vector<T> *head)
    : item(value), next(head)
  {}
  T item;
  vector<T> *next;
};

#endif // VECTOR_H
