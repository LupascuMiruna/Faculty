//
// Created by User on 19.05.2021.
//
#include <iostream>
#include<string>
#include<vector>
#include<functional>
#include "IO.h"

using namespace std;

#ifndef INC_2020V2_MASCA_H
#define INC_2020V2_MASCA_H
class Masca: public IO
        {
protected:
    string tip_protectie;
public:
    Masca(string);
    Masca(const Masca&) = default;
    Masca& operator=(const Masca&) = default;

    void read(istream&) override;
    void write(ostream&) const override;
};


#endif //INC_2020V2_MASCA_H
