#include "exceptions/UserNotFoundException.hpp"

UserNotFoundException::UserNotFoundException() : Exception() {}
UserNotFoundException::UserNotFoundException(const string message) : Exception(message) {}
UserNotFoundException::UserNotFoundException(const Exception* e) : Exception(e) {}
UserNotFoundException::UserNotFoundException(const string message, const Exception* e) : Exception(message, e) {}
UserNotFoundException::UserNotFoundException(const UserNotFoundException& e) : Exception(e) {}
