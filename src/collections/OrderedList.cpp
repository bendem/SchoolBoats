#include "collections/OrderedList.hpp"

template<class T>
int OrderedList<T>::ASCENDING = 0;
template<class T>
int OrderedList<T>::DESCENDING = 1;

template<class T>
int OrderedList<T>::compare(const T& e1, const T& e2) {
	if(e1 > e2) {
		return 1;
	}
	return e1 < e2 ? -1 : 0;
}

template<class T>
void OrderedList<T>::add(const T& elem) {
	// Add it at the start of the list if it is empty
	if(this->isEmpty()) {
		List<T>::add(elem);
		return;
	}

	// TODO Add somewhere else in the list
}

template<class T>
void OrderedList<T>::setMode(int mode) {
	this->_mode = mode;
}

template<class T>
int OrderedList<T>::getMode() const {
	return this->_mode;
}

// Pre setting template usage
template class OrderedList<int>;

#include "boats/Course.hpp"
template class OrderedList<Course>;
