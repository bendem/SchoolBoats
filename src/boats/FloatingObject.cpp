#include "boats/FloatingObject.hpp"

FloatingObject::FloatingObject() : FloatingObject("", FloatingObjectModel()) {}

FloatingObject::FloatingObject(string id, FloatingObjectModel model) {
    this->identifier = id;
    this->model = model;
}

FloatingObject::FloatingObject(const FloatingObject& obj) {
    this->identifier = obj.identifier;
    this->model = FloatingObjectModel(obj.model);
}

void FloatingObject::setIdentifier(string id) {
    this->identifier = id;
}

void FloatingObject::setModel(FloatingObjectModel model) {
    this->model = model;
}

string FloatingObject::getIdentifier() const {
    return this->identifier;
}

const FloatingObjectModel& FloatingObject::getModel() const {
    return this->model;
}

string FloatingObject::toString() const {
    return "FloatingObject{id='" + this->identifier + "', model=" + this->model.toString() + "}";
}

void FloatingObject::display() const {
    cout << toString() << endl;
}

ostream& operator<<(ostream& s, const FloatingObject& f) {
    return s << f.toString() << endl;
}

istream& operator>>(istream& s, FloatingObject& f) {
    s >> f.identifier;
    s >> f.model;
    return s;
}
