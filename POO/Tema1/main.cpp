#include <iostream>
#include "patiserie.h"
#include "produs.h"
#include <fstream>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    cout << "Hello, World!" << std::endl;
    patiserie p1("Luca", "Tineretului", 1500);
    produs produs1("savarina", 150);
    produs produs2("ecler", 200);
    p1.adauga_produs(produs1);
    p1.adauga_produs(produs2);
    produs produs3;
    produs3 = produs1;

    p1.adauga_produs(produs3);
    cout << p1;

    //p1.afiseaza_produse();
//    p1.if_open();
//    p1.close_shop();
//    p1.if_open();
//    patiserie p2;
//    fin >> p2;
//    cout << p2.get_suprafata();
//    fout << p1;
    //p1.open_shop();
    //p1.if_open();

    //produs1.modifica_gramaj(50);
    //cout << produs1.get_gramaj() <<"\n";
    return 0;



}
