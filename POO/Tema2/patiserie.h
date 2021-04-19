//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PATISERIE_H
#define INCERCARE1_PATISERIE_H

#include <iostream>
#include <vector>

#include "produs.h"
#include "personal.h"
using namespace std;


class patiserie
    {

        std::string nume;
        std::string locatie;
        int suprafata;
        bool state; //daca e deschis sau nu, initial deschise toate
        vector <produs> produse;
        vector <personal> angajati;

        public:
        //constructor
        patiserie();
        patiserie(std::string nume, string locatie, int suprafata);

        //destructor
        ~patiserie();

        //constructor de copiere
        patiserie(const patiserie &p);

        //operator =
        patiserie &operator=(const patiserie &p);

        ///functii pe produse
        void adauga_produs(produs prod);
        void afiseaza_produse();

        ///functii pe personal
        void adauga_personal(personal pers);
        void afiseaza_personal();

        ///functii pe patiserie
        void open_shop();
        void close_shop();
        void check_status();
        int get_suprafata();

        ///supraincarcarea >> declarat mai jos
        friend istream &operator>>(std::istream &in, patiserie &P);
        friend ostream &operator<<(std::ostream &out,const patiserie &P);

        ///setteri
        void set_nume(std::string new_nume);
        void set_locatie(std::string new_locatie);

    };


#endif //INCERCARE1_PATISERIE_H
