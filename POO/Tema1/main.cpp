#include <iostream>
#include <fstream>
#include "patiserie.h"
#include "produs.h"


using namespace std;

int main()

{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ///adauga lista de produse l o patiserie
    patiserie P1;
    fin >> P1;
    produs p1, p3;
    fin>>p1;
    p1.set_pret(7);
    p1.set_reducere(10);
    produs p2(p1);
    p3.set_tip("cozonac");
    p3.set_gramaj(1000);
    p3.set_reducere(0);
    p3.set_pret(70);

    ///modifica produs
    produs ecler("ecler", 150);
    ecler.modifica_gramaj(50);
    ecler.set_pret(10);
    ecler.set_reducere(15);
    ecler.aplica_reducere();


    P1.adauga_produs(p1);
    P1.adauga_produs(p2);
    P1.adauga_produs(p3);
    P1.adauga_produs(ecler);

    P1.afiseaza_produse();
    cout << "\n";

    ///afisare caracteristici produs
    cout <<"produsul " <<ecler.get_tip()<< " are un gramaj de " <<ecler.get_gramaj() <<" si costa "<< ecler.get_pret()<<"\n";

    ///adauga personal
    patiserie P2;
    P2.set_nume("Leon");
    P2.set_locatie("Unirii");

    personal casier;
    fin >> casier;
    P2.adauga_personal(casier);

    personal manager2("Bob", 27, "manager");
    P2.adauga_personal(manager2);

    personal bucatar2;
    bucatar2.set_vechime(3);
    bucatar2.set_nume("Victor");
    bucatar2.set_post("bucatar");
    bucatar2.schimba_post("chelner");
    P2.adauga_personal(bucatar2);
    P2.afiseaza_personal();
    cout <<"\n";


/////multiplica o patiserie inchide/deschide
    patiserie P3(P1);
    P3.if_open();
    P3.close_shop();
    P3.if_open();





//    patiserie p1("Luca", "Tineretului", 1500);
//    produs produs1("savarina", 150);
//    produs produs2("ecler", 200);
//    p1.adauga_produs(produs1);
//    p1.adauga_produs(produs2);
//    produs produs3;
//    produs3 = produs1;
//
//    p1.adauga_produs(produs3);
//    cout << p1;

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
