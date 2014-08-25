#include "boats/Track.hpp"

Track::Track() : Track("") {}
Track::Track(string name) : Track(name, 20) {}

Track::Track(string name, int size) {
    this->name = name;
    this->points = new Vector<Point*>(size);
}

Track::Track(const Track& orig) {
    this->name = orig.name;
    // Reduces the size to get only the amount of points needed in the points vector
    this->points = new Vector<Point*>(orig.points->count());
    for(int i = 0; i < orig.points->count(); ++i) {
        this->points->set(i, orig.points->get(i));
    }
}
Track::~Track() {
    delete this->points;
}

string Track::getName() const {
    return this->name;
}
Point& Track::getPoint(int index) const {
    return *this->points->get(index);
}
int Track::getPointCount() const {
    return this->points->count();
}

Track Track::load(string name, istream& is) {
    Track track(name);
    Vector<string> parts(2);
    string line;
    while(is.peek() != EOF) {
        is >> line;
        parts = StringUtils::cut(line, ';');
        *(track.points) + new Point(atoi(parts.get(0).c_str()), atoi(parts.get(1).c_str()));
    }
    // Making a copy removes the unused places in the vector
    return Track(track);
}
