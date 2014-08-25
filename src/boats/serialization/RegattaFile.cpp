#include "boats/serialization/RegattaFile.hpp"

RegattaFile::RegattaFile(const string& filename) {
    this->filename = filename;
}

void RegattaFile::list() const {
    Regatta regatta;
    ifstream is(this->filename, ios::in);
    while(is.peek() != EOF) {
        regatta.load(is);
        cout << regatta.getInfo() << endl;
    }
}

int RegattaFile::search(Regatta& regatta, string name) const {
    // TODO Throw an exception instead of returning 0 (such teacher D:)
    ifstream is(this->filename, ios::in);
    while(is.peek() != EOF) {
        regatta.load(is);
        if(regatta.getRaceName() == name) {
            return 0;
        }
    }
    return 1;
}

void RegattaFile::save(const Regatta& regatta) const {
    ofstream os(this->filename, ios::app);
    regatta.save(os);
}
