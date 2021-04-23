//
// Created by User on 20.04.2021.
//

#include "MascaChirurgicala.h"
#include<bits/stdc++.h>
using namespace std;

MascaChirugicala::MascaChirugicala():Masca(){}
MascaChirugicala::~MascaChirugicala(){}
MascaChirugicala::MascaChirugicala(string tip, string culoare, int nr_pliuri) :Masca(tip,culoare,nr_pliuri) {}
MascaChirugicala::MascaChirugicala(const MascaChirugicala &obj):Masca(obj) {}
istream &operator>>(istream &in, MascaChirugicala &obj)
{
    cout << "Introduceti tip: ";
    in >> obj.tip;
    cout << "Introduceti culoare: ";
    in >> obj.culoare;
    cout << "Introduceti nr_pliuri: ";
    in >> obj.nr_pliuri;
    return in;
}
ostream &operator<<(ostream &out, const MascaChirugicala& obj)
{
    cout << " tip: ";
    out << obj.tip;
    cout << " culoare: ";
    out << obj.culoare;
    cout << " nr_pliuri: ";
    out << obj.nr_pliuri;
    return out;
}
MascaChirugicala &MascaChirugicala:: operator = (const MascaChirugicala &obj)
{
    this ->tip = obj.tip;
    this ->culoare = obj.culoare;
    this ->nr_pliuri = obj.nr_pliuri;
    return *this;
}