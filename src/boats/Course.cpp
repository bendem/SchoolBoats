#include "boats/Course.hpp"

Course::Course() : Course("", "", FloatingObject(), 1, Planning()) {}

Course::Course(string name, string location, const FloatingObject& object, int level, const Planning& planning) : Activity(name, location, object) {
    this->level = level;
    this->planning = planning;
}

int Course::getLevel() const {
    return this->level;
}
const Planning& Course::getPlanning() const {
    return this->planning;
}

void Course::setLevel(int lvl) {
    this->level = lvl;
}
void Course::setPlanning(const Planning& p) {
    this->planning = p;
}


string Course::toString() const {
    return "Course{level=" + StringUtils::toString(this->level)
        + "', Planning=" + this->planning.toString()
        + ", Parent=" + Activity::toString();
        + "}";
}

void Course::display() const {
    cout << this->toString() << endl;
}

string Course::getInfo() const {
    return "COURSE: " + StringUtils::toString(this->level) + "#" + this->planning.toString();
}
