/*
 * File:   StringUtils.cpp
 * Author: bendem
 */

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
