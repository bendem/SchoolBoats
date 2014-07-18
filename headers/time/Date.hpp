#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/InvalidDateException.hpp"
#include "utils/StringUtils.hpp"

enum TimeUnit {
    Year, Month, Day, Hour, Minute, Second
};

// TODO Store struct tm instead of an int...
class Date {

    private:
        unsigned int time;

        struct tm getTimeStruct() const;
    public:
        Date();
        Date(int);
        Date(int, int, int, int, int, int);
        Date(const Date&);

        void add(int, TimeUnit);
        void remove(int, TimeUnit);
        void set(int, TimeUnit);
        int get(TimeUnit) const;
        void now();

        unsigned int getTime() const;

        Date operator+(int) const;
        Date operator+(const Date&) const;
        Date operator-(int) const;
        Date operator-(const Date&) const;

        string toString() const;

        static bool isLeapYear(int);
        static bool isValidDate(int, int, int);

};

#endif // DATE_H
