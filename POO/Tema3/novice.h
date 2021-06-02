//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_NOVICE_H
#define INCERCARE1_NOVICE_H

#include "personal.h"
class novice: virtual public personal
        {
protected:
        string mentor;
        public:
            novice() =default;
            novice(string nume, int an_nastere, int vechime, string mentor);
            void print_salariu() const override ;
    ///citire
    istream& read(istream&);
    friend istream& operator>>(istream&, novice&);

    ///afisare
    ostream& print(ostream&);
    friend ostream& operator<<(ostream&, novice&);
        };
#endif //INCERCARE1_NOVICE_H

