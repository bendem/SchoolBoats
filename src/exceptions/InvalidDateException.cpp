#include "exceptions/InvalidDateException.hpp"

InvalidDateException::InvalidDateException() : Exception() {}
InvalidDateException::InvalidDateException(const string message) : Exception(message) {}
InvalidDateException::InvalidDateException(const Exception* e) : Exception(e) {}
InvalidDateException::InvalidDateException(const string message, const Exception* e) : Exception(message, e) {}
InvalidDateException::InvalidDateException(const InvalidDateException& e) : Exception(e) {}
