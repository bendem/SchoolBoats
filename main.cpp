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

void login();
char menu(Role);
void action(char);

// Global stuff
UserList userList(USER_FILE);
User* currentUser;

int main(int argc, char** argv) {
	char choice;
	userList.save(USER_FILE);

	login();
	while(true) {
		choice = menu(currentUser->getRole());
		switch(choice) {
			case 'Q':
			case 'q':
				return 0;
			case 'N':
			case 'n':
				login();
				break;
			default:
				action(choice);
		}
	}

    return 0;
}

void login() {
	string login;
	string password;

	while(true) {
		cout << endl << endl << endl;
		cout << "***************************" << endl;
		cout << "*   MySailingWord stuff   *" << endl;
		cout << "***************************" << endl;
		cout << "Entrez votre nom d'utilisateur: ";
		cin >> login;
		cout << "Entrez votre mot de passe: ";
		cin >> password;

		try {
			currentUser = userList.search(login);
		} catch(Exception e) {
			cout << "Utilisateur inconnu!" << endl;
			continue;
		}

		if(currentUser->checkPassword(password)) {
			return;
		} else {
			cout << "Mot de passe incorrect!" << endl;
		}
	}
}

/**
 * When this returns 0, quit
 */
char menu(Role role) {
	string input;

	cout << endl << "Menu " << (role == Role::Admin ? "administrateur" : "manager") << endl;
	// TODO Menus

	cout << "N. Nouvelle session" << endl;
	cout << "Q. Quitter" << endl;


	cin >> input;
	return input.c_str()[0];
}

void action(char choice) {
}
