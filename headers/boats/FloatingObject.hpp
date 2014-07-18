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

        string getIdentifier();
        FloatingObjectModel& getModel();

        string toString();
        void display();

};

#endif // FLOATINGOBJECT_HPP
