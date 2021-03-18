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

personal::personal(string nume, int varsta, string post)
{
    this->nume = nume;
    this->varsta = varsta;
    this->post = post;
    this->vechime = 0;
}


string personal::get_nume()
{
    return this->nume;
}
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

ostream& operator<< (ostream &cout, const personal &persoana)
{
    cout << persoana.nume <<" este "<< persoana.post <<" si are o vechime de "<< persoana.vechime <<"\n";
    return cout;
}
istream& operator>> (istream &cin, personal &persoana)
{
    cin >> persoana.nume >> persoana.post;
    return cin;
}


