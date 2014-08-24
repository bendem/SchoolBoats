#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
#include <sstream>

using namespace std;

class StringUtils {

    public:
        static string toString(int);
        static string toString(unsigned int);
        static string toString(float);
        static string toString(bool);

};

#endif

