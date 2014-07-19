#ifndef INVALIDARGUMENTEXCEPTION_H
#define INVALIDARGUMENTEXCEPTION_H

#include <string>
#include "exceptions/Exception.hpp"

using namespace std;

class InvalidArgumentException : public Exception {

    public:
        InvalidArgumentException();
        InvalidArgumentException(const string);
        InvalidArgumentException(const Exception*);
        InvalidArgumentException(const string, const Exception*);
        InvalidArgumentException(const InvalidArgumentException&);

};

#endif

