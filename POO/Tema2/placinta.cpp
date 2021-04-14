//
// Created by User on 14.04.2021.
//
#include<string>
#include <iostream>
#include "placinta.h"
using namespace std;

void placinta::set_pret(double x) {
    this->pret = min(x, this->gramaj * this -> pret_unitar/100);
}
placinta::placinta(string tip, string umplutura, int gramaj, double pret_unitar):
            produs(tip, gramaj),umplutura(umplutura),pret_unitar(pret_unitar){}
