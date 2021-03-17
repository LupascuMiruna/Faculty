//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PRODUS_H
#define INCERCARE1_PRODUS_H
#include <string>
#include <iostream>
#include <vector>
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
    produs(){}
    produs(string tip)
    {
        this->tip = tip;

        //ingrediente = new int[];

    }
    //destructor
    ~produs(){}
    ///~produs(){ delete[]ingrediente;}
    //copy constructor
    produs(const produs& produs1)
    {
        this->data_expir = produs1.data_expir;
        this->tip = produs1.tip;
        this->gramaj = produs1.gramaj;
        this->redus = produs1.redus;
        this->pret = produs1.pret;
        ////////////////////////////////////////////////////////// cum copiez ingrediente

    }
    //operator de atribuire
    produs operator=(const produs &produs1)
    {
        this->redus = produs1.redus;
        this->gramaj = produs1.gramaj;
        this->tip = produs1.tip;
        this->data_expir = produs1.data_expir;

        return *this;
    }
    void modifica_gramaj(int x) //cu + daca se mareste, cu  - daca se micsoreaza
    {
        this->gramaj += x;
    }
    void aplica_reducere(int x)
    {
        this->pret = this->pret - (this->redus/100) * pret;
    }
    void adauga_ingredient()
    {

    }

    //geteri
    ///sa afisam lista de ingrediente

    //seteri



};

#endif //INCERCARE1_PRODUS_H
