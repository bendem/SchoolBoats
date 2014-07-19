#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "boats/Activity.hpp"
#include "boats/FloatingObject.hpp"
#include "time/Planning.hpp"
#include "utils/StringUtils.hpp"

class Course : public Activity {

    private:
        int level;
        Planning planning;
    public:
        Course();
        Course(string, string, const FloatingObject&, int, const Planning&);

        int getLevel() const;
        const Planning& getPlanning() const;

        void setLevel(int);
        void setPlanning(const Planning&);

        string toString() const;
        void display() const;

        string getInfo() const;

        void read(istream&);

        Course& operator=(const Course&);
        friend ostream& operator<<(ostream&, const Course&);
        friend istream& operator>>(istream&, Course&);

};

#endif // COURSE_H
