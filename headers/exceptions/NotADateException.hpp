#ifndef NOTADATEEXCEPTION_HPP
#define NOTADATEEXCEPTION_HPP

#include <string>
#include "exceptions/Exception.hpp"

class NotADateException : public Exception {

    public:
        NotADateException();
        NotADateException(const string);
        NotADateException(const Exception*);
        NotADateException(const string, const Exception*);
        NotADateException(const NotADateException&);

};

#endif // NOTADATEEXCEPTION_H
