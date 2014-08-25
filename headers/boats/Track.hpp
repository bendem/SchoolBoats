#ifndef TRACK_HPP
#define TRACK_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "boats/Point.hpp"
#include "collections/Vector.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

class Track {

    private:
        string name;
        Vector<Point*>* points;

    public:
        Track();
        Track(string);
        Track(string, int);
        Track(const Track&);
        ~Track();

        string getName() const;
        Point& getPoint(int) const;
        int getPointCount() const;

        // Serialization
        static Track load(string, istream&);

};

#endif
