#ifndef REGATTAFILE_HPP
#define REGATTAFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "boats/Regatta.hpp"

using namespace std;

class RegattaFile {
    private:
        string filename;

    public:
        RegattaFile(const string&);

        void list() const;
        int search(Regatta&, string) const; // TODO Throw an exception instead of returning 0 (such teacher D:)
        void save(const Regatta&) const;

};

#endif
