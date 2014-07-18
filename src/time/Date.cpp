#include "time/Date.hpp"

Date::Date() {
    this->now();
}

Date::Date(int time) {
    this->time = time;
}

Date::Date(int year, int month, int day, int hour, int minute, int second) {
    if(!Date::isValidDate(year, month, day)) {
        throw InvalidDateException();
    }
    struct tm t;

    t.tm_year = year - 1900;
    t.tm_mon  = month - 1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min  = minute;
    t.tm_sec  = second;

    this->time = mktime(&t);
}

Date::Date(const Date& date) {
    this->time = date.time;
}

struct tm Date::getTimeStruct() const {
    time_t tmp = this->time;
    return *(localtime(&tmp));
}

void Date::add(int toAdd, TimeUnit unit) {
    struct tm t = this->getTimeStruct();
    switch(unit) {
        case Year:
            t.tm_year += toAdd;
            break;
        case Month:
            t.tm_mon += toAdd;
            break;
        case Day:
            t.tm_mday += toAdd;
            break;
        case Hour:
            t.tm_hour += toAdd;
            break;
        case Minute:
            t.tm_min += toAdd;
            break;
        case Second:
            t.tm_sec += toAdd;
            break;
    }
    this->time = mktime(&t);
}

void Date::remove(int toRemove, TimeUnit unit) {
    this->add(-toRemove, unit);
}

void Date::set(int value, TimeUnit unit) {
    struct tm t = this->getTimeStruct();
    switch(unit) {
        case Year:
            t.tm_year = value - 1900;
            break;
        case Month:
            t.tm_mon = value - 1;
            break;
        case Day:
            t.tm_mday = value;
            break;
        case Hour:
            t.tm_hour = value;
            break;
        case Minute:
            t.tm_min = value;
            break;
        case Second:
            t.tm_sec = value;
            break;
    }
    this->time = mktime(&t);
}

int Date::get(TimeUnit unit) const {
    struct tm t = this->getTimeStruct();
    switch(unit) {
        case Year:   return t.tm_year + 1900;
        case Month:  return t.tm_mon + 1;
        case Day:    return t.tm_mday;
        case Hour:   return t.tm_hour;
        case Minute: return t.tm_min;
        case Second: return t.tm_sec;
    }
    throw InvalidArgumentException("This unit type is not recognized");
}

void Date::now() {
    this->time = std::time(NULL);
}

unsigned int Date::getTime() const {
    return this->time;
}

Date Date::operator+(int value) const {
    Date d(*this);
    d.add(value, Minute);
    return d;
}

Date Date::operator+(const Date& date) const {
    Date d(*this);
    d.time += date.time;
    return d;
}

Date Date::operator-(int value) const {
    Date d(*this);
    d.remove(value, Minute);
    return d;
}

int Date::operator-(const Date& date) const {
    return (int) difftime(this->time, date.time);
}

string Date::toString() const {
    return "Date{time=" + StringUtils::toString(this->time) + "}";
}

bool Date::isLeapYear(int year) {
    return (!(year % 4) && (year % 100) || !(year % 400));
}

bool Date::isValidDate(int year, int month, int day) {
    unsigned int month_len[] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    if(!month || !day || month > 12 || year < 2000) {
        return false;
    }
    if(Date::isLeapYear(year) && month == 2) {
        ++month_len[1];
    }
    if(day > month_len[month - 1]) {
        return false;
    }

    return true;
}
