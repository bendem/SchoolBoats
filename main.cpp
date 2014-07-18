/*
 * File:   main.cpp
 * Author: bendem
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "collections/Vector.hpp"
#include "exceptions/InvalidArgumentException.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

int main(int argc, char** argv) {
    cout << "Test IDE" << StringUtils::toString(5) << endl;
    try {
        Vector<int> v(-1);
    } catch (InvalidArgumentException e) {
        cout << e.getMessage() << endl;
    }

    Vector<int> v(2);
    cout << "size: " << v.maxSize() << " / current size: " << v.currentSize() << endl;
    v.set(0, 5);
    cout << v.get(0) << endl;
    cout << "size: " << v.maxSize() << " / current size: " << v.currentSize() << endl;
    v.set(1, 4);
    cout << "size: " << v.maxSize() << " / current size: " << v.currentSize() << endl;
    cout << v.get(1) << endl;
    cout << "size: " << v.maxSize() << " / current size: " << v.currentSize() << endl;


    return 0;
}
