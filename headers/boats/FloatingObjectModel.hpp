#ifndef FLOATINGOBJECTMODEL_HPP
#define FLOATINGOBJECTMODEL_HPP

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

        friend istream& operator>>(istream&, FloatingObjectModel&);

        static string HOBIE;
        static string BICSPORT;
        static FloatingObjectModel HOBIE_14;
        static FloatingObjectModel HOBIE_16;
};

#endif // FLOATINGOBJECTMODEL_H
