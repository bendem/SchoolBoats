#include <iostream>
#include <string>
#include <stdlib.h>
#include "boats/FloatingObject.hpp"
#include "boats/FloatingObjectModel.hpp"

using namespace std;

int main()
{
using std::string;

    cout << endl << "(1) ***** Test de la classe ModeleObjetFlottant *****" << endl;
    {
        FloatingObjectModel mof1;
        mof1.display();
        mof1.setManufacturer("Hobie");
        mof1.setModel("15");
        mof1.setSize(11.25f);
        mof1.display();
        cout << "Constructeur = " << mof1.getManufacturer() << endl;
        cout << "Modele = " << mof1.getModel() << endl;
        cout << "Taille = " << mof1.getSize() << endl ;
    } // Appel du destructeur de ma1 (automatique)

    {
        string constructeur("BIC Sport");
        FloatingObjectModel mof2(constructeur,"KJ14",10.09f);
        cout << endl;
        mof2.display();
        {
            FloatingObjectModel mof3(mof2);
            string modele = "RT14";
            mof3.setModel(modele);
            mof3.display();
        } // Appel du destructeur de ma3 (automatique)

        mof2.display();
    } // Appel du destructeur de ma2 (automatique)

    // Modifications de la classe ObjetFlottant (A FAIRE !!!) :
    // On remplace la variable Modele (du type char*) par la variable Modele du type ModeleObjetFlottant
    // --> Le jeu de Test2 ne sera donc plus valable avec la premiere version de la classe ObjetFlottant --> c'est normal
    cout << endl << "(2) ***** Test du constructeur par defaut de ObjetFlottant *****" << endl;
    {
        FloatingObject objetFlottant;
        objetFlottant.display();
    }

    cout << endl << "(3) **** Test des setters/getters *****" << endl;
    {
        FloatingObject objetFlottant;
        objetFlottant.setIdentifier("HC-1716");
        objetFlottant.setModel(FloatingObjectModel("Hobie","14",10.46f));
        objetFlottant.display();
        cout << "Identifiant : " << objetFlottant.getIdentifier() << endl;
        objetFlottant.getModel().display();
    }

    cout << endl << "(4) ***** Test du constructeur d'initialisation de ObjetFlottant *****" << endl;
    {
        FloatingObject objetFlottant("BI-4456", FloatingObjectModel("BIC Sport","15",12.14f));
        objetFlottant.display();
        cout << "Identifiant : " << objetFlottant.getIdentifier() << endl;
        objetFlottant.getModel().display();
    }

    cout << endl << "(5) ***** Test du constructeur de copie de ObjetFlottant *****" << endl;
    {
        FloatingObject objetFlottant1("IN-2201", FloatingObjectModel("INPRES Sport","16",16.25f));
        cout << "objetFlottant1 (AVANT) :" << endl;
        objetFlottant1.display();
        {
            FloatingObject objetFlottant2(objetFlottant1);
            cout << "objetFlottant2 :" << endl;
            objetFlottant2.display();
            objetFlottant2.setIdentifier("IN-2202");
            objetFlottant2.display();
        }
        cout << "objetFlottant1 (APRES) :" << endl;
        objetFlottant1.display();
    }

    cout << endl << "(6) ***** Test des variables membres statiques de ModeleObjetFlottant *****" << endl;
    {
        cout << "Liste des noms des fabricants disponibles :" << endl;
        cout << FloatingObjectModel::HOBIE << endl;
        cout << FloatingObjectModel::BICSPORT << endl;

        cout << endl << "Creation d'un ModeleObjetFlottant du frabicant BICSPORT :" << endl;
        FloatingObjectModel mof(FloatingObjectModel::BICSPORT,"18",18.89f);
        mof.display();

        cout << endl << "Creation d'un ObjetFlottant du modele HOBIE_14 :" << endl;
        FloatingObject objetFlottant("BI-1111", FloatingObjectModel::HOBIE_14);
        objetFlottant.display();
        cout << endl;
    }

    return 0;
}
