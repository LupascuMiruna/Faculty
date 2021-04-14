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
            manager(string nume, int an_nastere, int vechime, int mandat);
        };

#endif //INCERCARE1_MANAGER_H
