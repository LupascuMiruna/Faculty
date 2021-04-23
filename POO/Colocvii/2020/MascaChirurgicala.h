//
// Created by User on 20.04.2021.
//

#ifndef COLOCVIU_MASCACHIRURGICALA_H
#define COLOCVIU_MASCACHIRURGICALA_H
#include "Masca.h"
#include <bits/stdc++.h>
class MascaChirugicala: public Masca
        {
        public:
        MascaChirugicala();
        MascaChirugicala(std::string tip, std::string culoare, int nr_pliuri);
        ~MascaChirugicala();
        MascaChirugicala(const MascaChirugicala &obj);
        MascaChirugicala &operator = (const MascaChirugicala &obj);
        friend std::istream &operator >> (std::istream &in, MascaChirugicala& obj);
        friend std::ostream &operator << (std::ostream &out, const MascaChirugicala& obj);
        };

#endif //COLOCVIU_MASCACHIRURGICALA_H
