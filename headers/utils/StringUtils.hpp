#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
#include <sstream>
#include "collections/Vector.hpp"

using namespace std;

// Prevents circular include problems
template<class T>
class Vector;

class StringUtils {

    public:
        static string toString(int);
        static string toString(unsigned int);
        static string toString(float);
        static string toString(bool);
        static Vector<string> cut(string, char);

};

#endif
