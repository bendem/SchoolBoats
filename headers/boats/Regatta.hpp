#ifndef REGATTA_HPP
#define REGATTA_HPP

#include <iostream>
#include <string>
#include "boats/Activity.hpp"
#include "boats/FloatingObject.hpp"
#include "time/Moment.hpp"
#include "utils/StringUtils.hpp"

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

        // Serialization
        void save(ostream&) const;
        void load(istream&);

};

#endif // REGATTA_H
