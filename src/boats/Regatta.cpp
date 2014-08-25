#include "boats/Regatta.hpp"

Regatta::Regatta() : Regatta("", "", FloatingObject(), "", Moment()) {}

Regatta::Regatta(string name, string location, const FloatingObject& object, string raceName, const Moment& start/*, unknown*/)
        : Activity(name, location, object) {
    this->raceName = raceName;
    this->start = start;
}

Regatta::Regatta(const Regatta& regatta) : Activity(regatta) {
    this->raceName = regatta.raceName;
    this->start = regatta.start;
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

void Regatta::save(ostream& os) const {
    StreamUtils::write(os, this->raceName);
    StreamUtils::write(os, this->start.getTime());
    StreamUtils::write(os, this->start.isDate());
    StreamUtils::write(os, this->location);
    StreamUtils::write(os, this->name);
    StreamUtils::write(os, this->object->getIdentifier());
    StreamUtils::write(os, this->object->getModel().getManufacturer());
    StreamUtils::write(os, this->object->getModel().getModel());
    StreamUtils::write(os, this->object->getModel().getSize());
}

void Regatta::load(istream& is) {
    this->raceName =            StreamUtils::readString(is);
    this->start.setTime(        StreamUtils::readInt(is));
    this->start.setDate(        StreamUtils::readBool(is));
    this->location =            StreamUtils::readString(is);
    this->name     =            StreamUtils::readString(is);
    this->object->setIdentifier(StreamUtils::readString(is));

    string manufacturer = StreamUtils::readString(is);
    string model        = StreamUtils::readString(is);
    float modelSize     = StreamUtils::readFloat(is);

    this->object->setModel(FloatingObjectModel(manufacturer, model, modelSize));
}
