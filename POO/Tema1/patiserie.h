//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PATISERIE_H
#define INCERCARE1_PATISERIE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "produs.h"
#include "personal.h"
using namespace std;


class patiserie
    {
        static int nr_patisrii;
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
        friend istream &operator>>(istream &fin, patiserie &P);
        friend ostream &operator<<(ostream &fout,const patiserie &P);

    };
///constructor
patiserie::patiserie()
{
    this->state = 1;
}
patiserie::patiserie(string nume, string locatie, int suprafata)
{
    this->nume = nume;
    this->locatie = locatie;
    this->suprafata = suprafata;
    this->state = 1;
}

///destructor
patiserie::~patiserie()
{
    //cout <<"Patiseria " << this->nume <<" din "<< this->locatie << " a fost desfiintata." <<"\n";
}


patiserie &patiserie::operator=(const patiserie &p)
{
    this->nume = p.nume;
    this->locatie = p.locatie;
    this->suprafata = p.suprafata;
    this->state = p.state;
    //this->produse = p.produse;

    return *this;
}

///functii pe produse
void patiserie::adauga_produs(produs prod)
{
    this->nr_produse += 1;
    this->produse.push_back(prod);

}

void patiserie::afiseaza_produse()
{
    int i;
    cout <<"Patiseria "<< this->nume <<" are urmatoarele produse:\n";
    for (i = 0; i < this->produse.size(); ++i)
        cout << this->produse[i];
    cout <<"\n";

}

/// functii pe personal
void patiserie::adauga_personal(personal pers)
{
    this->nr_angajati += 1;
    this->angajati.push_back(pers);
}
void patiserie::afiseaza_personal()
{
    cout <<"Patiseria "<< this->nume <<" din " << this->locatie <<" are urmatorii angajati:\n";
    for (int i = 0; i < this->angajati.size(); ++i)
        cout <<this->angajati[i] <<" ";
}


void patiserie::open_shop()
{this->state = 1;}

void patiserie::close_shop()
{this->state = 0;}

void patiserie::if_open()
{
    if (this->state == 1)
        cout<<"Patiseria " << this->nume <<" din "<< this->locatie <<": OPEN :)" <<"\n";
    else
        cout<<"Patiseria " << this->nume <<" din "<< this->locatie <<": CLOSE :(" <<"\n";
}


int patiserie::get_suprafata()
{
    return this->suprafata;
}


istream& operator>> (istream &cin,  patiserie &P)
{
    cin >> P.nume >> P.locatie >> P.suprafata;
    P.state = 1;
    return cin;

}

ostream& operator<< (ostream &cout, const patiserie &P)
{

    cout <<"Patiseria: "<< P.nume <<" din "<<P.locatie <<" are urmatoarele produse: \n";
    for (int i = 0; i < P.produse.size(); ++i)
        cout << P.produse[i];

    return cout;
}

#endif //INCERCARE1_PATISERIE_H
