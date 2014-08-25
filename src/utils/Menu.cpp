#include "utils/Menu.hpp"

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

int menu() {
    int input;

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

    cout << "8. Nouvelle session" << endl;
    cout << "0. Quitter" << endl;

    cout << endl << "Votre choix: ";
    cin >> input;
    return input;
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
