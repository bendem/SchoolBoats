#include <stdlib.h>
#include <iostream>
#include "boats/FloatingObject.hpp"

using namespace std;

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make

int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + affiche *****" << endl;
  {
    FloatingObject objetFlottant;
    objetFlottant.display();
  } // La presence des accolades assure que le destructeur de avion sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters *****" << endl;
  {
    FloatingObject objetFlottant;
    objetFlottant.setIdentifier("HC-1716");
    objetFlottant.setModel("HobieCat16Easy");
    objetFlottant.display();
    cout << "Identifiant = " << objetFlottant.getIdentifier() << endl;
    cout << "Modele      = " << objetFlottant.getModel() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation *****" << endl;
  {
    FloatingObject objetFlottant("HC-1821","HobieCat21Hard");
    objetFlottant.display();
  }

  cout << endl << "(4) ***** Test du constructeur de copie *****" << endl;
  {
    FloatingObject objetFlottant1("HC-2110","HobieCat10Easy");
    cout << "objetFlottant1 (AVANT) :" << endl;
    objetFlottant1.display();
    {
      FloatingObject objetFlottant2(objetFlottant1);
      cout << "objetFlottant2 :" << endl;
      objetFlottant2.display();
      objetFlottant2.setIdentifier("HC-2112");
      objetFlottant2.display();
    } // de nouveau, les {} assurent que objetFlottant2 sera detruit avant la suite
    cout << "objetFlottant1 (APRES) :" << endl;
    objetFlottant1.display();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique (constructeur par defaut) *****" << endl;
  {
    FloatingObject *p = new FloatingObject();
    p->setIdentifier("BI-4115");
    p->setModel("BicCat15Easy");
    p->display();
    cout << "Le modele de cet objet flottant est : " << p->getModel() << endl;
    delete p;
  }

  cout << endl << "(6) ***** Test d'allocation dynamique (constructeur de copie) *****" << endl;
  {
    FloatingObject objetFlottant1("BI-7415","BicCat21Hard");
    cout << "objetFlottant1 (AVANT) :" << endl;
    objetFlottant1.display();
    FloatingObject* p = new FloatingObject(objetFlottant1);
    cout << "La copie :" << endl;
    p->display();
    cout << "Destruction de la copie..." << endl;
    delete p;
    cout << "objetFlottant1 (APRES) :" << endl;
    objetFlottant1.display();
  }

  return 0;
}
