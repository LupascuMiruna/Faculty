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

#ifndef INC_2020V2_MASCAPOLICARBONAT_H
#define INC_2020V2_MASCAPOLICARBONAT_H
class MascaPolicarbonat: public Masca{
    string tip_prindere;
public:
    MascaPolicarbonat(string = "");
    MascaPolicarbonat(const MascaPolicarbonat&) = default;
    MascaPolicarbonat& operator=(const MascaPolicarbonat&) = default;

    void read(istream&) override;
    void write(ostream&) const override;
};
#endif //INC_2020V2_MASCAPOLICARBONAT_H
