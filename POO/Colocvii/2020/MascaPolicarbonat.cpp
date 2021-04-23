//
// Created by User on 20.04.2021.
//
#include <bits/stdc++.h>
#include "MascaPolicarbonat.h"

using namespace std;
MascaPolicarbonat::MascaPolicarbonat():Masca(),tip_prindere(){}
MascaPolicarbonat::~MascaPolicarbonat() {}
MascaPolicarbonat::MascaPolicarbonat(string tip, string culoare, int nr_pliuri,string tip_prindere):
Masca(tip,culoare,nr_pliuri), tip_prindere(tip_prindere){}


MascaPolicarbonat::MascaPolicarbonat(const MascaPolicarbonat& obj):Masca(obj), tip_prindere(tip_prindere){}
MascaPolicarbonat & MascaPolicarbonat::operator=(const MascaPolicarbonat &obj)
        {
            (*this).Masca::operator=(obj); ////////////////////////copiez partea din baza
            tip_prindere = obj.tip_prindere;
            return *this;
        }
std::istream& operator >>(std::istream &in, MascaPolicarbonat& obj)
{
    std::cout << " introduceti tip_prindere: ";
    in >> obj.tip_prindere;
    cout << "Introduceti tip: ";
    in >> obj.tip;
    cout << "Introduceti culoare: ";
    in >> obj.culoare;
    cout << "Introduceti nr_pliuri: ";
    in >> obj.nr_pliuri;
    return in;
}
std::ostream& operator <<(std::ostream &out, const MascaPolicarbonat&obj)
{
    cout << " tip_prindere: ";
    out << obj.tip_prindere;
    cout << " tip: ";
    out << obj.tip;
    cout << " culoare: ";
    out << obj.culoare;
    cout << " nr_pliuri: ";
    out << obj.nr_pliuri;
return out;
}

void MascaPolicarbonat::set_tip_prindere(std::string x)
{
    this->tip_prindere = x;
}
std::string MascaPolicarbonat::get_tip_prindere()const
{
    return tip_prindere;
}