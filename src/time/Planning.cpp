#include "time/Planning.hpp"

Planning::Planning() {}

Planning::Planning(const Moment& start, const Moment& end) {
    this->start = start;
    this->end = end;
}
Planning::Planning(const Planning& p) {
    this->start = Moment(p.start);
    this->end = Moment(p.end);
}

Moment& Planning::getStart() {
    return this->start;
}
Moment& Planning::getEnd() {
    return this->end;
}

Moment& Planning::operator=(const Planning& p) {
    this->start = p.start;
    this->end = p.end;
}

string Planning::toString() const {
    return "Planning{start=" + this->start.toString()
        + ", end=" + this->end.toString()
        + "}";
}

ostream& operator<<(ostream& s, const Planning& p) {
    return s << p.toString() << endl;
}
