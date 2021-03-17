//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PATISERIE_H
#define INCERCARE1_PATISERIE_H

#include <string>
#include <iostream>
#include <vector>
#include "produs.h"
using namespace std;



class patiserie
    {

        string nume;
        string locatie;
        int suprafata;
        bool state; //daca e deschis sau nu, initial deschise toate
        vector <produs> produse;
        //produs prod1;/////////////

        //personal pers;


        public:
        //constructor
        patiserie(){}
        patiserie(string nume, string locatie, int suprafata)
        {
            this->nume = nume;
            this->locatie = locatie;
            this->suprafata = suprafata;
        }
        //destructor
        ~patiserie(){}

        //constructor de copiere
        patiserie(const patiserie &p);

        //operator =
        patiserie operator=(const patiserie &p)
        {
            nume = p.nume;
            locatie = p.locatie;
            suprafata = p.suprafata;
            state = p.state;
            produse = p.produse;

            return *this;
        }

        void open_shop()
        {this->state = 1;}

        void close_shop()
        {this->state = 0;}


        void if_open()
        {
            if (this->state == 1)
                cout <<"open";
            else
                cout << "close";
        }

        void adauga_produs(string prod)
        {
            this->produs.push_back(prod);

        }
        void afiseaza_produse()
        {
            int i;
            for(i = 0; i < this->produse.size(); ++i)
                cout << this->produse[i] <<", "

        }
        void get_suprafata()
        {
            return this->suprafata;
        }
        ///supraincarcarea >> declarat mai jos
        friend istream &operator>>(istream &fin, patiserie &P);
        friend ostream &operator<<(ostream &fout,const patiserie &P);

    };

    istream &operator >>(istream &fin, patiserie &P)
    {
        fin >> P.nume >> P.locatie >> P.suprafata;

    }
    ostream &operator<<(ostream &fout,const patiserie &P)
    {
        fout <<"Patiseria: "<< P.nume <<"\n" <<" din "<<P.locatie <<" are urmatoarele produse: ";
        for(int i = 0; i < P.produse.size(); i++)
            fout <<P.produse[i] <<" ";

    }


#endif //INCERCARE1_PATISERIE_H
