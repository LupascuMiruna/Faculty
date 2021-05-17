//
// Created by User on 17.05.2021.
//

#ifndef INCERCARE1_PRET_EXCEPTION_H
#define INCERCARE1_PRET_EXCEPTION_H


#include <iostream>
using namespace std;

class pret_exception: public exception {
public:
    const char* what() const noexcept  ///suprascriem functia care returneaza mesajul exceptiei
    {
        return "Mai gandeste-te la pret. REINCEARCA RESETAREA PRODUSULUI";
    }
};
#endif //INCERCARE1_PRET_EXCEPTION_H
