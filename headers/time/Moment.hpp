#ifndef MOMENT_H
#define MOMENT_H

#include <string>
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/InvalidDateException.hpp"
#include "exceptions/NotADateException.hpp"
#include "time/Date.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

class Moment {

    private:
        int time;
        bool date;

        int toSec(int, int, int, int, int) const;

    public:
        Moment();
        Moment(int);
        Moment(int, int, int);
        Moment(int, int, int, int, int);
        Moment(const Moment&);
        ~Moment();

        string toString() const;

        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setHour(int);
        void setMinute(int);
        void setSecond(int);

        int getYear() const;
        int getMonth() const;
        int getDay() const;
        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        bool isDate() const;

        Moment& operator=(const Moment&);
        Moment operator+(const Moment&) const;
        Moment operator+(const int) const;
        Moment operator-(const Moment&) const;
        Moment operator-(const int) const;
        bool operator>(const Moment&) const;
        bool operator<(const Moment&) const;
        bool operator==(const Moment&) const;
        Moment operator++();
        Moment operator++(int);

        static Moment now();

};

ostream& operator<<(ostream&, const Moment&);
//istream& operator>>(istream&, Moment&);

#endif // MOMENT_H
