#include "collections/List.hpp"

template<class T>
List<T>::List() {
    this->_first = NULL;
    this->_size = 0;
}

template<class T>
List<T>::List(T elem) {
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
    this->_first->current = toCopy->current;
    newNode = this->_first;
    newNode->prev = NULL;

    while(toCopy = toCopy->next) {
        newNode->next = new Node<T>;
        newNode->current = toCopy->current;
        newNode->next->prev = newNode;
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
void List<T>::add(const T& elem) {
	// Adds elements to the start of the List
	struct Node<T>* node = new Node<T>;
	node->current = elem;
	node->next = this->_first;
	node->prev = NULL;
	if(this->_first != NULL) {
		node->next->prev = node;
	}
	this->_first = node;
	++this->_size;
}

template<class T>
const T& List<T>::get(int index) const {
	this->validate(index);
	int i = 0;
	struct Node<T>* current = this->_first;
	while(i < index) {
		current = current->next;
		++i;
	}
	return current->current;
}

template<class T>
T List<T>::remove(int index) {
    this->validate(index);

    // TODO Don't remove the first one only
    struct Node<T>* tmp = this->_first->next;
    T ret = this->_first->current;
    delete this->_first;
    this->_first = tmp;
    --this->_size;
    return ret;
}

template<class T>
bool List<T>::isEmpty() const {
    return this->_size == 0;
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
void List<T>::display() const {
	cout << "[ ";
	struct Node<T>* cur = this->_first;
	while(cur != NULL) {
		cout << cur->current << " ";
		cur = cur->next;
	}
    cout << "]";
}

template<class T>
void List<T>::validate(int index) const {
    if(!this->isValid(index)) {
        throw OutOfBoundsException("Index out of bounds: " + StringUtils::toString(index));
    }
}

// Pre setting template usage
template class List<int>;

#include "boats/Course.hpp"
template class List<Course>;

#include "users/User.hpp"
template class List<User*>;
