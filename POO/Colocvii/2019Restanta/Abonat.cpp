//
// Created by User on 06.05.2021.
//

#include "Abonat.h"
#include<iostream>
#include<string>

using namespace std;

int Abonat::CT = 0;
Abonat::Abonat(string nume =" ", string abonament = "") :nume(nume),abonament(abonament)
{
    CT++;
    tel = CT;
}
string Abonat::getabonament() {return abonament;}
int Abonat:: gettel(){return tel;}

istream &operator>>(istream &in, Abonat& ob)
{
    cout <<" nume: ";in >>ob.nume;
    cout << "tel: "; in  >> ob.tel;
    return in;
}
ostream &operator <<(ostream &out, const Abonat &ob)
{
    out <<" nume: "<< ob.nume;
    out << "tel: " << ob.tel;
    return out;
}