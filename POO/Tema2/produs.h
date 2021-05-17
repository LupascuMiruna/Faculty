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
protected:
    std::string tip; //dulce/sarat
    int gramaj;
    double redus;
    double pret;
    std::string data_expir;

public:
    //constructor
    produs();
    produs(std::string tip, int gramaj);

    ///destructor virtual
    virtual ~produs();

    ///copy constructor
    produs(const produs& produs1);

    //operator de atribuire
    produs &operator=(const produs &produs1);

    void modifica_gramaj(int x) ;//cu + daca se mareste, cu  - daca se micsoreaza
    void modifica_produs(int new_gramaj, int new_pret, string new_tip);

    void aplica_reducere();

    void adauga_ingredient();
    ///setteri
    void set_reducere(double x);
    virtual void set_pret(double x);
    void set_tip(std::string new_tip);
    void set_gramaj(int new_gramaj);


    ///geteri
    int get_gramaj();
    double get_pret();
    string get_tip();

    ///supraincarcare << >>
    friend ostream& operator<< (std::ostream &out, const produs &prod);
    friend istream& operator>>(std::istream &in, produs &prod);

    ///sa afisam lista de ingrediente

};



#endif //INCERCARE1_PRODUS_H
