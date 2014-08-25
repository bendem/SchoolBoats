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
char menu();
void action(char);
string askLogin();
void addUser();
void changePassword(string);

// Global stuff
UserList userList(USER_FILE);
User* currentUser;

int main(int argc, char** argv) {
	char choice;
	userList.save(USER_FILE);

	login();
	while(true) {
		choice = menu();
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
char menu() {
	string input;

	// TODO Clearscreen?
	cout << endl << "Menu " << (currentUser->getRole() == Role::Admin ? "administrateur" : "manager") << endl;
	if(currentUser->getRole() == Role::Admin) {
		cout << "1. Afficher la liste des utilisateurs" << endl;
		cout << "2. Afficher les infos d'un utilisateur" << endl;
		cout << "3. Creer un utilisateur" << endl;
		cout << "4. Changer un mot de passe" << endl;
	} else {
	}

	cout << "N. Nouvelle session" << endl;
	cout << "Q. Quitter" << endl;


	cin >> input;
	return input.c_str()[0];
}

void action(char choice) {
	// TODO Clearscreen?
	if(currentUser->getRole() == Role::Admin) {
		switch(choice) {
			case '1':
				userList.list();
				break;
			case '2':
				try {
					cout << *userList.search(askLogin()) << endl;
				} catch(Exception e) {
					cout << e << endl;
				}
				break;
			case '3':
				addUser();
				break;
			case '4':
				changePassword(askLogin());
				break;
		}
	} else {
		// TODO Manager menu
	}
}

string askLogin() {
	string login;
	cout << "Entrez le nom de l'utilisateur: ";
	cin >> login;
	return login;
}

void addUser() {
	string user, password;
	Role role;
	int iRole;

	user = askLogin();
	cout << "Entrez le mot de passe de l'utilisateur: ";
	cin >> password;
	cout << "Entrez le role de l'utilisateur (1. Admin, 2. Manager): ";
	cin >> iRole;

	role = static_cast<Role>(iRole);

	try {
		userList.add(new User(user, password, role));
	} catch(DuplicatedUserException e) {
		// Duplicated user login
		cout << "Nom d'utilisateur deja utilise!" << endl;
		return;
	}
	userList.save(USER_FILE);
}

void changePassword(string login) {
	User* u;
	try {
		u = userList.search(login);
	} catch(Exception e) { // TODO Change that
		cout << e << endl;
		return;
	}
	// TODO Check previous password
	string newPass;
	cout << "Entrez le nouveau mot de passe: ";
	cin >> newPass;
	u->setPassword(newPass);
	userList.save(USER_FILE);
}
