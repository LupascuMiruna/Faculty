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
            novice(string nume, int an_nastere, int vechime, string mentor);
            void print_salariu() const override ;
        };
#endif //INCERCARE1_NOVICE_H
