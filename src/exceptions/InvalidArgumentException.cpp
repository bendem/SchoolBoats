#include "exceptions/InvalidArgumentException.hpp"

InvalidArgumentException::InvalidArgumentException() : Exception() {}
InvalidArgumentException::InvalidArgumentException(const string message) : Exception(message) {}
InvalidArgumentException::InvalidArgumentException(const Exception* e) : Exception(e) {}
InvalidArgumentException::InvalidArgumentException(const string message, const Exception* e) : Exception(message, e) {}
InvalidArgumentException::InvalidArgumentException(const InvalidArgumentException& e) : Exception(e) {}
