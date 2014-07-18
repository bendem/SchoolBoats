#include "time/Moment.hpp"

Moment::Moment() : Moment(0) {}

Moment::Moment(int time) {
    this->date = false;
    this->time = time * 60;
}

Moment::Moment(int year, int month, int day) : Moment(year, month, day, 0, 0) {}

Moment::Moment(int year, int month, int day, int hour, int minute) {
    this->date = true;
    this->time = this->toSec(year, month, day, hour, minute);
}

Moment::Moment(const Moment& other) {
    this->time = other.time;
    this->date = other.date;
}

Moment::~Moment() {}

void Moment::setYear(int year) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(year, Year);
    this->time = d.getTime();
}
void Moment::setMonth(int month) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(month, Month);
    this->time = d.getTime();
}
void Moment::setDay(int day) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(day, Day);
    this->time = d.getTime();
}
void Moment::setHour(int hour) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(hour, Hour);
    this->time = d.getTime();
}
void Moment::setMinute(int minute) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(minute, Minute);
    this->time = d.getTime();
}
void Moment::setSecond(int second) {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    d.set(second, Second);
    this->time = d.getTime();
}

int Moment::getYear() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Year);
}
int Moment::getMonth() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Month);
}
int Moment::getDay() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Day);
}
int Moment::getHour() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Hour);
}
int Moment::getMinute() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Minute);
}
int Moment::getSecond() const {
    if(!this->date) {
        throw NotADateException();
    }
    Date d(this->time);
    return d.get(Second);
}

bool Moment::isDate() const { return this->date; }

Moment& Moment::operator=(const Moment& m) {
    this->time= m.time;
    this->date = m.date;
    return *this;
}
Moment Moment::operator+(const Moment& m) const {
    if(this->isDate() && m.isDate()) {
        // date + date
        throw InvalidArgumentException("Can't add a date to a date");
    }

    if(!this->isDate() && !m.isDate()) {
        // délai + délai
        return Moment(this->time + m.time);
    }

    // date + delai


}
Moment Moment::operator+(const int val) const {}
Moment Moment::operator-(const Moment& m) const {}
Moment Moment::operator-(const int val) const {}
bool Moment::operator>(const Moment& m) const {}
bool Moment::operator<(const Moment& m) const {}
bool Moment::operator==(const Moment& m) const {}
Moment Moment::operator++() {}
Moment Moment::operator++(int) {}

string Moment::toString() const {
    return "Moment{time=" + StringUtils::toString(this->time)
        + ", date=" + StringUtils::toString(this->date)
        + "}";
}

int Moment::toSec(int year, int month, int day, int hour, int minute) const {
    Date d(year, month, day, hour, minute, 0);

    return d.getTime();
}

Moment Moment::now() {
    return Moment(Date().getTime());
}


ostream& operator<<(ostream& s, const Moment& m) {
}
//istream& operator>>(istream& s, Moment& m) {}
