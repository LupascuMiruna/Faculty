//
// Created by User on 06.05.2021.
//

#ifndef COLOCVIU2019R_ABONAT_H
#define COLOCVIU2019R_ABONAT_H
#include<iostream>
#include<string>

#include "Abonament.h"
using namespace std;
class Abonat
{
protected:
    static int CT;
    string nume;
    int tel;
    string abonament;
    Abonament *a;

public:
    Abonat(string nume, string abonament);
    string getabonament();
    int gettel();
    friend istream& operator>>(istream &in, Abonat& ob);
    friend ostream &operator <<(ostream &out, const Abonat &ob);
};

#endif //COLOCVIU2019R_ABONAT_H
