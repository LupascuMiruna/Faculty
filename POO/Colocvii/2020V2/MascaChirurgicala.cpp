//
// Created by User on 19.05.2021.
//

#include "MascaChirurgicala.h"



MascaChirurgicala::MascaChirurgicala(string protectie, string culoare,int nr_pliuri,  bool model_special) :
Masca(protectie), culoare(culoare), nr_pliuri(nr_pliuri), model_special(model_special) {}

void MascaChirurgicala::read(istream &in)
{
   Masca::read(in);
   cout <<"alegeti culoarea: ";
   in >> culoare;
   cout <<"alegeti nr_pliuri: ";
    in >> nr_pliuri;

    unsigned int _model_special = Ajutor::alege(in, "masca", {"speciala", "normala"});

    model_special = _model_special == 0;
}

void MascaChirurgicala::write(ostream& out) const
{
    Masca::write(out);
    cout << "Culoarea: " << culoare << endl;
    cout << "Numar pliuri: " << nr_pliuri << endl;
    cout << "Model special: " << (model_special ? "DA" : "NU") << endl;
}
