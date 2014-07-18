#include <stdlib.h>
#include <iostream>
// #include <string>
#include "time/Moment.hpp"
#include "exceptions/InvalidDateException.hpp"

using namespace std;

void Pause() {
    char buffer;
    cout << endl << "--> RETURN <--";
    cin >> buffer;
}

int main() {

    cout << endl << "(0) ***** PRE TEST by bendem ***************" << endl;
    {
        try {
            Moment d(1990, 9, 14);
        } catch(InvalidDateException e) {
            cout << e << endl;
        }
        Moment d(129);
        try {
            d.setDay(50);
        } catch(NotADateException e) {
            cout << e << endl;
        }
    }

    cout << endl << "(1) ***** Constructeurs par defaut, initialisation (duree), copie de Moment ***************" << endl;
    { // A faire aussi : la methode toString() qui n'affiche rien mais qui retourne un objet string !!!
        Moment d; // constructeur par defaut
        cout << "d (par defaut) = " << d << endl;
        Moment delai(10), delai1(143); // constructeur d'initialisation
        cout << "delai (initialisation de 10 minutes) = " << delai << endl;
        cout << "delai1 (initialisation de 143 minutes) = " << delai1 << endl;
        Moment delai2(delai1); // constructeur de copie
        cout << "delai2 (copie de delai1) = " << delai2 << endl;
        Pause();
    }

    cout << endl << "(2) ***** Constructeur d'initialisation (date --> SANS heure) et getters ***************" << endl;
    {
        Moment date(2013, 9, 14);
        cout << "date (14/09/2013) = " << date << endl;
        cout << "Annee = " << date.getYear() << endl;
        cout << "Mois = " << date.getMonth() << endl;
        cout << "Jour = " << date.getDay() << endl;
        cout << "Heure = " << date.getHour() << endl;
        cout << "Minute = " << date.getMinute() << endl;
        cout << "Seconde = " << date.getSecond() << endl;
        Pause();
    }

    cout << endl << "(3) ***** Constructeur d'initialisation (date --> AVEC heure) et getters ***************" << endl;
    {
        Moment date(2013, 9, 14, 17, 11);
        cout << "date (14/09/2013 17h11) = " << date << endl;
        cout << "Annee = " << date.getYear() << endl;
        cout << "Mois = " << date.getMonth() << endl;
        cout << "Jour = " << date.getDay() << endl;
        cout << "Heure = " << date.getHour() << endl;
        cout << "Minute = " << date.getMinute() << endl;
        cout << "Seconde = " << date.getSecond() << endl;
        Pause();
    }

    cout << endl << "(4) ***** Test de setters (pour la date) ***************" << endl;
    {
        Moment date(2013, 9, 14);
        cout << "date (14/09/2013) = " << date << endl;
        cout << "--> L'annee devient 2014" << endl;
        date.setYear(2014); // A faire aussi : setMois() et setDay()
        cout << "date (apres) = " << date << endl;
        cout << "--> L'heure devient 17h32" << endl;
        date.setHour(17);
        date.setMinute(32); // A faire aussi : setSeconde()
        cout << "date (apres) = " << date << endl;
        Pause();
    }

    cout << endl << "(5) ***** Constructeur de copie (Date) ***************" << endl;
    {
        Moment date(2013, 9, 14), date2(date);
        cout << "date (14/09/2013) = " << date << endl;
        cout << "date2 (copie de date) = " << date2 << endl;
        cout << "--> L'heure de date2 devient 12h34" << endl;
        date2.setHour(12);
        date2.setMinute(34);
        cout << "date = " << date << endl;
        cout << "date2 = " << date2 << endl;
        Pause();
    }

    cout << endl << "(6) ***** Test de la methode Now ***************" << endl;
    {
        cout << "Date et heure actuelle (1) = " << Moment::now() << endl;
        Moment date(Moment::now());
        cout << "Date et heure actuelle (2) = " << date << endl;
        Pause();
    }

    cout << endl << "(7) ***** Test de l'opérateur d'affectation ***************" << endl;
    {
        Moment d, d1(2013, 9, 14);
        cout << "d1 = " << d1 << endl;
        cout << "--> d = d1;" << endl;
        d = d1;
        cout << "d = " << d << endl;
        cout << "--> d = Moment(129);" << endl;
        d = Moment(129);
        cout << "d = " << d << endl;
        Pause();
    }

    cout << endl << "(8) ***** Test de l'operateur + (int) ***************" << endl;
    {
        Moment d, d1(2013, 9, 14, 15, 25);
        cout << "d1 = " << d1 << endl;
        cout << "--> d = d1 + 125;" << endl;
        d = d1 + 125;
        cout << "d1 = " << d1 << endl;
        cout << "d = " << d << endl;
        cout << "--> d = d + 17;" << endl;
        d = d + 17;
        cout << "d = " << d << endl << endl;
        Moment d2(10);
        cout << "d2 = " << d2 << endl;
        cout << "--> d = d2 + 7;" << endl;
        d = d2 + 7;
        cout << "d = " << d << endl;
        Pause();
    }

    cout << endl << "(9) ***** Test de l'operateur - (int) ***************" << endl;
    {
        Moment d, d1(2013, 9, 14, 10, 20);
        cout << "d1 = " << d1 << endl;
        cout << "--> d = d1 - 40;" << endl;
        d = d1 - 40;
        cout << "d1 = " << d1 << endl;
        cout << "d = " << d << endl;
        cout << "--> d = d - 70;" << endl;
        d = d - 70;
        cout << "d = " << d << endl << endl;
        Moment d2(20);
        cout << "d2 = " << d2 << endl;
        cout << "--> d = d2 - 5;" << endl;
        d = d2 - 5;
        cout << "d = " << d << endl;
        Pause();
    }

    cout << endl << "(10) ***** Test de l'operateur + (Moment) ***************" << endl;
    {
        Moment d, date(2013, 9, 14, 9, 20), delai(15);
        cout << "date = " << date << endl;
        cout << "delai = " << delai << endl << endl;

        cout << "--> d = date + delai;" << endl;
        d = date + delai;
        cout << "date = " << date << endl;
        cout << "delai = " << delai << endl;
        cout << "d = " << d << endl << endl;

        cout << "--> d = delai + date;" << endl;
        d = delai + date;
        cout << "date = " << date << endl;
        cout << "delai = " << delai << endl;
        cout << "d = " << d << endl << endl;

        cout << "--> d = date + Moment(30);" << endl;
        d = date + Moment(30);
        cout << "date = " << date << endl;
        cout << "d = " << d << endl << endl;

        cout << "--> d = delai + Moment(30);" << endl;
        d = delai + Moment(30);
        cout << "delai = " << delai << endl;
        cout << "d = " << d << endl;
        Pause();
    }

    cout << endl << "(11) ***** Test de l'operateur - (Moment) ***************" << endl;
    {
        Moment d, date1(2013, 9, 14, 13, 30), date2(2013, 9, 14, 14, 45), d1(20), d2(30);
        cout << "date1 = " << date1 << endl;
        cout << "date2 = " << date2 << endl;
        cout << "d1 = " << d1 << endl;
        cout << "d2 = " << d2 << endl << endl;

        cout << "--> d = date1 - d1; " << endl;
        d = date1 - d1;
        cout << "d = " << d << endl << endl;

        cout << "--> d = date2 - date1; " << endl;
        d = date2 - date1;
        cout << "d = " << d << endl << endl;

        cout << "--> d = d2 - d1; " << endl;
        d = d2 - d1;
        cout << "d = " << d << endl << endl;

        cout << "--> d = d1 - d2; " << endl;
        d = d1 - d2;
        cout << "d = " << d << endl << endl;

        Pause();
    }

    cout << endl << "(12) ***** Test de l'opérateur << ***************" << endl;
    {
        Moment d(15), d1(2013, 9, 14);
        cout << "--> Affichons d : " << d << endl;
        cout << "--> Affichons d1 : " << d1 << endl << endl;
        Pause();
    }

    cout << endl << "(13) ***** Test des operateurs de comparaison < > == ***************" << endl;
    {
        Moment d1(26), d2(15), d3(2013, 8, 29, 17, 15), d4(2013, 8, 29, 17, 30);
        cout << "d1 = " << d1 << endl;
        cout << "d2 = " << d2 << endl;
        cout << "d3 = " << d3 << endl;
        cout << "d4 = " << d4 << endl << endl;
        if (d1 < d2) cout << "La duree d1 est plus petite que la duree d2" << endl;
        if (d1 > d2) cout << "La duree d1 est plus grande que la duree d2" << endl;
        if (d1 == d2) cout << "Les durees d1 et d2 sont identiques" << endl;
        if (d3 < d4) cout << "La date d3 est anterieure a la date d4" << endl;
        if (d3 > d4) cout << "La date d3 est posterieure a la date d4" << endl;
        if (d3 == d4) cout << "Les dates d3 et d4 sont identiques" << endl << endl;
        Pause();
    }

    cout << endl << "(14) ***** Test de l'operateur de pre-incrementation ***************" << endl;
    {
     Moment d(2013, 9, 14, 17, 30);
     cout << "Affichons d'abord d : " << d << endl;
     cout << "Resultat de cout << ++d << endl; :" << endl;
     cout << ++d << endl; // Si tout va bien, d est incremente avant d'etre affiche !
     cout << "et on reaffiche d : " << d << endl << endl;
     Pause();
    }

    cout << endl << "(15) ***** Test de l'operateur de post-incrementation ***************" << endl;
    {
     Moment d(2013, 9, 14, 17, 30);
     cout << "Affichons d'abord d : " << d << endl;
     cout << "Resultat de cout << d++ << endl; :" << endl;
     cout << d++ << endl; // Si tout va bien, d est incremente apres avoir ete affiche !
     cout << "et on reaffiche d :" << d << endl << endl;
    }

    return 0;
}
