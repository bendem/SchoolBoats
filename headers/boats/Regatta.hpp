#ifndef REGATTA_H
#define REGATTA_H

#include "boats/Activity.hpp"
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

};

#endif // REGATTA_H
