//
// Created by User on 14.04.2021.
//

#ifndef INCERCARE1_GRAMAJ_EXCEPTION_H
#define INCERCARE1_GRAMAJ_EXCEPTION_H

#include <iostream>
using namespace std;

///exceptie custom
class gramaj_exception: public exception {
public:
    const char* what() const noexcept  ///suprascriem functia care returneaza mesajul exceptiei
    {
        return "Gramajul este necorespunzator!!!! REINCEARCA RESETAREA PRODUSULUI";
    }
};

#endif //INCERCARE1_GRAMAJ_EXCEPTION_H
