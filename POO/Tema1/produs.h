//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PRODUS_H
#define INCERCARE1_PRODUS_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



class produs
{
    string tip; //amandina, cozonac...
    int gramaj;
    int redus;
    int pret;
    vector <string> ingrediente;
    string data_expir;

public:
    //constructor
    produs();
    produs(string tip, int gramaj);

    //destructor
    ~produs();
    ///~produs(){ delete[]ingrediente;}
    //copy constructor
    produs(const produs& produs1);

    //operator de atribuire
    produs &operator=(const produs &produs1);

    void modifica_gramaj(int x) ;//cu + daca se mareste, cu  - daca se micsoreaza

    void aplica_reducere(int x);

    void adauga_ingredient();
    ///setteri
    void set_reducere(int x);

    ///geteri
    int get_gramaj();

    //supraincarcare <<
    friend ostream& operator<< (ostream &cout, const produs &prod);



    ///sa afisam lista de ingrediente



};

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

void produs::aplica_reducere(int x)
{
    this->pret = this->pret - (this->redus/100) * pret;
}
///seteri
void produs::set_reducere(int x)
{
    this->redus = x;
}

///geteri
int produs::get_gramaj()
{
    return this->gramaj;
}
//
ostream& operator<< (ostream &cout, const produs &prod)
{

    cout << prod.tip << " " << prod.gramaj <<"\n";

    return cout;
}


#endif //INCERCARE1_PRODUS_H
