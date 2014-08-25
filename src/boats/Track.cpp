#include "boats/Track.hpp"

Track::Track() : Track("", 20) {}

Track::Track(string name, int size) {
    this->name = name;
    this->points = new Vector<Point*>(size);
}

Track(const Track& orig) {
    this->name = orig.name;
    this->points = new Vector<Point*>(orig.points);
}
Track::~Track() {
    delete this->points;
}

string Track::getName() const {
    return this->name;
}
Point& getPoint(int index) const {
    return *this->points->get(index);
}
int getPointCount() const {
    return this->points->count();
}
