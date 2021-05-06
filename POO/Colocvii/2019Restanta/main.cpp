#include <iostream>
#include "Abonament.h"
#include "AbonamentVedere.h"
#include "Abonat.h"
#include "Retea.h"
using namespace std;

int main() {
    Retea * R = R->getInstance();
    int var;
    while(1)
    {
        cout << "1.Adaugare abonament\n";
        cout << "2.Adaugare abonat\n";
        cout << "3.Afisare abonati si abonamente\n";
        cout << "4.Efectueaza SMS sau Apel\n";
        cout << "5.Nr apeluri si sms-uri\n";
        cout << "6.Castig\n";
        cout << "7.Inchide\n";
        cin >> var;
        if(var == 1)
        {
            string tip;
            cout << "tip[simplu, auz, vaz]: ";
            cin >> tip;
            R->addAbonament(tip);

        }

        else if(var == 2)
        {
            string tip, nume;
            cout <<"nume:";
            cin >>nume;
            cout << "tip[simplu, auz, vaz]: ";
            cin >> tip;
            R->Register(nume,tip);
        }
        else if(var == 3)
        {
            R->afis();

        }
            else if(var == 4)
        {
        }
            else if(var == 5)
        {
           int destin, rec;
           string tip;
           cout <<"tip";
           cin >> tip;
           cout <<"telefon sursa: ";
           cin >>destin;
           cout <<"telefon destinatar";
           cin >> rec;
           try{
               if(tip =="sms")R->createsms(destin, rec);
               else if(tip == "apel")R->createapel(destin, rec);
               else throw(runtime_error("tip incorect"));

           }
           catch (const exception &ex){cout << ex.what();}
        }

    }
return 0;
}
