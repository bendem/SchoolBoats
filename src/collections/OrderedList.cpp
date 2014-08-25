#include "collections/OrderedList.hpp"

template<class T>
int OrderedList<T>::ASCENDING = 0;
template<class T>
int OrderedList<T>::DESCENDING = 1;

template<class T>
OrderedList<T>::OrderedList() : OrderedList(OrderedList::ASCENDING) {}

template<class T>
OrderedList<T>::OrderedList(int mode) {
    this->_mode = mode;
}
template<class T>
OrderedList<T>::OrderedList(const OrderedList& list) : List<T>::List(list) {
    this->_mode = list._mode;
}

template<class T>
bool OrderedList<T>::shouldInsert(const T& current, const T& newElem) {
    if(current > newElem && this->_mode == OrderedList::ASCENDING) {
        return true;
    }
    if(current < newElem && this->_mode == OrderedList::DESCENDING) {
        return true;
    }
    return false;
}

template<class T>
void OrderedList<T>::add(T elem) {
    // Insert on first position
    if(this->isEmpty() || this->shouldInsert(this->_first->current, elem)) {
        struct Node<T> *tmp = this->_first;
        this->_first = new struct Node<T>;
        this->_first->current = elem;
        this->_first->prev = NULL;
        this->_first->next = tmp;
        // If there was something after, link it to the first item
        if(tmp) {
            this->_first->next->prev = this->_first;
        }
        ++this->_size;
        return;
    }

    struct Node<T> *current = this->_first;
    struct Node<T> *prev = this->_first;
    while(prev != NULL) {
        if(current == NULL || this->shouldInsert(current->current, elem)) {
            prev->next = new struct Node<T>;
            prev->next->current = elem;
            prev->next->prev = prev;
            prev->next->next = current;
            break;
        }
        prev = current;
        current = current->next;
    }
    ++this->_size;
}

template<class T>
void OrderedList<T>::setMode(int mode) {
    if(this->_mode != mode) {
        // TODO Reverse list order!
    }
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

#include "users/User.hpp"
template class OrderedList<User*>;

#include "boats/Regatta.hpp"
template class List<Regatta*>;
