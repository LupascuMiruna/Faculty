#include <iostream>
#include <fstream>
#include <memory>

#include "patiserie.h"
#include "produs.h"
#include "personal.h"
#include "placinta.h"
#include  "novice.h"
#include "experimentat.h"
#include "reprezentant.h"
#include "manager.h"
#include "gramaj_exception.h"
#include "pret_exception.h"
#include "tip_exception.h"

///reprezentat: manager+experimentat
///personal: experimenta sau novice
///persoanl: manager sau....

using namespace std;





int main()

{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
/// TEMA 1
//TIP INPUT:
//    Luca
//    Tineretului
//    3000
//    savarina
//    200
//    Adelina
//    casier


//    ///adauga lista de produse l o patiserie
//    patiserie P1;
//    fin >> P1;
//    produs p1, p3;
//    fin>>p1;
//    p1.set_pret(7);
//    p1.set_reducere(10);
//    produs p2(p1);
//    p3.set_tip("cozonac");
//    p3.set_gramaj(1000);
//    p3.set_reducere(0);
//    p3.set_pret(70);
//
//    ///modifica produs
//    produs ecler("ecler", 150);
//    ecler.modifica_gramaj(50);
//    ecler.set_pret(10);
//    ecler.set_reducere(15);
//    ecler.aplica_reducere();
//
//
//    P1.adauga_produs(p1);
//    P1.adauga_produs(p2);
//    P1.adauga_produs(p3);
//    P1.adauga_produs(ecler);
//
//    P1.afiseaza_produse();
//    cout << "\n";
//
//    ///afisare caracteristici produs
//    cout <<"produsul " <<ecler.get_tip()<< " are un gramaj de " <<ecler.get_gramaj() <<" si costa "<< ecler.get_pret()<<"\n";
//
//    ///adauga personal
//    patiserie P2;
//    P2.set_nume("Leon");
//    P2.set_locatie("Unirii");
//
//    personal casier;
//    fin >> casier;
//    P2.adauga_personal(casier);
//
//    personal manager2("Bob", 27, "manager");
//    P2.adauga_personal(manager2);
//
//    personal bucatar2;
//    bucatar2.set_vechime(3);
//    bucatar2.set_nume("Victor");
//    bucatar2.set_post("bucatar");
//    bucatar2.schimba_post("chelner");
//    P2.adauga_personal(bucatar2);
//    P2.afiseaza_personal();
//    cout <<"\n";

//
///////multiplica o patiserie inchide/deschide
//    patiserie P3(P1);
//    P3.if_open();
//    P3.close_shop();
//    P3.if_open();
////SFARSIT TEMA 1

////TEMA 2
    ///MOSTENIRE DIAMANT
    reprezentant reprez1("Bob",1996, 2,"contabilitate",3,"national");
    cout << "Angajatul " << reprez1.get_nume() <<" are salariul de ";
    reprez1.print_salariu();
    cout << "\n";


    ///SMART POINTERS
    shared_ptr<placinta> pmere = make_shared<placinta>("dulce", "mere", 100, 2);
    ////FUNCTIE VIRTUALA PENTRU MODIFICARE PRET
    pmere->set_pret(1);
    cout <<"Produsul costa " << pmere->get_pret() << "\n";


    ///VECTORI DE SMART POINTERS
    vector<shared_ptr<patiserie>> vecpatiserie;
    vecpatiserie.emplace_back(make_shared<patiserie>("Dulcelind","Iasi",3000));
    vecpatiserie.emplace_back(make_shared<patiserie>("Dulcelind","Vaslui",2000));



    placinta pbranza("dulce", "branza", 200, 3);
    ///EXCEPTIE PENTRU GRAMAJ / pret /tip
    try
    {
        int new_gramaj, new_pret;
        string new_tip;

        fin >> new_tip;
        fin >> new_gramaj;
        fin >> new_pret;

        pbranza.modifica_produs(new_gramaj, new_pret, new_tip);

    }
    catch(tip_exception& e)
    {
        cout << e.what() << endl;
    }
    catch(pret_exception& e)
    {
        cout << e.what() << endl;
    }

    catch(gramaj_exception& e)
    {
        cout << e.what() << endl;

    }

    cout << pbranza.get_tip() << " " << pbranza.get_pret() << " " << pbranza.get_gramaj();






    return 0;



}
