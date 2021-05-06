//
// Created by User on 06.05.2021.
//

#ifndef COLOCVIU2019R_RETEA_H
#define COLOCVIU2019R_RETEA_H
#include<iostream>
#include<string>
#include <vector>
#include "Abonament.h"
#include "Abonat.h"
class Retea
{
protected:
    vector <Abonat*> abonati;
    vector <Abonament*> abonamente;

    static Retea* instance;
    Retea(){}

public:
    static Retea* getInstance()
    {
        if(instance == nullptr)return new Retea();
        return instance;
    }
    void addAbonament(string abon);

    void afis();
    void createapel(int destin, int rec);
    void createsms(int destin, int rec);
    ~Retea()
    {
        for(int i = 0; i <abonamente.size();++i)
            delete abonamente[i];
        abonamente.clear();
    }
    void Register(string nume, string abon);


};
#endif //COLOCVIU2019R_RETEA_H
