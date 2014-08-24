#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "boats/Course.hpp"
#include "collections/Vector.hpp"
#include "collections/OrderedList.hpp"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();

int main() {
    int choix;
    bool fini = false;
    srand((unsigned) time(NULL));

    while(!fini) {
        choix = Menu();

        switch(choix) {
            case 1 : Essai1(); break;
            case 2 : Essai2(); break;
            case 3 : Essai3(); break;
            default : fini = true ; break;
        }
    }

    exit(0);
}

int Menu() {
    cout << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "--- JEU DE TEST 6 --------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << " 1. Test du template Vecteur avec des entiers" << endl;
    cout << " 2. Test du template Vecteur avec des objets de la classe Stage" << endl;
    cout << endl << "et si vous voulez prendre de l'avance..." << endl << endl;
    cout << " 3. Test du template ListeTriee avec des entiers" << endl; // pas obligatoire pour l'evaluation des jeux de test !!!
    cout << " 4. Quitter" << endl << endl;

    int ch;
    cout << "  Choix : ";
    cin >> ch; // Faites pas le biess !
    return ch;
}

/*******************************************************************************************************/
void Essai1()
{
    cout << "----- 1. Test du template Vecteur avec des entiers ------------------------" << endl;
    cout << "Creation d'un vecteur de 5 cases..." << endl;
    Vector<int> vec(5);
    vec.display();                                         // --> -- -- -- -- --
    cout << endl;

    cout << "L'element d'indice 2 devient 34" << endl;
    if (vec.isValid(2))
        vec.set(2, 34);
    vec.display();                                         // --> -- -- 34 -- --
    cout << endl;

    cout << "L'element d'indice 4 devient 71" << endl;
    if (vec.isValid(4))
        vec.set(4, 71);
    try  {
        vec.display();                                         // --> -- -- 34 -- 71
    } catch(Exception e) {
        cout << e << endl;
        exit(1);
    }
    cout << endl;

    cout << "On recupere l'element d'indice 2 (sans le retirer !!!)" << endl;
    if (vec.isValid(2) && vec.isUsed(2)) {
        int val = vec.get(2);
        cout << "Element recupere = " << val << endl;
    }
    else
        cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;

    cout << "On recupere l'element d'indice 3 (sans le retirer !!!)" << endl;
    if (vec.isValid(3) && vec.isUsed(3)) {   // ce serait beau de gerer ceci avec des exceptions... :-)
        int val= vec.get(3);
        cout << "Element recupere = " << val << endl;
    }
    else cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;
    vec.display();                                         // --> -- -- 34 -- 71
    cout << endl;

    cout << "On retire l'element d'indice 2" << endl;
    if (vec.isValid(2) && vec.isUsed(2)) {  // ce serait beau de gerer ceci avec des exceptions... :-)
        int val = vec.remove(2);
        cout << "Element recupere = " << val << endl;
    }
    else
        cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;
    vec.display();                                         // --> -- -- -- -- 71
    cout << endl;

    cout << "On ajoute 43 en utilisant l'operateur +" << endl;
    // operator+ : Ajout dans la premiere case libre du vecteur
    vec + 43;
    try {
        vec.display();                                         // --> 43 -- -- -- 71
    } catch (Exception e) {
        cout << e;
        exit(1);
    }
    cout << endl;

    cout << "On ajoute 59 en utilisant l'operateur +" << endl;
    vec + 59;
    vec.display();                                         // --> 43 59 -- -- 71
    cout << endl;
}

