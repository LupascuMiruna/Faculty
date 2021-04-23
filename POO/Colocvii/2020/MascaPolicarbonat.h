//
// Created by User on 20.04.2021.
//

#ifndef COLOCVIU_MASCAPOLICARBONAT_H
#define COLOCVIU_MASCAPOLICARBONAT_H

#include "Masca.h"
#include <bits/stdc++.h>
class MascaPolicarbonat: public Masca
{
protected:
    std::string tip_prindere;
public:
    MascaPolicarbonat();
    ~MascaPolicarbonat();
    MascaPolicarbonat(std::string tip, std::string culoare, int nr_pliuri, std::string tip_prindere);
    MascaPolicarbonat(std::string tip_prindere);
    MascaPolicarbonat(const MascaPolicarbonat&obj);
    MascaPolicarbonat &operator = (const MascaPolicarbonat &obj);
    friend std::istream &operator>>(std::istream &in, MascaPolicarbonat&obj);
    friend std::ostream &operator<<(std::ostream &out, const MascaPolicarbonat& obj);

    void set_tip_prindere(std::string x);
    std::string get_tip_prindere()const;


};
#endif //COLOCVIU_MASCAPOLICARBONAT_H
