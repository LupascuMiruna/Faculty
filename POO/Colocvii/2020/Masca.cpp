//
// Created by User on 20.04.2021.
//
#include<bits/stdc++.h>
#include "Masca.h"

using namespace std;
Masca::~Masca() {}
Masca::Masca(): tip(""),culoare(""), nr_pliuri(0){}
Masca::Masca(string tip, string culoare, int nr_pliuri):tip(tip), culoare(culoare), nr_pliuri(nr_pliuri){}
Masca::Masca(const Masca &obj): tip(obj.tip), culoare(obj.culoare), nr_pliuri(obj.nr_pliuri){}
Masca &Masca::operator = (const Masca &obj)
{
    this ->tip = obj.tip;
    this ->culoare = obj.culoare;
    this ->nr_pliuri = obj.nr_pliuri;
    return *this;
}
istream &operator>>(istream &in, Masca &obj)
{
    cout << "Introduceti tip: ";
    in >> obj.tip;
    cout << "Introduceti culoare: ";
    in >> obj.culoare;
    cout << "Introduceti nr_pliuri: ";
    in >> obj.nr_pliuri;
    return in;
}
ostream &operator<<(ostream &out, const Masca& obj)
{
    cout << " tip: ";
    out << obj.tip;
    cout << " culoare: ";
    out << obj.culoare;
    cout << " nr_pliuri: ";
    out << obj.nr_pliuri;
    return out;
}

string Masca::get_culoare()const
{
    return this->culoare;
}
string Masca::get_tip()const
{
    return this->tip;
}
int Masca::get_nr_pliuri() const
{
    return this->nr_pliuri;
}

void Masca::set_culoare(string x)
{
    this->culoare = x;
}
void Masca::set_tip(string x)
{
    this->tip = x;
}
void Masca::set_nr_pliuri(int  x)
{
    this->nr_pliuri = x;
}



