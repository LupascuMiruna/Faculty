//
// Created by User on 17.05.2021.
//

#ifndef INCERCARE1_TIP_EXCEPTION_H
#define INCERCARE1_TIP_EXCEPTION_H


#include <iostream>
using namespace std;

class tip_exception: public exception {
public:
    const char* what() const noexcept  ///suprascriem functia care returneaza mesajul exceptiei
    {
        return "Denumirea trebuie sa contina doare litere mici. REINCEARCA RESETAREA PRODUSULUI";
    }
};
#endif //INCERCARE1_TIP_EXCEPTION_H
