//
// Created by User on 06.05.2021.
//
#include<iostream>
#include "Abonament.h"
using namespace std;

int Abonament::ID = 0;
Abonament::Abonament()
{
    ID++;
    id = ID;
}
Abonament::Abonament(double pret = 0, int nr_min = 0, int nr_sms = 0):
        pret(pret), nr_min(nr_min), nr_sms(nr_sms)
{
    ID++;
    id = ID;
}

istream &operator >>(istream &in, Abonament &obj)
{
    cout << "Pretul: "; in >> obj.pret;
    cout << "Nr minute: "; in >> obj.nr_min;
    cout << "Nr sms: "; in >> obj.nr_sms;
    return in;
}

ostream &operator <<(ostream &out,const Abonament &obj)
{
    out << "Pretul: "<< obj.pret;
    out << "Nr minute: "<< obj.nr_min;
    out << "Nr sms: " << obj.nr_sms;
    return out;
}