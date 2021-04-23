//
// Created by User on 20.04.2021.
//

#ifndef COLOCVIU_MASCA_H
#define COLOCVIU_MASCA_H
#include <bits/stdc++.h>
class Masca
{
protected:
    std::string tip;
    std::string culoare;
    int nr_pliuri;
public:
    Masca();
    Masca(std::string tip, std::string culoare, int nr_pliuri);
    virtual ~Masca();
    Masca(const Masca &obj);
    Masca &operator = (const Masca &obj);
    friend std::istream &operator >> (std::istream &in, Masca &obj);
    friend std::ostream &operator << (std::ostream &out, const Masca& obj);

    std::string get_culoare()const;
    std::string get_tip()const;
    int get_nr_pliuri()const;

    void set_culoare(std::string x);
    void set_tip(std::string x);
    void set_nr_pliuri(int x);

};

#endif //COLOCVIU_MASCA_H
