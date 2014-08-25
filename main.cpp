#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "collections/OrderedList.hpp"
#include "collections/Vector.hpp"
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/OutOfBoundsException.hpp"
#include "utils/StringUtils.hpp"
#include "users/User.hpp"
#include "users/UserList.hpp"

#define USER_FILE "./data/Users.dat"

using namespace std;

int main(int argc, char** argv) {
	User a("a", "a", Role::Admin);
	cout << a << endl;
	cout << User(a) << endl;

	char choice;
	User* currentUser;
	UserList userList(USER_FILE);
	userList.save(USER_FILE);

	try {
		cout << userList.search("a") << endl;
	} catch(Exception e) {
		cout << endl << e << endl;
	}

    return 0;
}
