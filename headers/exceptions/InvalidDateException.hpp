#ifndef INVALIDDATEEXCEPTION_HPP
#define INVALIDDATEEXCEPTION_HPP

#include <string>
#include "exceptions/Exception.hpp"

class InvalidDateException : public Exception {

    public:
        InvalidDateException();
        InvalidDateException(const string);
        InvalidDateException(const Exception*);
        InvalidDateException(const string, const Exception*);
        InvalidDateException(const InvalidDateException&);

};

#endif
