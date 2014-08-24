#include "collections/List.hpp"

template<class T>
List<T>::List() {
    this->_first = NULL;
    this->_size = 0;
}

template<class T>
List<T>::List(const T& elem) {
    this->_first = new struct Node<T>;
    this->_first->current = elem;
    this->_first->prev = NULL;
    this->_first->next = NULL;
    this->_size = 0;
}

template<class T>
List<T>::List(const List& list) {
    if(list.isEmpty()) {
        return;
    }

    struct Node<T>* toCopy = list._first;
    struct Node<T>* newNode;

    this->_first = new Node<T>;
    newNode = this->_first;
    newNode->prev = NULL;
    newNode->current = toCopy->current;

    while(toCopy = toCopy->next) {
        newNode->next = new Node<T>;
        newNode->next->prev = newNode;
        newNode->next->current = toCopy->current;
        newNode = newNode->next;
    }
    newNode->next = NULL;

    this->_size = list._size;
}

template<class T>
List<T>::~List() {
    while(!this->isEmpty()) {
        this->remove(0);
    }
}

template<class T>
const T& List<T>::get(int index) const {
	// TODO Implement that
}

template<class T>
void List<T>::remove(int index) {
    this->validate(index);

    // TODO Don't remove the first one only
    struct Node<T>* tmp = this->_first->next;
    delete this->_first;
    this->_first = tmp;
    --this->_size;
}

template<class T>
bool List<T>::isEmpty() const {
    return this->_first = NULL;
}

template<class T>
int List<T>::size() const {
    return this->_size;
}

/**
 * Checks wether an index is valid or not
 * @return
 */
template<class T>
bool List<T>::isValid(int index) const {
    return index >= 0 && index < this->_size;
}

template<class T>
void List<T>::validate(int index) const {
    if(!this->isValid(index)) {
        throw OutOfBoundsException("Index out of bounds: " + StringUtils::toString(index));
    }
}
