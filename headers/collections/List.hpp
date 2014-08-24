#ifndef LIST_HPP
#define LIST_HPP

#include "exceptions/OutOfBoundsException.hpp"

template<class T>
struct Node {
    struct Node* prev;
    struct Node* next;
    T& current;
};

template<class T>
class List {

    protected:
        struct Node<T>* _first;
        int _size;

        void validate(int) const;

    public:
        List();
        List(const T&);
        List(const List&);
        ~List();

        // abstract, need to be added in subclasses
        virtual void add(const T&) = 0;
        const T& get(int) const;
        bool isEmpty() const;
        int size() const;
        void remove(int);
		bool isValid(int) const;
        void display() const;

};

#endif // LIST_HPP
