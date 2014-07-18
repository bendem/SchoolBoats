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
        struct Node<T>* first;

    public:
        List();
        List(const T&);
        List(const List&);
        ~List();

        // abstract, need to be added in subclasses
        virtual void add(const T&) = 0;
        const T&     get(int);
        bool         empty();
        int          size();
        void         remove(int);

};

#endif // LIST_HPP
