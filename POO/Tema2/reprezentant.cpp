//
// Created by User on 14.04.2021.
//

#include "reprezentant.h"
reprezentant::reprezentant(string nume, int an_nastere, int vechime, string domeniu, int mandat, string plan):
    personal(nume, an_nastere, vechime),
    manager(nume, an_nastere, vechime, mandat),
    experimentat(nume, an_nastere, vechime, domeniu),
    plan(plan){}
void reprezentant::set_nume(string new_nume){
    this->nume = new_nume;
}
