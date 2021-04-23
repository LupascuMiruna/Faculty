//
// Created by User on 22.04.2021.
//

#ifndef COLOCVIU_DEZINFECTANT_H
#define COLOCVIU_DEZINFECTANT_H
#include<bits/stdc++.h>

class Dezinfectant
{
protected:
    int nr_organisme_ucise;
    std::vector<std::string>suprafete;
    std::vector<std::string>ingrediente;
public:
    virtual ~Dezinfectant();
    Dezinfectant();
    Dezinfectant(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise);
    Dezinfectant(const Dezinfectant& obj);
    Dezinfectant &operator =(const Dezinfectant&  obj);
    friend std::istream &operator >> (std::istream &in, Dezinfectant& obj);
    friend std::ostream &operator <<(std::ostream &out, const Dezinfectant& obj);

    std::vector<std::string> get_ingrediente()const;
    std::vector<std::string> get_suprafete()const;
    int get_nr_oganisme_ucise()const;

    void set_ingrediente(std::string& x);
    void set_suprafete(std::string& x);
    void set_nr_organisme_ucise(int x);

    virtual double eficienta()=0;




};

#endif //COLOCVIU_DEZINFECTANT_H
