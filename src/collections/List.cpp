#include "collections/List.hpp"

template<class T>
List<T>::List() {
    first = NULL;
}

template<class T>
List<T>::List(const T& elem) {
    this->first = new struct Node<T>;
    this->first->current = elem;
    this->first->prev = NULL;
    this->first->next = NULL;
}

template<class T>
List<T>::List(const List& list) {
    if(list.empty()) {
        return;
    }

    struct Node<T>* toCopy = list.first;
    struct Node<T>* newNode;

    this->first = new Node<T>;
    newNode = this->first;
    newNode->prev = NULL;
    newNode->current = toCopy->current;

    while(toCopy = toCopy->next) {
        newNode->next = new Node<T>;
        newNode->next->prev = newNode;
        newNode->next->current = toCopy->current;
        newNode = newNode->next;
    }
    newNode->next = NULL;
}

template<class T>
List<T>::~List() {
    while(!this->empty()) {
        this->remove(0);
    }
}

template<class T>
void List<T>::remove(int index) {
    if(empty()) {
        throw OutOfBoundsException("No element to remove.");
    }
    struct Node<T>* lol = this->first->next;
    delete this->first;
    this->first = lol;
}

template<class T>
bool List<T>::empty() {
    return this->first = NULL;
}

template<class T>
int List<T>::size() {
    int i = 0;
    struct Node<T>* current = first;
    while(current != NULL) {
        ++i;
        current = current->next;
    }
    return i;
}
