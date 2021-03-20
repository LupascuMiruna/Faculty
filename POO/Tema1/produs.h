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
    double redus;
    double pret;
    vector <string> ingrediente;
    string data_expir;

public:
    //constructor
    produs();
    produs(string tip, int gramaj);

    //destructor
    ~produs();

    ///copy constructor
    produs(const produs& produs1);

    //operator de atribuire
    produs &operator=(const produs &produs1);

    void modifica_gramaj(int x) ;//cu + daca se mareste, cu  - daca se micsoreaza

    void aplica_reducere();

    void adauga_ingredient();
    ///setteri
    void set_reducere(double x);
    void set_pret(double x);
    void set_tip(string new_tip);
    void set_gramaj(int new_gramaj);


    ///geteri
    int get_gramaj();
    double get_pret();
    string get_tip();

    ///supraincarcare << >>
    friend ostream& operator<< (ostream &out, const produs &prod);
    friend istream& operator>>(istream &in, produs &prod);

    ///sa afisam lista de ingrediente



};



#endif //INCERCARE1_PRODUS_H
