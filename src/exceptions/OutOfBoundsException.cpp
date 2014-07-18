#include "exceptions/OutOfBoundsException.hpp"

OutOfBoundsException::OutOfBoundsException() : Exception() {}
OutOfBoundsException::OutOfBoundsException(const string message) : Exception(message) {}
OutOfBoundsException::OutOfBoundsException(const Exception* e) : Exception(e) {}
OutOfBoundsException::OutOfBoundsException(const string message, const Exception* e) : Exception(message, e) {}
OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& e) : Exception(e) {}
