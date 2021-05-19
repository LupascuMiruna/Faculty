//
// Created by User on 19.05.2021.
//

#include "MascaPolicarbonat.h"
MascaPolicarbonat::MascaPolicarbonat(string tip_prindere):
        Masca("ff0"),
        tip_prindere(tip_prindere)
{
}

void MascaPolicarbonat::read(istream& in)
{
    cout << "Tipul de prindere: ";
    in >> tip_prindere;
}

void MascaPolicarbonat::write(ostream& out) const
{
    Masca::write(out);
    cout << "Tipul de prindere: " << tip_prindere << endl;
}