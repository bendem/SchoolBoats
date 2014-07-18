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

string FloatingObject::getIdentifier() {
    return this->identifier;
}

FloatingObjectModel& FloatingObject::getModel() {
    return this->model;
}

string FloatingObject::toString() {
    return "FloatingObject{id='" + this->identifier + "', model=" + this->model.toString() + "}";
}

void FloatingObject::display() {
    cout << toString() << endl;
}
