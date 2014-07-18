#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include "boats/FloatingObject.hpp"

class Activity {

    protected:
        string location;
        string name;
        FloatingObject* object;
        Activity(string, string, const FloatingObject&);
        Activity(const Activity&);
    public:
        ~Activity();

        string getLocation() const;
        string getName() const;
        FloatingObject& getFloatingObject() const;

        void setLocation(string);
        void setName(string);
        void setFloatingObject(FloatingObject);

        virtual string toString() const;
        virtual void display() const;

        virtual string getInfo() const = 0;

};

#endif // ACTIVITY_H
