#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "exceptions/OutOfBoundsException.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

template<class T>
struct Node {
    struct Node* prev;
    struct Node* next;
    T current;
};

template<class T>
class List {

    protected:
        struct Node<T>* _first;
        int _size;

        void validate(int) const;

    public:
        List();
        List(T);
        List(const List&);
        ~List();

        // abstract, need to be added in subclasses
        virtual void add(const T&);
        const T& get(int) const;
        bool isEmpty() const;
        int size() const;
        T remove(int);
        bool isValid(int) const;
        void display() const;

};

#endif // LIST_HPP
