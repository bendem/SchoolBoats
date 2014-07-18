#include "boats/FloatingObjectModel.hpp"

FloatingObjectModel::FloatingObjectModel() : FloatingObjectModel("", "", 0) {}

FloatingObjectModel::FloatingObjectModel(const string manufacturer, const string model, float size) {
    this->manufacturer = manufacturer;
    this->model = model;
    this->size = size;
}

FloatingObjectModel::FloatingObjectModel(const FloatingObjectModel& other) {
    this->manufacturer = other.manufacturer;
    this->model = other.model;
    this->size = other.size;
}

FloatingObjectModel::~FloatingObjectModel() {}

void FloatingObjectModel::setManufacturer(const string manufacturer) {
    this->manufacturer = manufacturer;
}
void FloatingObjectModel::setModel(const string model) {
    this->model = model;
}
void FloatingObjectModel::setSize(float size) {
    this->size = size;
}

string FloatingObjectModel::getManufacturer() const {
    return this->manufacturer;
}
string FloatingObjectModel::getModel() const {
    return this->model;
}
float FloatingObjectModel::getSize() const {
    return this->size;
}

string FloatingObjectModel::toString() const {
    return "FloatingObjectModel{manufacturer='" + this->manufacturer
        + "', model='" + this->model
        + "', size=" + StringUtils::toString(this->size)
        + "}";
}

void FloatingObjectModel::display() const {
    cout << toString() << endl;
}

string FloatingObjectModel::HOBIE = "Hobie";
string FloatingObjectModel::BICSPORT = "BIC Sport";

FloatingObjectModel FloatingObjectModel::HOBIE_14 = FloatingObjectModel("Hobie", "14", 10.46);
FloatingObjectModel FloatingObjectModel::HOBIE_16 = FloatingObjectModel("Hobie", "16", 10.46);
