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
void result(string);
void wait();

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
}

void login() {
    string login;
    string password;

    while(true) {
        cout << endl;
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
            result("Utilisateur inconnu!");
            continue;
        }

        if(currentUser->checkPassword(password)) {
            return;
        } else {
            result("Mot de passe incorrect!");
        }
    }
}

/**
 * When this returns 0, quit
 */
char menu() {
    char input;

    cout << endl << string(70, '=') << endl << endl;
    cout << "Menu " << (currentUser->getRole() == Role::Admin ? "administrateur" : "manager") << endl;
    cout << string(55, '-') << endl;
    if(currentUser->getRole() == Role::Admin) {
        cout << "1. Afficher la liste des utilisateurs" << endl;
        cout << "2. Afficher les infos d'un utilisateur" << endl;
        cout << "3. Creer un utilisateur" << endl;
        cout << "4. Changer un mot de passe" << endl;
    } else {
        cout << "1. Gerer les circuits" << endl;
        cout << "\t1.1. Ajouter un circuit" << endl;
        cout << "\t1.2. Ajouter un circuit a partir d'un fichier texte" << endl;
        cout << "\t1.3. Afficher les donnees d'un circuit" << endl;
        cout << "2. Gerer les regates" << endl;
        cout << "\t2.1. Ajouter une regate" << endl;
        cout << "\t2.2. Afficher la liste des regates" << endl;
        cout << "\t2.3. Afficher une regate" << endl;
        cout << "\t2.4. Supprimer une regate" << endl;
        cout << "3. Gerer une regate" << endl;
        cout << "\t3.1. Ajouter un concurrent" << endl;
        cout << "\t3.2. Ajouter des concurrents depuis un fichier texte" << endl;
        cout << "\t3.3. Lancer la regate" << endl;
    }

    cout << "N. Nouvelle session" << endl;
    cout << "Q. Quitter" << endl;

    cout << "Votre choix: ";
    cin >> input;
    return input;
}

void action(char choice) {
    cout << endl;
    if(currentUser->getRole() == Role::Admin) {
        switch(choice) {
            case '1':
                cout << "Liste des utilisateur" << endl << string(55, '-') << endl;
                userList.list();
                break;
            case '2':
                try {
                    cout << *userList.search(askLogin()) << endl;
                } catch(Exception e) {
                    cout << e << endl;
                }
                wait();
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
    result("Mot de passe change avec succes");
}

void result(string text) {
    cout << endl << " => " << text << endl;
    wait();
}

void wait() {
    // flush
    cin.sync();
    cout << endl << " > Press enter to continue... <";
    // send to the nowhereness
    cin.ignore();
}
