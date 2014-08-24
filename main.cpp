/*
 * File:   main.cpp
 * Author: bendem
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "collections/OrderedList.hpp"
#include "collections/Vector.hpp"
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/OutOfBoundsException.hpp"
#include "utils/StringUtils.hpp"

using namespace std;

int main(int argc, char** argv) {
    cout << "Test IDE" << StringUtils::toString(5) << endl;

    {
	    try {
	        Vector<int> v(-1);
	    } catch (InvalidArgumentException e) {
	        cout << e.getMessage() << endl;
	    }

	    Vector<int> v(3);
		v.display();
	    v.set(0, 5);
		v.display();
	    v.set(1, 4);
		v.display();
		cout << endl;

	    Vector<int> b(v);
	    b.display();
	    cout << endl << b.size() << endl;
	    b.display();
	    cout << endl;
    }

    cout << endl << "Lists" << endl << endl;

	{
	    OrderedList<int> list;
	    list.add(5);
	    list.add(2);
	    list.add(4);
	    list.display();
	    cout << endl << list.get(0) << list.get(1) << list.get(2) << endl;
	    OrderedList<int> lel(list);
	    lel.display();
	}


    return 0;
}
