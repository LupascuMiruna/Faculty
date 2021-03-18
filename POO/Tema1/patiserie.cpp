////
//// Created by User on 14.03.2021.
////
#include "patiserie.h"
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
//#include <fstream>
#include "produs.h"
#include "personal.h"
using namespace std;

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
///copy constructor
patiserie::patiserie(const patiserie &p)
{
    this->nume = p.nume;
    this->locatie = p.locatie;
    this->suprafata = p.suprafata;
    this->state = p.state;
    this->produse = p.produse;
    this->angajati = p.angajati;
    this->nr_angajati = p.nr_angajati;
    this->nr_produse = p.nr_produse;

}

patiserie &patiserie::operator=(const patiserie &p)
{
    this->nume = p.nume;
    this->locatie = p.locatie;
    this->suprafata = p.suprafata;
    this->state = p.state;
    this->produse = p.produse;
    this->angajati = p.angajati;
    this->nr_angajati = p.nr_angajati;
    this->nr_produse = p.nr_produse;

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

///setteri
void patiserie::set_nume(string new_nume)
{
    this->nume = new_nume;
}

void patiserie::set_locatie(string new_locatie)
{
    this->locatie = new_locatie;
}