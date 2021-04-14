//
// Created by User on 17.03.2021.
//

#include <iostream>
#include<string>
#include "personal.h"
using namespace std;
///constructori
personal::personal()
{ this->vechime = 0;
}
personal::personal(string nume, int an_nastere, int vechime = 0)
{
    this->nume = nume;
    this->an_nastere = an_nastere;
    this->vechime = vechime;

}
///copy constructor --- chiar daca nu l folosim
personal::personal(const personal& pers)
{
    this->nume = pers.nume;
    this->an_nastere = pers.an_nastere;
    this->vechime = vechime;
}



///destructori
personal::~personal()
{
    ///cout << "persoana "<< this->nume <<" a fost concediata";

}
///operator =
personal &personal::operator=(const personal& pers)
{
    this->nume = nume;
    this->an_nastere = an_nastere;
    this->vechime = vechime;
    return *this;
}

///getteri
string personal::get_nume()
{
    return this->nume;
}
int personal::get_vechime()
{
    return this->vechime;
}

///setteri

void personal::set_nume(string new_nume)
{
    this->nume = new_nume;
}

ostream& operator<< (ostream &out, const personal &persoana)
{
    out << persoana.nume <<" este nascuta in anul"<< persoana.an_nastere <<"\n";
    return out;
}
istream& operator>> (istream &in, personal &persoana)
{
    in >> persoana.nume >> persoana.an_nastere;
    return in;
}
///functie pentru salariu
void personal::print_salariu() {
    cout<<"salriul nu a fost stabilit";
}
