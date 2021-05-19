//
// Created by User on 19.05.2021.
//

#include "Masca.h"
#include "IO.h"
#include "Ajutor.h"
Masca::Masca(string tip_protectie):
tip_protectie(tip_protectie)
{
};
void Masca::read(istream &in)
{
    vector<string> tipuri = {"ff1", "ff2", "ff3"};
    unsigned int tip_ales = Ajutor::alege(in, "protectie", tipuri);

    tip_protectie = tipuri[tip_ales];


}

void Masca::write(ostream& out) const
{
    out << "Tip protectie: " << tip_protectie << endl;
}