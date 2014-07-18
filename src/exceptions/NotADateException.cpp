#include "exceptions/NotADateException.hpp"

NotADateException::NotADateException() : Exception() {}
NotADateException::NotADateException(const string message) : Exception(message) {}
NotADateException::NotADateException(const Exception* e) : Exception(e) {}
NotADateException::NotADateException(const string message, const Exception* e) : Exception(message, e) {}
NotADateException::NotADateException(const NotADateException& e) : Exception(e) {}
