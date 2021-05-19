//
// Created by User on 19.05.2021.
//
#include <iostream>
#include<string>
#include<vector>
#include<functional>
#include "Masca.h"
#include "Ajutor.h"

using namespace std;


#ifndef INC_2020V2_MASCACHIRURGICALA_H
#define INC_2020V2_MASCACHIRURGICALA_H

class MascaChirurgicala: public Masca
{
    string culoare;
    int nr_pliuri;
    bool model_special;

public:

    MascaChirurgicala(string = "ff1", string = "", int = 0, bool = false);

    MascaChirurgicala(const MascaChirurgicala&) = default;
    MascaChirurgicala& operator=(const MascaChirurgicala&) = default;

    void read(istream&) override;
    void write(ostream&) const override;



};

#endif //INC_2020V2_MASCACHIRURGICALA_H
