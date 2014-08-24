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

void Regatta::save(ostream& os) const {
	int time = this->start.getTime();
	bool date = this->start.isDate();
	float modelSize = this->object->getModel().getSize();
	StringUtils::write(os, this->raceName);
	os.write((char*) &time, sizeof(int));
	os.write((char*) &date, sizeof(bool));
	StringUtils::write(os, this->location);
	StringUtils::write(os, this->name);
	StringUtils::write(os, this->object->getIdentifier());
	StringUtils::write(os, this->object->getModel().getManufacturer());
	StringUtils::write(os, this->object->getModel().getModel());
	os.write((char*) &modelSize, sizeof(float));
}
void Regatta::load(istream& is) {

	this->raceName = StringUtils::read(is);

	int time;
	is.read((char*) &time, sizeof(int));
	this->start.setTime(time);

	bool date;
	is.read((char*) &date, sizeof(bool));
	this->start.setDate(date);

	this->location = StringUtils::read(is);
	this->name     = StringUtils::read(is);
	this->object->setIdentifier(StringUtils::read(is));

	string manufacturer = StringUtils::read(is);
	string model        = StringUtils::read(is);
	float modelSize;
	is.read((char*) &modelSize, sizeof(float));

	this->object->setModel(FloatingObjectModel(manufacturer, model, modelSize));
}
