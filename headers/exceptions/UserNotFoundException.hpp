#ifndef USERNOTFOUNDEXCEPTION_HPP
#define USERNOTFOUNDEXCEPTION_HPP

#include <string>
#include "exceptions/Exception.hpp"

class UserNotFoundException : public Exception {

    public:
        UserNotFoundException();
        UserNotFoundException(const string);
        UserNotFoundException(const Exception*);
        UserNotFoundException(const string, const Exception*);
        UserNotFoundException(const UserNotFoundException&);

};

#endif

