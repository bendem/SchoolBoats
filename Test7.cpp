#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>

#include "classes/Activite.hpp"
#include "classes/Moment.hpp"
#include "classes/Regate.hpp"
#include "classes/FichierRegates.hpp"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      case 5 : Essai5(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test preliminaire de la serialisation d'une Regate" << endl;
  cout << " 2. Test de FichierRegates : Creation du fichier avec quelques regates" << endl;
  cout << " 3. Test de FichierRegates : Listing (cout) des regates presentes dans le fichier" << endl;
  cout << " 4. Test de FichierRegates : Ajout d'une regate au fichier existant" << endl;
  cout << " 5. Test de FichierRegates : Recherche d'une regate dans le fichier" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

/*********************************************************************************************/
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test preliminaire de la serialisation d'une Regate ------" << endl;
  // Pas encore de classe FichierRegates !!! La Regate gere elle-meme sa serialisation !!!!

  Regate r("Les Voiles d'Antibes","Baie des Anges,Antibes",ObjetFlottant("XX-1111",ModeleObjetFlottant::HOBIE_14),"Coupe des Fleurs",Moment(2013,9,1,14,10));
  r.affiche();
  cout << endl;

  cout << "----- Sauvegarde de la regate dans le fichier LesVoilesDAntibes.dat -----" << endl;
  ofstream fichier1("data/LesVoilesDAntibes.dat",ios::out);
  r.save(fichier1);
  fichier1.close();

  cout << "----- Chargement de la regate situee dans le fichier LesVoilesDAntibes.dat -----" << endl;
  ifstream fichier2("data/LesVoilesDAntibes.dat",ios::in);
  Regate r2;
  r2.load(fichier2);
  fichier2.close();
  r2.affiche();
  cout << endl;
}

/*********************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test de FichierRegates : creation du fichier avec quelques regates -----" << endl;

  Regate r1("Les Voiles d'Antibes","Baie des Anges,Antibes",ObjetFlottant("XX-1111",ModeleObjetFlottant::HOBIE_14),"Coupe des Fleurs",Moment(2013,9,1,14,10));
  Regate r2("Inpres Cup 2013","Baie des Hauts Fourneaux,Seraing",ObjetFlottant("YY-1199",ModeleObjetFlottant::HOBIE_16),"Inpres Cup",Moment(2013,11,15,15,0));
  Regate r3("Paradise Boats","Quai des Anges,LA",ObjetFlottant("ZZ-2222",ModeleObjetFlottant::HOBIE_14),"Coupe des Anges",Moment(2013,12,1,10,30));
  Regate r4("Les Voiles liegeoises","Baie Gloesener,Liege",ObjetFlottant("PE-1221",ModeleObjetFlottant::HOBIE_16),"Coupe des isiliens",Moment(2013,10,13,13,10));

  FichierRegates fichier("data/Regates.dat");
  fichier.save(r1);
  fichier.save(r2);
  fichier.save(r3);
  fichier.save(r4);
}

/*********************************************************************************************/
void Essai3()
{
  cout << "-----  3. Test de FichierRegates : Listing (cout) des regates presentes dans le fichier -----" << endl;
  FichierRegates fichier("data/Regates.dat");
  fichier.list();  // n'affiche que sur le cout... ooouuhh!!!
}

/*********************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test de FichierRegates : Ajout d'une regate au fichier existant -----" << endl;

  Regate r("Catamaran Cup 2013","Baie des noyes,Ostende",ObjetFlottant("AZ-1234",ModeleObjetFlottant::HOBIE_14),"Catamaran Cup",Moment(2013,11,20,14,0));

  FichierRegates fichier("data/Regates.dat");
  fichier.save(r);
  fichier.list();
}

/*********************************************************************************************/
void Essai5()
{
  cout << "----- 5. Test de FichierRegates : Recherche d'une regate dans le fichier -----" << endl;
  Regate r;

  FichierRegates fichier("data/Regates.dat");

  int ret = fichier.load(r,"La coupe des naufrages");   // Pour bien faire, r doit etre passe par...
  if (ret == 0)
  {
    cout << "----> Regate trouvee :-) <----" << endl;
    r.affiche();
  }
  else cout << "-----> Regate NON trouvee !!! <-----" << endl;

  cout << endl << endl;

  ret = fichier.load(r,"Inpres Cup 2013");
  if (ret == 0)
  {
    cout << "----> Regate trouvee :-) <----" << endl;
    r.affiche();
  }
  else cout << "-----> Regate NON trouvee !!! <-----" << endl;
}