/*********************************************************************************************/
void Essai2() {
    cout << "----- 2. Test du template Vecteur avec des objets de la classe Stage -------------" << endl;
    cout << "Creation d'un vecteur de 7 cases..." << endl;
    Vector<Stage> vec(7);
    vec.display();
    cout << endl;

    Course s1(
        "Planche a voile AS2013", "Abri du Port Cros, Cagnes-sur-mer",
        FloatingObject("XX-1111", FloatingObjectModel("BICSport", "12", 12.16f)),
        2,
        Planning(Moment(2013, 9, 4), Moment(2014, 6, 25))
    );
    Course s2(
        "Catamaran A43", "Abri du Port Cros, Cagnes-sur-mer",
        FloatingObject("XX-1111", FloatingObjectModel::HOBIE_14),
        1,
        Planning(Moment(2013, 8, 26), Moment(2013, 8, 30))
    );

    cout << "L'element d'indice 2 devient Planche a voile AS2013" << endl;
    if (vec.isValid(2))
        vec.set(2, s1);
    vec.display();           /* /!\/!\ SEG FAULT /!\/!\ */
    cout << endl;

    cout << "L'element d'indice 4 devient Catamaran A43" << endl;
    if (vec.isValid(4))
        vec.set(4, s2);
    vec.display();
    cout << endl;

    cout << "On recupere l'element d'indice 2 (sans le retirer !!!)" << endl;
    if (vec.isValid(2) && vec.isUsed(2)) {
        Stage s = vec.get(2);
        cout << "Element recupere = " << s << endl;
    }
    else cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;

    cout << "On recupere l'element d'indice 3 (sans le retirer !!!)" << endl;
    if (vec.isValid(3) && vec.isUsed(3)) {
        Stage s = vec.get(3);
        cout << "Element recupere = " << s << endl;
    }
    else
        cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;

    vec.display();
    cout << endl;

    cout << "On retire l'element d'indice 2" << endl;
    if (vec.isValid(2) && vec.isUsed(2)) {
        Stage s = vec.remove(2);
        cout << "Element recupere = " << s << endl;
    }
    else
        cout << "Case non occupee ou indice invalide !" << endl;
    cout << endl;

    vec.display();
    cout << endl;

    cout << "On ajoute Trimaran Stage 2013 en utilisant l'operateur +" << endl;
    // operator+ : Ajout dans la premiere case libre du vecteur
    vec + Course("Trimaran Stage 2013", "Belle Ile en Mer", FloatingObject("YY-1112", FloatingObjectModel("BICSport", "16", 16.16f)), 3, Planning(Moment(2013, 1, 15), Moment(2014, 1, 30)));
    vec.display();
    cout << endl;

    Course s3("Inpres Voiles 2013", "Les quais de Seraing beach", FloatingObject("IN-1009", FloatingObjectModel::HOBIE_14), 1, Planning(Moment(2013, 10, 1), Moment(2013, 11, 30)));
    cout << "On ajoute Inpres Voiles 2013 en utilisant l'operateur +" << endl;
    vec + s3;
    vec.display();
    cout << endl;
}

/*********************************************************************************************/
void Essai3()
{
    cout << "----- 3. Test du template ListeTriee avec des entiers ----------------------" << endl;
    OrderedList<int> liste;
    liste.display();
    cout << endl;

    cout << "On insere 11..." << endl;
    liste.add(11);
    liste.display();
    cout << endl;

    cout << "On insere 19..." << endl;
    liste.add(19);
    liste.display();
    cout << endl;

    cout << "On insere 5..." << endl;
    liste.add(5);
    liste.display();
    cout << endl;

    cout << "On insere 15..." << endl;
    liste.add(15);
    liste.display();
    cout << endl;

    cout << "On insere 21..." << endl;
    liste.add(21);
    liste.display();
    cout << endl;

    cout << "On met la liste en mode DECROISSANT... " << endl;
    liste.setMode(OrderedList<int>::DESCENDING);
    liste.display();
    cout << endl;

    cout << "On insere 18..." << endl;
    liste.add(18);
    liste.display();
    cout << endl;

    cout << "On met la liste en mode CROISSANT... " << endl;
    liste.setMode(OrderedList<int>::ASCENDING);
    liste.display();
    cout << endl;

    cout << "On insere 13..." << endl;
    liste.add(13);
    liste.display();
    cout << endl;
}


