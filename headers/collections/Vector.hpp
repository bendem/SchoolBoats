#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/OutOfBoundsException.hpp"
#include "utils/StringUtils.hpp"

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
        void remove(int);
        int  currentSize() const;
        int  maxSize() const;
        bool isEmpty() const;
        bool isValid(int) const;
};

#endif
