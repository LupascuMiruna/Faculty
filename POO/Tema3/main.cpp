#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <functional>
#include <string>
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
ifstream fin("input.txt");
ofstream fout("output.txt");


class regular_anunt
{
public:
    virtual ~regular_anunt()
    {
    }
    virtual void afiseaza()
    {
        cout << "Am deschis!" << endl;
    }
};
class fancy_anunt : public regular_anunt
{
public:
    void afiseaza() override
    {
        cout << "Am deschis si avem reduceri!" << endl;
    }
};
class random_anunt : public regular_anunt
{
public:
    void afiseaza() override
    {
        cout << "Nu stim cat vom mai tine deschis" << endl;
    }
};

class anunt_factory
//
{
public:
    enum anunt_types // avem un enum
    { // pentru tipurile
        regular_anunt_type, // claselor
        fancy_anunt_type, // pentru a ne
        random_anunt_type // usura treaba
    };
    static regular_anunt* create_anunt(anunt_types anunt_type)


    {
        if (anunt_type == anunt_types::regular_anunt_type)
            return new regular_anunt();
        else if (anunt_type == anunt_types::fancy_anunt_type)
            return new fancy_anunt();
        else if (anunt_type == anunt_types::random_anunt_type)
            return new random_anunt();
        return nullptr;
    }
};
////////////////////

///meniu singleton
class Menu
{

private:
    static Menu* ptr;
    vector<pair< string, function<void()>>> op;
    Menu();
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
public:
    void run();
    static Menu* get_ptr();
    static void delete_ptr();
};
Menu* Menu::ptr = nullptr;

Menu::Menu()
{
    op.push_back(make_pair("Tema 1",[&]()
    {

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


//
///////multiplica o patiserie inchide/deschide
//    patiserie P3(P1);
//    P3.if_open();
//    P3.close_shop();
//    P3.if_open();
////SFARSIT TEMA 1


    }));
    op.push_back(make_pair("Tema 2", [&]()
    {
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
        cout <<"\n";


//    ///adauga personal
    patiserie P2;
    P2.set_nume("Leon");
    P2.set_locatie("Unirii");

        P2.adauga_personal();

//    novice novice1("Bob", 1987, 20, "mentooor");
//
//    P2.adauga_personal(&novice1);
//
//        manager manager1;
//        fin >> manager1;
//        P2.adauga_personal(&manager1);
//



    P2.afiseaza_personal();
    cout <<"\n";


    }));
    op.push_back(make_pair("Tema 3 -- Factory", [&]()
    {
        int type = 0;
        cout << "0) pentru regular_anunt\n";
        cout << "1) pentru fancy_anunt\n";
        cout << "2) pentru rendom_anunt\n";
        cout << "Introduceti tipul:";
        cin >> type;
        if (type > 2 || type < 0)
            return -1;
        regular_anunt* anunt = anunt_factory::create_anunt((anunt_factory::anunt_types)type);
        anunt->afiseaza();
        delete anunt;
        anunt = nullptr;
    }));
}
void Menu::run()
{
    bool running = true;

    while (running)
    {
        try
        {
            int operatie;
            cout << "Operatia:" << endl;
            for (int i = 0; i < op.size(); i++)
                cout << i << op[i].first <<"\n";
            cout << op.size() << " Inchidere" <<"\n";
            cin >> operatie;
            if (operatie < 0 || operatie > op.size())
                throw runtime_error("Optiune gresita");

            if (operatie == op.size())
            {
                running = false;
                continue;
            }
            op[operatie].second();
        }
        catch(const exception& e)
        {
            cout << "Problema: " << e.what() <<"\n";
        }

    }
}
Menu* Menu::get_ptr() {
    if(!ptr)
        ptr = new Menu();
    return ptr;
}

void Menu::delete_ptr()
{
    delete ptr;
    ptr = nullptr;
}


int main() {


    Menu::get_ptr()->run();
    Menu::delete_ptr();
    return 0;
}



