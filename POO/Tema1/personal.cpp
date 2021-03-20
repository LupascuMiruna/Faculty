//
// Created by User on 17.03.2021.
//

#include <iostream>
#include "personal.h"
using namespace std;
///constructori
personal::personal()
{
    this->vechime = 0;
}

///copy constructor --- chiar daca nu l folosim
personal::personal(const personal& pers)
{
    this->nume = pers.nume;
    this->varsta = pers.varsta;
    this->post = pers.post;
    this->vechime = pers.vechime;
}

personal::personal(string nume, int varsta, string post)
{
    this->nume = nume;
    this->varsta = varsta;
    this->post = post;
    this->vechime = 0;
}

///destructori
personal::~personal()
{
    ///cout << "persoana "<< this->nume <<" a fost concediata";

}
///operator =
personal &personal::operator=(const personal& pers)
{
    this->nume = pers.nume;
    this->varsta = pers.varsta;
    this->post = pers.post;
    this->vechime = pers.vechime;
    return *this;
}

///getteri
string personal::get_nume()
{
    return this->nume;
}
string personal::get_post()
{
    return this->post;
}
int personal::get_vechime()
{
    return this->vechime;
}

//setteri
void personal::set_post(string new_post)
{
    this->post = new_post;
}
void personal::set_vechime(int new_vechime)
{
    this->vechime = new_vechime;
}

void personal::set_nume(string new_nume)
{
    this->nume = new_nume;
}

ostream& operator<< (ostream &out, const personal &persoana)
{
    out << persoana.nume <<" este "<< persoana.post <<" si are o vechime de "<< persoana.vechime <<"\n";
    return out;
}
istream& operator>> (istream &in, personal &persoana)
{
    in >> persoana.nume >> persoana.post;
    return in;
}

void personal::schimba_post(string new_post)
{
    this->post = new_post;
}
void personal::adauga_vechime()
{
    this->vechime = this->vechime + 1;
}