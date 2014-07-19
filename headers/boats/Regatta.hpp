#ifndef REGATTA_H
#define REGATTA_H

#include <iostream>
#include <string>
#include "boats/Activity.hpp"
#include "boats/FloatingObject.hpp"
#include "time/Moment.hpp"

class Regatta : public Activity {

    private:
        string raceName;
        Moment start;
    public:
        Regatta();
        Regatta(string, string, const FloatingObject&, string, const Moment&/*, unknown*/);

        string getRaceName() const;
        const Moment& getStart() const;

        void setRaceName(string);
        void setStart(const Moment&);

        string getInfo() const;

        void read(istream&);

        Regatta& operator=(const Regatta&);
        friend ostream& operator<<(ostream&, const Regatta&);
        friend istream& operator>>(istream&, Regatta&);

};

#endif // REGATTA_H
