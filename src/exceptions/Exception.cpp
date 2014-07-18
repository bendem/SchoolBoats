#include "exceptions/Exception.hpp"

Exception::Exception() : Exception("") {}

Exception::Exception(const string message) {
    this->message = message;
    this->source = NULL;
}

Exception::Exception(const Exception* e) : Exception("", e) {}

Exception::Exception(const string message, const Exception* e) {
    this->message = message;
    this->source = e;
}

Exception::Exception(const Exception& e) {
    this->message = e.message;
    if(e.source != NULL) {
        this->source = new Exception(e.source);
    } else {
        this->source = NULL;
    }
}

Exception::~Exception() {
    if(this->source != NULL) {
        delete this->source;
    }
}

string Exception::getMessage() const {
    return this->message;
}

const Exception& Exception::getSource() const {
    return *this->source;
}

bool Exception::hasSource() const {
    return this->source != NULL;
}

ostream& operator<<(ostream& stream, const Exception& e) {
    stream << "Exception: " << e.getMessage() << endl;
    if(e.hasSource()) {
        stream << "Caused by " << e.getSource();
    }
    return stream;
}
