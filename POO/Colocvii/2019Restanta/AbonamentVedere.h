//
// Created by User on 06.05.2021.
//

#ifndef COLOCVIU2019R_ABONAMENTVEDERE_H
#define COLOCVIU2019R_ABONAMENTVEDERE_H
#include "Abonament.h"
#include<iostream>
using namespace std;
class AbonamentVedere :public Abonament
{
public:
    AbonamentVedere(double pret = 0, int nr_min = 0, int nr_sms = 0):
    Abonament(pret/2.5, 3*nr_min, 0){};


};

#endif //COLOCVIU2019R_ABONAMENTVEDERE_H
