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

void StringUtils::write(ostream& os, const string& str) {
	int n = str.size();
	os.write((char*) &n, sizeof(int));
	os.write(str.c_str(), n);
}

string StringUtils::read(istream& is) {
	int n;
	string str;

    is.read((char*) &n, sizeof(int));

    // Create a buffer of the needed size
	char buff[n];
    is.read(buff, n);
    buff[n] = '\0';

    str.assign(buff);
	return str;
}
