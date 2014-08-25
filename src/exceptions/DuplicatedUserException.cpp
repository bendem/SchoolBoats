#include "exceptions/DuplicatedUserException.hpp"

DuplicatedUserException::DuplicatedUserException() : Exception() {}
DuplicatedUserException::DuplicatedUserException(const string message) : Exception(message) {}
DuplicatedUserException::DuplicatedUserException(const Exception* e) : Exception(e) {}
DuplicatedUserException::DuplicatedUserException(const string message, const Exception* e) : Exception(message, e) {}
DuplicatedUserException::DuplicatedUserException(const DuplicatedUserException& e) : Exception(e) {}

