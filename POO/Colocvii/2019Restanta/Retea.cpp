//
// Created by User on 06.05.2021.
//

#include "Retea.h"
#include "Abonat.h"
#include "Abonament.h"
#include "AbonamentVedere.h"
#include<iostream>
#include<string>
using  namespace std;

Retea*  Retea::instance = nullptr;
void Retea::addAbonament(string abonament)
{
    Abonament *a = nullptr;
    if(abonament == "simplu") a = new Abonament();
    if(abonament == "vaz") a = new AbonamentVedere();
    //if(abonament == 'auz') a = new AbonamentAuz;
    cin >>(*a);
    abonamente.push_back(a);
}
void Retea::Register(string nume, string abonament)
{
    Abonat *a = new Abonat(nume, abonament);
    abonati.push_back(a);
}
void Retea::afis()
{
    int i, j;
    for(i = 0; i < abonamente.size(); ++i)
        if(dynamic_cast<Abonament*>(abonamente[i]))
        {
            cout <<"tip: simplu\n";
            cout <<(*abonamente[i]);
            cout <<"abonati:\n";
            for(j = 0; j < abonati.size(); ++j)
                if(abonati[i]->getabonament() == "simplu")
                cout <<(*abonati[i]) << " ";

        }
    for(i = 0; i < abonamente.size(); ++i)
        if(dynamic_cast<Abonament*>(abonamente[i]))
        {
            cout <<"tip: auz\n";
            cout <<(*abonamente[i]);
            cout <<"abonati:\n";
            for(j = 0; j < abonati.size(); ++j)
                if(abonati[i]->getabonament() == "auz")
            cout <<(*abonati[i]) << " ";

        }
    for(i = 0; i < abonamente.size(); ++i)
        if(dynamic_cast<Abonament*>(abonamente[i]))
        {
            cout <<"tip: vaz\n";
            cout <<(*abonamente[i]);
            cout <<"abonati:\n";
            for(j = 0; j < abonati.size(); ++j)
                if(abonati[i]->getabonament() == "vaz")
            cout <<(*abonati[i]) << " ";

        }
}

void Retea::createapel(int destin, int rec)
{
    int j;
    for(j = 0; j < abonati.size(); ++j)
        if(abonati[j]->gettel() == destin);

}

void Retea::createsms(int destin, int rec)
{
    int j;
    for(j = 0; j < abonati.size(); ++j)
        if(abonati[j]->gettel() == destin);

}