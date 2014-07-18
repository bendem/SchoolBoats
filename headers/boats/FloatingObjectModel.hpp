#ifndef FLOATINGOBJECTMODEL_H
#define FLOATINGOBJECTMODEL_H

#include <iostream>
#include <string>
#include "utils/StringUtils.hpp"

using namespace std;

class FloatingObjectModel {
    private:
        string manufacturer;
        string model;
        float size;
    public:
        FloatingObjectModel();
        FloatingObjectModel(const string, const string, float);
        FloatingObjectModel(const FloatingObjectModel& other);
        ~FloatingObjectModel();

        void setManufacturer(const string);
        void setModel(const string);
        void setSize(float);

        string getManufacturer() const;
        string getModel() const;
        float getSize() const;

        string toString() const;
        void display() const;

        static string HOBIE;
        static string BICSPORT;
        static FloatingObjectModel HOBIE_14;
        static FloatingObjectModel HOBIE_16;
};

#endif // FLOATINGOBJECTMODEL_H
