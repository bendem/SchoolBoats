#ifndef TRACK_HPP
#define TRACK_HPP

#include <string>
#include "collections/Vector.hpp"

class Track {

    private:
        string name;
        Vector<Point*>* points;

    public:
        Track();
        Track(string, int);
        Track(const Track&);
        ~Track();

        string getName() const;
        Point& getPoint(int) const;
        int getPointCount() const;

};

#endif
