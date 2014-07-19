#include "time/Moment.hpp"

Moment::Moment() : Moment(0) {}
Moment::Moment(int time) : Moment(time * 60, false) {}
Moment::Moment(int time, bool isDate) {
    this->date = isDate;
    this->time = time;
}

Moment::Moment(int year, int month, int day) : Moment(year, month, day, 0, 0) {}
Moment::Moment(int year, int month, int day, int hour, int minute) {
    this->date = true;
    this->time = Date(year, month, day, hour, minute, 0).getTime();
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
        return Moment(this->time + m.time, false);
    }

    // date + delai
    Date d(this->date ? this->time : m.time);
    d.add(this->date ? m.time : this->time, Second);
    return Moment(d.getTime(), true);
}
Moment Moment::operator+(const int val) const {
    if(this->date) {
        Moment m(*this);
        m.setMinute(m.getMinute() + val);
        return m;
    }
    return Moment(this->time + val*60, false);
}
Moment Moment::operator-(const Moment& m) const {
    if(!this->date && m.date) {
        // délai - date
        throw InvalidArgumentException("You shouldn't remove a delay from a date");
    }

    if(!this->date && !m.date) {
        // délai - délai
        return Moment(this->time - m.time, false);
    }

    if(this->date && !m.date) {
        // date - délai
        Date d(this->time);
        d.remove(m.time, Second);
        return Moment(d.getTime(), true);
    }

    // date - date
    return Moment(Date(this->time) - Date(m.time), false);
}
Moment Moment::operator-(const int val) const {
    if(this->date) {
        Date d(this->time);
        d.remove(val, Minute);
        return Moment(d.getTime(), true);
    }

    return Moment(this->time - val*60, false);
}
bool Moment::operator>(const Moment& m) const {
    if(this->date != m.date) {
        throw InvalidArgumentException("Can't compare a date with a delay");
    }
    return this->time > m.time;
}
bool Moment::operator<(const Moment& m) const {
    if(this->date != m.date) {
        throw InvalidArgumentException("Can't compare a date with a delay");
    }
    return this->time < m.time;
}
bool Moment::operator==(const Moment& m) const {
    if(this->date != m.date) {
        throw InvalidArgumentException("Can't compare a date with a delay");
    }
    return this->time == m.time;
}
Moment& Moment::operator++() {
    this->setDay(this->getDay()+1);
    return *this;
}
Moment Moment::operator++(int) {
    Moment m(*this);
    this->setDay(this->getDay()+1);
    return m;
}

string Moment::toString() const {
    return "Moment{time=" + StringUtils::toString(this->time)
        + ", date=" + StringUtils::toString(this->date)
        + "}";
}

Moment Moment::now() {
    return Moment(Date().getTime(), true);
}

ostream& operator<<(ostream& s, const Moment& m) {
    if(m.isDate()) {
        Date d(m.time);
        return s << d.get(Year) << "/" <<  d.get(Month) << "/" << d.get(Day) << " " << d.get(Hour) << ":" << d.get(Minute) << ":" << d.get(Second);
    }
    return s << m.toString();
}
istream& operator>>(istream& s, Moment& m) {
    return s >> m.time >> m.date;
}
