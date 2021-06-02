//
// Created by User on 14.04.2021.
//

#include "manager.h"
manager::manager(string nume, int an_nastere, int vechime, int mandat):
personal(nume, an_nastere, vechime), mandat(mandat){}
istream& manager::read(istream& in){

    cout <<"nume\n";
    in>>this->nume;
    cout <<"an_nastere\n";
    in>>this->an_nastere;
    cout <<"vechime\n";
    in>>this->vechime;
    cout <<"mandat\n";
    in>>this->mandat;

    return in;
}

istream& operator>>(istream& in, manager& p){
    p.read(in);
    return in;
}
ostream& manager::print(ostream& out){
    out<<"Nume: "<<this->nume + " " + this->nume<<"\n";
    out<<"an_nastere: "<<this->an_nastere<<"\n";
    out<<"vechime: "<<this->vechime<<"\n";
    out<<"mentor: "<<this->mandat<<"\n";
    out<<"\n";
    return out;
}

ostream& operator<<(ostream& out, manager& p){
    p.print(out);
    return out;
}