//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PATISERIE_H
#define INCERCARE1_PATISERIE_H

#include <string>
#include <iostream>
#include <vector>

#include "produs.h"
#include "personal.h"
using namespace std;


class patiserie
    {
        static int nr_patiserii;
        string nume;
        string locatie;
        int suprafata;
        int nr_produse = 0;
        int nr_angajati = 0;
        bool state; //daca e deschis sau nu, initial deschise toate
        vector <produs> produse;
        vector <personal> angajati;

        public:
        //constructor
        patiserie();
        patiserie(string nume, string locatie, int suprafata);

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
        void if_open();
        int get_suprafata();

        ///supraincarcarea >> declarat mai jos
        friend istream &operator>>(istream &in, patiserie &P);
        friend ostream &operator<<(ostream &out,const patiserie &P);

        ///setteri
        void set_nume(string new_nume);
        void set_locatie(string new_locatie);

    };


#endif //INCERCARE1_PATISERIE_H
