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
    double reducere = (this->redus/100) * this->pret;

    this->pret = this->pret - reducere;
}
///seteri
void produs::set_reducere(double x)
{
    this->redus = x;
}
void produs::set_pret(double x)
{
    this->pret = x;
}

void produs::set_tip(string new_tip)
{
    this->tip = new_tip;
}
void produs::set_gramaj(int new_gramaj)
{
    this->gramaj = new_gramaj;
}

///geteri
string produs::get_tip()
{
    return this->tip;
}
int produs::get_gramaj()
{
    return this->gramaj;
}
double produs::get_pret()
{
    return this->pret;
}
/// >> <<
ostream& operator<< (ostream &out, const produs &prod)
{
    out << prod.tip << " " << prod.pret <<"\n";
    return out;
}

istream& operator>>(istream &in, produs &prod)
{
    in >> prod.tip >> prod.gramaj;
    return in;
}

