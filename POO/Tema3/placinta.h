//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_PLACINTA_H
#define INCERCARE1_PLACINTA_H

#include "produs.h"

class placinta: public produs {
    string umplutura;
    double pret_unitar;//pret pe 100g


    public:
        void set_pret(double x) override;
        placinta(string tip, string umplutura, int gramaj, double pret_unitar);

};

#endif //INCERCARE1_PLACINTA_H
