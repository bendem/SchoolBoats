#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "collections/OrderedList.hpp"
#include "collections/Vector.hpp"
#include "exceptions/InvalidArgumentException.hpp"
#include "exceptions/OutOfBoundsException.hpp"
#include "exceptions/UserNotFoundException.hpp"
#include "users/User.hpp"
#include "users/UserList.hpp"
#include "utils/Menu.hpp"
#include "utils/StringUtils.hpp"

#define USER_FILE "./data/Users.dat"

using namespace std;

void action(int);
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
            case 0:
                return 0;
            case 8:
                login();
                break;
            default:
                action(choice);
        }
    }
}

void action(int choice) {
    cout << endl;
    if(currentUser->getRole() == Role::Admin) {
        switch(choice) {
            case 1:
                cout << "Liste des utilisateur" << endl << string(55, '-') << endl;
                userList.list();
                break;
            case 2:
                try {
                    cout << *userList.search(askLogin()) << endl;
                } catch(UserNotFoundException e) {
                    result("Utilisateur non trouve");
                }
                break;
            case 3:
                addUser();
                break;
            case 4:
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
        wait();
        return;
    }
    userList.save(USER_FILE);
    result("Utilisateur ajoute");
}

void changePassword(string login) {
    User* u;
    try {
        u = userList.search(login);
    } catch(UserNotFoundException e) {
        cout << e << endl;
        return;
    }
    // TODO Check previous password
    string newPass;
    cout << "Entrez le nouveau mot de passe: ";
    cin >> newPass;
    u->setPassword(newPass);
    userList.save(USER_FILE);
    result("Mot de passe change avec succes");
}
