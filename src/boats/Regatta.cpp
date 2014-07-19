#include "boats/Regatta.hpp"

Regatta::Regatta() : Regatta("", "", FloatingObject(), "", Moment()) {}

Regatta::Regatta(string name, string location, const FloatingObject& object, string raceName, const Moment& start/*, unknown*/)
        : Activity(name, location, object) {
    this->raceName = raceName;
    this->start = start;
}

string Regatta::getRaceName() const {
    return this->raceName;
}
const Moment& Regatta::getStart() const {
    return this->start;
}

void Regatta::setRaceName(string raceName) {
    this->raceName = raceName;
}

void Regatta::setStart(const Moment& m) {
    this->start = m;
}

string Regatta::getInfo() const {
    return "REGATE: " + this->raceName + "#" + this->start.toString();
}

void Regatta::read(istream& s) {
    Activity::read(s);
    s >> this->raceName;
    s >> this->start;
}

Regatta& Regatta::operator=(const Regatta& r) {
    this->raceName = r.raceName;
    this->start = r.start;
    Activity::operator=(r);
    return *this;
}

ostream& operator<<(ostream& s, const Regatta& r) {
    return s << r.toString();
}

istream& operator>>(istream& s, Regatta& r) {
    r.read(s);
    return s;
}
