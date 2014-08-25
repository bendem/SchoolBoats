#include "utils/StringUtils.hpp"


string StringUtils::toString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

string StringUtils::toString(unsigned int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

string StringUtils::toString(float number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

string StringUtils::toString(bool boolean) {
    return boolean ? "true" : "false";
}

Vector<string> StringUtils::cut(string text, char c) {
    Vector<string> vect(2);
    int index = text.find(c);
    vect.set(0, text.substr(0, index));
    vect.set(1, text.substr(index+1, text.size()));
    return vect;
}
