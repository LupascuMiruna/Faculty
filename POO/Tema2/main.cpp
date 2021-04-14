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

///reprezentat: manager+experimentat
///personal: experimenta sau novice
///persoanl: manager sau....

using namespace std;

class gramaj_exception: public exception {
public:
    const char* what() const noexcept override ///suprascriem functia care returneaza mesajul exceptiei
    {
        return "Gramajul este necorespunzator!!!!";
    }
};


int main()

{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

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



    ///MOSTENIRE DIAMANT
    reprezentant p1("a",2, 2,"d",3,"intern");
    p1.print_salariu();
    cout << "\n";
    cout << p1.get_nume() << "\n";

    ///SMART POINTERS
    shared_ptr<placinta> pmere(new placinta("dulce", "mere", 100, 2));
    ////FUNCTIE VIRTUALA PENTRU MODIFICARE PRET
    pmere->set_pret(1);
    cout << pmere->get_pret() << "\n";

    placinta pbranza("dulce", "branza", 200, 3);
    ///EXCEPTIE PENTRU GRAMAJ
    try
    {
        int new_gramaj;
        fin >> new_gramaj;
        if(new_gramaj > 500 || new_gramaj < 100)
            throw gramaj_exception();
        pbranza.modifica_gramaj(new_gramaj);
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }





    return 0;



}
