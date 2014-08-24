#include "collections/OrderedList.hpp"

template<class T>
int OrderedList<T>::ASCENDING = 0;
template<class T>
int OrderedList<T>::DESCENDING = 1;

// Pre setting template usage
template class OrderedList<int>;

#include "boats/Course.hpp"
template class OrderedList<Course>;
