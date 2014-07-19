#ifndef FLOATINGOBJECT_HPP
#define FLOATINGOBJECT_HPP

#include <iostream>
#include <string>
#include "boats/FloatingObjectModel.hpp"

using namespace std;

class FloatingObject {

    private:
        string identifier;
        FloatingObjectModel model;

    public:
        FloatingObject();
        FloatingObject(string, FloatingObjectModel);
        FloatingObject(const FloatingObject&);

        void setIdentifier(string);
        void setModel(FloatingObjectModel);

        string getIdentifier() const;
        const FloatingObjectModel& getModel() const;

        string toString() const;
        void display() const;

        friend ostream& operator<<(ostream&, const FloatingObject&);
        friend istream& operator>>(istream&, FloatingObject&);

};

#endif // FLOATINGOBJECT_HPP
