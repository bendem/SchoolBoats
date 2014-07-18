#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "classes/Moment.hpp"
#include "classes/exceptions/BadDateOperatorException.hpp"
#include "classes/exceptions/InvalidDateException.hpp"
#include "classes/exceptions/NotADateException.hpp"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

int main()
{
  int choix;
  bool fini = false;
  srand((unsigned)time(NULL));

  while(!fini)
  {
    choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      default : fini = true ; break;
    }
  }

  exit(0);
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des constructeurs susceptibles de lancer une InvalidDateException" << endl;
  cout << " 2. Test des setters susceptibles de lancer une InvalidDateException" << endl;
  cout << " 3. Test des operateurs < > == susceptibles de lancer une BadDateOperatorException" << endl;
  cout << " 4. Test des operateurs + et - susceptibles de lancer une BadDateOperatorException" << endl;
  cout << " 5. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

/**********************************************************************************************/
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch
/**********************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test des constructeurs susceptibles de lancer une exception InvalidDateException --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
  {
    cout << "--> Creation d'un objet de la classe Moment (Date) <--" << endl;
    int  annee, mois, jour;
    cout << "Jour  = ";
    cin >> jour;
    cout << "Mois  = ";
    cin >> mois;
    cout << "Annee = ";
    cin >> annee;
    try {
        Moment d1(annee, mois, jour); // !!!
        cout << "Date entree = " << d1 << endl << endl;
    } catch(InvalidDateException e) {
        cout << e.getMessage() << endl;
    }
    cout << endl;

    cout << "--> Creation d'un objet de la classe Moment (Date + Heure) <--" << endl;
    int  heure, minute;
    cout << "Jour   = ";
    cin >> jour;
    cout << "Mois   = ";
    cin >> mois;
    cout << "Annee  = ";
    cin >> annee;
    cout << "Heure  = ";
    cin >> heure;
    cout << "Minute = ";
    cin >> minute;
    try {
        Moment d2(annee, mois, jour, heure, minute); // !!!
        cout << "Date entree = " << d2 << endl << endl;
    } catch(InvalidDateException e) {
        cout << e.getMessage() << endl;
    }
    cout << endl;
  }
  // ...

  cout << endl;
}

/**********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test des setters susceptibles de lancer une exception InvalidDateException --------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ...
  {
    Moment d1(Moment::now());
    cout << "Date et heure actuelle = " << d1 << endl << endl;
    cout << "Modification de :" << endl;
    cout << "  1. Annee" << endl;
    cout << "  2. Mois" << endl;
    cout << "  3. Jour" << endl;
    cout << "  4. Heure" << endl;
    cout << "  5. Minute" << endl;
    cout << "  6. Seconde" << endl;
    cout << "Choix : ";
    int ch;
    cin >> ch;
    cout << "Nouvelle valeur = ";
    int val;
    cin >> val;

    switch(ch)
    {
      case 1 : d1.setAnnee(val); break;
      case 2 : d1.setMois(val); break;
      case 3 : d1.setJour(val); break;
      case 4 : d1.setHeure(val); break;
      case 5 : d1.setMinute(val); break;
      case 6 : d1.setSeconde(val); break;
      default : break;
    }

    cout << "Date apres modification = " << d1 << endl << endl;
  }
  // ...

  cout << endl;
}

/**********************************************************************************************/
void Essai3()
{
  cout << "----- 4. Test des operateurs > < == susceptibles de lancer une BadDateOperatorException ---" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // On ne peut comparer que 2 dates ou 2 durees !!!
  // ...
  {
    Moment T[4];
    T[0] = Moment(2013, 9, 11);
    T[1] = Moment(2013, 5, 13);
    T[2] = Moment(18);
    T[3] = Moment(63);
    cout << "Objets a comparer :" << endl;
    cout << "  0: " << T[0] << endl;
    cout << "  1: " << T[1] << endl;
    cout << "  2: " << T[2] << endl;
    cout << "  3: " << T[3] << endl;
    int ch1, ch2;
    cout << "Choix : ";
    cin >> ch1;
    cout << "A comparer a : ";
    cin >> ch2;
    cout << endl;
    if ( T[ch1] < T[ch2] ) cout << "--> " << T[ch1] << " < " << T[ch2] << endl;
    if ( T[ch1] > T[ch2] ) cout << "--> " << T[ch1] << " > " << T[ch2] << endl;
    if ( T[ch1] == T[ch2] ) cout << "--> " << T[ch1] << " == " << T[ch2] << endl;
  }
  // ...

  cout << endl;
}

/**********************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test des operateurs de + et - susceptibles de lancer une BadDateOperatorException ---" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // Date + Duree = Date
  // Date - Duree = Date
  // Date + Date --> Exception !
  // Date - Date = Duree

  // Duree + Duree = Duree
  // Duree - Duree = Duree
  // Duree + Date = Date
  // Duree - Date --> Exception !
  // ...
  {
    Moment T[4];
    T[0] = Moment(2013, 9, 11);
    T[1] = Moment(2013, 5, 13);
    T[2] = Moment(18);
    T[3] = Moment(63);
    cout << "Objets a disposition :" << endl;
    cout << "  0: " << T[0] << endl;
    cout << "  1: " << T[1] << endl;
    cout << "  2: " << T[2] << endl;
    cout << "  3: " << T[3] << endl;
    int ch1, ch2;
    cout << "Operande 1 : ";
    cin >> ch1;
    cout << "Operande 2 : ";
    cin >> ch2;
    cout << "Operation (+ ou -) : ";
    char op;
    cin >> op;
    cout << endl;
    if (op == '+')
    {
      Moment d;
      d = T[ch1] + T[ch2];
      cout << "--> " << T[ch1] << " + " << T[ch2] << " = " << d << endl;
    }
    if (op == '-')
    {
      Moment d;
      d = T[ch1] - T[ch2];
      cout << "--> " << T[ch1] << " - " << T[ch2] << " = " << d << endl;
    }
  }
  // ...

  cout << endl;
}

