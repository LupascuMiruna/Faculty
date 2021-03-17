//
// Created by User on 14.03.2021.
//
#include "patiserie.h"
#include <string>
#include <iostream>
using namespace std;


void patiserie::open_shop() {this->state = 1;}
void patisertie::if_open()
{
    if (this->state == 1)
        cout <<"open";
    else
        cout << "close";
}

/*void patiserie::close_shop() {this->state = 0;}


patiserie operator=(const patiserie &p)
{
    nume = p.nume;
    locatie = p.locatie;
    suprafata = p.suprafatata;
    state = p.state;

}

patiserie(string nume, string locatie, int suprafata)
{
    this->nume = nume;
    this->locatie = locatie;
    this->suprafata = suprafata;

}
void patiserie::setare_nume(int x) {this->x = x;}

*/