//
// Created by User on 06.05.2021.
//

#ifndef COLOCVIU2019R_ABONAMENT_H
#define COLOCVIU2019R_ABONAMENT_H
#include<iostream>
using namespace std;

class Abonament
{
protected:
    static int ID;
    int id;
    double pret;
    int nr_min, nr_sms;
public:
    Abonament();
    Abonament(double pret, int nr_min, int nr_sms);

    friend istream &operator >>(istream &in, Abonament &obj);
    friend ostream &operator <<(ostream &out, const Abonament &obj);



};


#endif //COLOCVIU2019R_ABONAMENT_H
