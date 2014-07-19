#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "boats/Regatta.hpp"
#include "boats/Course.hpp"
#include "boats/FloatingObject.hpp"
#include "boats/FloatingObjectModel.hpp"
#include "time/Moment.hpp"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();

int main() {
    int choix;
    bool fini = false;
    srand((unsigned)time(NULL));

    while(!fini) {
        choix = Menu();
        switch(choix) {
            case 1 : Essai1(); break;
            case 2 : Essai2(); break;
            case 3 : Essai3(); break;
            case 4 : Essai4(); break;
            default : fini = true ; break;
        }
    }

    return 0;
}

int Menu() {
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "----- JEU DE TEST 4 -------------------------------------------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << " 1. Test de la classe Regate" << endl;
    cout << " 2. Test de la classe Stage" << endl;
    cout << " 3. Heritage et hierarchie : Test des methodes (non) virtuelles" << endl;
    cout << " 4. Test du downcasting et du dynamic-cast" << endl;
    cout << " 5. Quitter" << endl << endl;

    int ch;
    cout << "  Choix : ";
    cin >> ch; // Faites pas le biess !
    return ch;
}

/***********************************************************************************************/
// A FAIRE : la classe abstraite Activite qui contient le nom (string), le lieu (string), un objet flottant (FloatingObject*)
//           la classe Regate heritant de Activite, contenant en plus un nom de course (string) et une date de depart (Moment)
//           la methode Affiche (NON virtuelle !!!) dans Activite et dans Regate
//           les methodes << et >> de Regate
//           l'operateur d'affectation (=) de Regate
void Essai1() {
    cout << "----- 1.1 Test du constructeur par defaut de Regate ------------------------" << endl;
    Regatta r1;
    cout << "--> Voici r1 :" << endl;
    r1.display();
    cout << endl << endl;

    cout << "----- 1.2 Test du constructeur d'initialisation de Regate ------------------" << endl;
    Regatta r2("Les Voiles d'Antibes", "Baie des Anges, Antibes", FloatingObject("XX-1111", FloatingObjectModel::HOBIE_14), "Coupe des Fleurs", Moment(2013, 9, 1, 14, 10));
    cout << "--> Voici r2 :" << endl;
    r2.display();
    cout << endl << endl;

    cout << "----- 1.2 Test de quelques methodes heritees ou non ------------------------" << endl;
    // Attention !!! N'oubliez pas de faire tous les setters/getters meme s'il ne sont pas testés ici !
    cout << "--> On modifie la date de depart de r2..." << endl;
    r2.setStart(Moment(2013, 9, 2, 13, 30));
    cout << "Nom : " << r2.getName() << endl;
    cout << "Lieu : " << r2.getLocation() << endl;
    cout << "Objet flottant : " << r2.getFloatingObject() << endl;  // A faire : opération << de FloatingObject
    cout << "Nom Course : " << r2.getRaceName() << endl;
    cout << "Date/heure depart : " << r2.getStart() << endl;
    cout << endl << endl;

    cout << "----- 1.3 Allocation dynamique de Regate avec pointeur de type Regate + test du constructeur de copie ------" << endl;
    cout << "--> On copie r2..." << endl;
    Regatta *p1 = new Regatta(r2); // Vive le constructeur de copie !
    cout << "--> Voici la copie de r2 :" << endl;
    p1->display();
    cout << "--> On detruit la copie de r2..." << endl;
    delete p1;
    cout << "--> Revoici r2 :" << endl;
    r2.display();
    cout << endl << endl;

    /*cout << "----- 1.4 Allocation dynamique de Regate avec pointeur de type Activity (Upcasting) -----" << endl;
    Activity *p2 = new Regatta(r2);
    p2->display();  // Quelle methode Affiche est appelee ? celle de Activity ou de Regate ?
    delete p2;      // Quel destructeur est appele ? celui de Activity ou de Regate ?
    cout << endl << endl;

    cout << "----- 1.5 Test de cin et cout ----------------------------------------------" << endl;
    Regatta r3;
    cout << "--> Entrez la Regate r3 :" << endl;
    cin >> r3;
    cout << endl << "--> Voici r3 :" << endl;
    cout << r3 << endl << endl;

    cout << "----- 1.6 Test de l'operateur d'affectation --------------------------------" << endl;
    Regatta r4;
    cout << "--> Execution du code r4 = r3; :" << endl;
    r4 = r3;
    cout << "--> r4 = " << r4 << endl;*/
}

