//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PERSONAL_H
#define INCERCARE1_PERSONAL_H

#include<string>
#include<iostream>

class personal
        {
            string nume;
            int varsta;
            string tip;//manager, contabil, bucatar, casier
            string cnp;
            string email;

        public:
            string get_nume(){return nume;}
            void set_nume(string new_nume){nume = new_nume;}
            void set_varsta(int new_varsta){varsta = new_varsta;}

        };

#endif //INCERCARE1_PERSONAL_H
