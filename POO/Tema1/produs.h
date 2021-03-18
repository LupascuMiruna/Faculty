//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PRODUS_H
#define INCERCARE1_PRODUS_H

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

    void aplica_reducere();

    void adauga_ingredient();
    ///setteri
    void set_reducere(int x);
    void set_pret(int x);

    ///geteri
    int get_gramaj();
    int get_pret();

    //supraincarcare << >>
    friend ostream& operator<< (ostream &cout, const produs &prod);
    friend istream& operator>>(istream &cin, produs &prod);

    ///sa afisam lista de ingrediente



};



#endif //INCERCARE1_PRODUS_H
