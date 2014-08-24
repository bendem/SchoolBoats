#ifndef INVALIDARGUMENTEXCEPTION_HPP
#define INVALIDARGUMENTEXCEPTION_HPP

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

