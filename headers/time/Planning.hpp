#ifndef PLANNING_H
#define PLANNING_H

#include "time/Moment.hpp"

class Planning {

    private:
        Moment start;
        Moment end;
    public:
        Planning();
        Planning(const Moment&, const Moment&);
        Planning(const Planning&);

        Moment& getStart();
        Moment& getEnd();

        Moment& operator=(const Planning&);

        string toString() const;

        friend ostream& operator<<(ostream&, const Planning&);
        friend istream& operator>>(istream&, Planning&);

};

#endif // PLANNING_H