/***********************************************************************************************/
// A FAIRE : la classe Planning qui contient deux dates (Moment)
//           la classe Stage qui herite de Activity, contenant en plus un niveau (int) et un horaire (Planning)
//           la methode Affiche (NON virtuelle !!!) de Stage
//           les operateurs << et >> de Stage
//           l'operateur d'affectation (=) de Stage
void Essai2() {
    cout << "----- 2.1 Test du constructeur par defaut ----------------------------------" << endl;
    Course s1;
    cout << "--> Voici s1 :" << endl;
    s1.display();
    cout << endl;

    cout << "----- 2.2 Test des setters -------------------------------------------------" << endl;
    s1.setName("Catamaran A43");
    s1.setLocation("Abri du Port Cros, Cagnes-sur-mer");
    s1.setFloatingObject(FloatingObject("XX-1111", FloatingObjectModel::HOBIE_14));
    s1.setLevel(1);
    s1.setPlanning(Planning(Moment(2013, 8, 26), Moment(2013, 8, 30)));
    cout << "--> Voici s1 (apres les setters) :" << endl;
    s1.display();
    cout << endl;

    cout << "----- 2.3 Test des getters -------------------------------------------------" << endl;
    cout << "Nom            : " << s1.getName() << endl;
    cout << "Lieu           : " << s1.getLocation() << endl;
    cout << "Objet flottant : " << s1.getFloatingObject() << endl;
    cout << "Niveau         : " << s1.getLevel() << endl;
    cout << "Horaire        : " << s1.getPlanning() << endl;
    cout << endl;

    cout << "----- 2.4 Test du constructeur d'initialisation ----------------------------" << endl;
    FloatingObject of("XX-1111", FloatingObjectModel("BICSport", "12", 12.16f));
    Planning ho(Moment(2013, 9, 4), Moment(2014, 6, 25));
    Course s2("Planche a voile AS2013", "Abri du Port Cros, Cagnes-sur-mer", of, 2, ho);
    cout << "--> Voici s2 :" << endl;
    s2.display();
    cout << endl;

    cout << "----- 2.5 Allocation dynamique de Stage avec pointeur de type Stage + test du constructeur de copie ------" << endl;
    cout << "--> Copie de s2..." << endl;
    Course *p1 = new Course(s2); // Vive le constructeur de copie !
    cout << "--> Voici la copie de s2 :" << endl;
    p1->display();
    cout << "--> Destruction de la copie..." << endl;
    delete p1;
    cout << "--> Revoici s2 :" << endl;
    s2.display();
    cout << endl;

    cout << "----- 2.6 Allocation dynamique de Stage avec pointeur de type Activity (Upcasting) -----" << endl;
    Activity *p2 = new Course(s2);
    p2->display();  // Quelle methode Affiche est appelee ? celle de Activity ou de Stage ?
    delete p2;      // Quel destructeur est appele ? celui de Activity ou de Stage ?
    cout << endl;

    cout << "----- 2.7 Test de cin et cout ----------------------------------------------" << endl;
    Course s3;
    cout << "--> Entrez le stage s3 :" << endl;
    cin >> s3;
    cout << endl << "--> Voici s3 :" << endl;
    cout << s3 << endl;
    cout << endl;

    cout << "----- 2.8 Test de l'operateur d'affectation --------------------------------" << endl;
    Course s4;
    cout << "--> Execution du code s4 = s3; :" << endl;
    s4 = s3;
    cout << "--> s4 = " << s4 << endl;
}

/******************************************************************************************/
// A FAIRE : La méthode virtuelle pure getInfo() de la classe Activity
//           Les methodes getInfo() de Regate et Stage qui surchargent celle de la classe Activity
void Essai3() {
    srand((unsigned)time(NULL));

    cout << "----- 3.1 Allocation dynamique d'activites --------------------------------" << endl;
    Activity* activite[10];

    for (int i=0 ; i<10 ; i++) {  // Tracez vos constructeurs !!!
        cout << endl << "activite[" << i << "] :" << endl;
        int n = rand()%2;
        switch(n) {
            case 0 : activite[i] = new Regatta();
            break;

            case 1 : activite[i] = new Course();
            break;
        }
    }
    cout << endl;

    // Rappel : on vous demande de définir la methode Affiche en NON virtuelle a des fins
    // pedagogiques, dans le but de comprendre la difference entre virtuelle et non virtuelle
    cout << "----- 3.2 Test de la methode NON VIRTUELLE Affiche() (redefinie dans chaque classe heritee) -------" << endl;
    for (int i = 0 ; i < 10; i++) {
        cout << endl << "activite[" << i << "] :" << endl;
        activite[i]->display();
    }
    cout << endl;

    cout << "----- 3.3 Test de la methode VIRTUELLE getInfo() (redefinie dans chaque classe heritee) -------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << endl << "activite[" << i << "] : " << activite[i]->getInfo() << endl;
    }
    cout << endl;

    cout << "----- 3.4 Liberation memoire ----------------------------------------------------------------------------" << endl;
    for (int i=0 ; i<10 ; i++)
        delete activite[i];  // Tout se passe-t-il comme vous voulez ?
    // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

/*********************************************************************************************/
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous
void Essai4() {
    srand((unsigned) time(NULL));

    cout << "----- 4.1 Allocation dynamique d'activites --------------------------------" << endl;
    Activity* activite[10];

    for (int i = 0; i < 10; i++) {  // Tracez vos constructeurs !!!
        cout << endl << "activite[" << i << "] :" << endl;
        int n = rand() % 2;
        switch(n) {
            case 0 : activite[i] = new Regatta();
            break;

            case 1 : activite[i] = new Course();
            break;

        }
    }
    cout << endl;

    cout << "----- 4.2 Test du downcasting et dynamic-cast ------------------------------" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "activite[" << i << "] ";
        Regatta* pRegate = dynamic_cast<Regatta*>(activite[i]);
        if (pRegate != NULL) cout << "est une Regate" << endl;
        Course* pStage = dynamic_cast<Course*>(activite[i]);
        if (pStage != NULL) cout << "est un Stage" << endl;
    }
    cout << endl;
}
