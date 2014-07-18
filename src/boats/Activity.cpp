#include "boats/Activity.hpp"

Activity::Activity(string name, string location, const FloatingObject& object) {
    this->name = name;
    this->location = location;
    this->object = new FloatingObject(object);
}

Activity::Activity(const Activity& a) {
    this->name = a.name;
    this->location = location;
    this->object = new FloatingObject(*a.object);
}

Activity::~Activity() {
    if(this->object != NULL) {
        delete this->object;
    }
}


string Activity::getLocation() const {
    return this->location;
}
string Activity::getName() const {
    return this->name;
}
FloatingObject& Activity::getFloatingObject() const {
    return *this->object;
}

void Activity::setLocation(string location) {
    this->location = location;
}
void Activity::setName(string name) {
     this->name = name;
}
void Activity::setFloatingObject(FloatingObject object) {
    this->object = new FloatingObject(object);
}

string Activity::toString() const {
    return "Activity{name='" + this->name
        + "', location='" + this->location
        + "', object=" + this->object->toString()
        + "}";
}

void Activity::display() const {
    cout << this->toString() << endl;
}
