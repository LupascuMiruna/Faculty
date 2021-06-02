//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_MANAGER_H
#define INCERCARE1_MANAGER_H
#include "personal.h"
class manager: virtual public personal
        {
        protected:
            int mandat;
        public:
            manager() =default;
            manager(string nume, int an_nastere, int vechime, int mandat);
    ///citire
    istream& read(istream&);
    friend istream& operator>>(istream&, manager&);

    ///afisare
    ostream& print(ostream&);
    friend ostream& operator<<(ostream&, manager&);
        };

#endif //INCERCARE1_MANAGER_H
