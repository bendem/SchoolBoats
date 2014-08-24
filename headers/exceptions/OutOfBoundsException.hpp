#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP

#include <string>
#include "exceptions/Exception.hpp"

class OutOfBoundsException : Exception {

    public:
        OutOfBoundsException();
        OutOfBoundsException(const string);
        OutOfBoundsException(const Exception*);
        OutOfBoundsException(const string, const Exception*);
        OutOfBoundsException(const OutOfBoundsException&);

};

#endif  /* OUTOFBOUNDSEXCEPTION_H */

