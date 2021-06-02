//
// Created by User on 14.04.2021.
//

#include "experimentat.h"
experimentat::experimentat(string nume, int an_nastere, int vechime, string domeniu):
        personal(nume, an_nastere, vechime), domeniu(domeniu){}
void experimentat::print_salariu ()const
{
    cout << this->vechime * 200;
}