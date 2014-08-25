#ifndef DUPLICATEDUSEREXCEPTION_HPP
#define DUPLICATEDUSEREXCEPTION_HPP

#include <string>
#include "exceptions/Exception.hpp"

using namespace std;

class DuplicatedUserException : public Exception {

    public:
        DuplicatedUserException();
        DuplicatedUserException(const string);
        DuplicatedUserException(const Exception*);
        DuplicatedUserException(const string, const Exception*);
        DuplicatedUserException(const DuplicatedUserException&);

};

#endif

