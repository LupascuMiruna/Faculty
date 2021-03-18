//
// Created by User on 14.03.2021.
//


#include<string>
#include <iostream>
#include<fstream>
#include <vector>
#include "produs.h"
using namespace std;
///constructori
produs::produs(){}
produs::produs(string tip, int gramaj)
{
    this->tip = tip;
    this->gramaj = gramaj;

//ingrediente = new int[];

}

///destrctori
produs::~produs()
{
    //cout <<"Produsul " << this->tip <<" nu mai exista" <<"\n";

}

produs &produs::operator=(const produs& produs1)
{
    this->data_expir = produs1.data_expir;
    this->tip = produs1.tip;
    this->gramaj = produs1.gramaj;
    this->redus = produs1.redus;
    this->pret = produs1.pret;
////////////////////////////////////////////////////////// cum copiez ingrediente
    return *this;
}

produs::produs(const produs &produs1)
{
    this->pret = produs1.pret;
    this->redus = produs1.redus;
    this->gramaj = produs1.gramaj;
    this->tip = produs1.tip;
    this->data_expir = produs1.data_expir;

}

void produs::modifica_gramaj(int x) //cu + daca se mareste, cu  - daca se micsoreaza
{
    this->gramaj += x;
}

void produs::aplica_reducere()
{
    this->pret = this->pret - (this->redus/100) * pret;
}
///seteri
void produs::set_reducere(int x)
{
    this->redus = x;
}
void produs::set_pret(int x)
{
    this->pret = x;
}

///geteri
int produs::get_gramaj()
{
    return this->gramaj;
}
int produs::get_pret()
{
    return this->pret;
}
/// >> <<
ostream& operator<< (ostream &cout, const produs &prod)
{
    cout << prod.tip << " " << prod.gramaj <<"\n";
    return cout;
}

istream& operator>>(istream &cin, produs &prod)
{
    cin >> prod.tip >> prod.gramaj;
    return cin;
}

