#include <iostream>
#include "patiserie.h"
#include "produs.h"
#include <fstream>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
//    cout << "Hello, World!" << std::endl;
//    int i, nr_prod_adaugat;
    patiserie p1;
    p1.set_nume("Leon");
    p1.set_locatie("Unirii");
    ///adauga lista de produse
//    produs prod;
//    cout <<"Nr de produse de adaugat:";
//    cin >> nr_prod_adaugat;
//    for(i = 0; i < nr_prod_adaugat; ++i)
//    {
//        cout <<" nume produs de adaugat:";
//        cin >> prod;
//        p1.adauga_produs(prod);
//    }
//    p1.afiseaza_produse();
/////////adauga personal

//    patiserie p2("Luca", "Tineretului", 1500);
//    personal manager2("Bob", 27, "manager");
//    p2.adauga_personal(manager2);
//
//    personal bucatar2;
//    bucatar2.set_vechime(3);
//    bucatar2.set_nume("Victor");
//    bucatar2.set_post("bucatar");
//
//    p2.adauga_personal(bucatar2);
//    p2.afiseaza_personal();
//
///modifica produs
        produs ecler("ecler", 150);
        ecler.modifica_gramaj(50);
        ecler.set_pret(10);
        ecler.set_reducere(10);
        ecler.aplica_reducere();
        cout << ecler.get_pret()<<"\n";
///multiplica o patiserie inchide/deschide
    patiserie p3(p1);
    p3.if_open();
    p3.close_shop();
    p3.if_open();
    p1.if_open();


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
