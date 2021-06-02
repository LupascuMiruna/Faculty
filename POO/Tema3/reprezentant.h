//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_REPREZENTANT_H
#define INCERCARE1_REPREZENTANT_H
#include "manager.h"
#include "experimentat.h"
class reprezentant: public manager, public experimentat {
    string plan; ///pe plan national sau international
public:
    reprezentant(string nume, int an_nastere, int vechime, string domeniu, int mandat, string plan);
    void set_nume(string new_nume);

};
#endif //INCERCARE1_REPREZENTANT_H
