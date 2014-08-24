#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/OutOfBoundsException.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

template<class T>
class Vector {

    private:
        int   _size;
        T*    _values;
        bool* _indexes;
        int   _used;

        void validate(int) const;

    public:
        Vector(int);
        Vector(const Vector& orig);
        ~Vector();

        T& get(int) const;
        void set(int, const T&);
        T&   remove(int);
        int  count() const;
        int  size() const;
        bool isUsed(int) const;
        bool isEmpty() const;
        bool isValid(int) const;

        void display() const;

        Vector<T>& operator+(const T&);
};

#endif
