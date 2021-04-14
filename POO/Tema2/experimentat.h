//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_EXPERIMENTAT_H
#define INCERCARE1_EXPERIMENTAT_H
#include "personal.h"
class experimentat: virtual public personal{
    protected:
        string domeniu;
    public:
        experimentat(string nume, int an_nastere, int vechime, string domeniu);
        void print_salariu();

};

#endif //INCERCARE1_EXPERIMENTAT_H
