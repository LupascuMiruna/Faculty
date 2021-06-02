//
// Created by User on 14.04.2021.
//
#include<string>
#include "novice.h"
using namespace std;
void novice::print_salariu()const {
    cout << vechime * 100;
}
novice::novice(string nume, int an_nastere, int vechime, string mentor):
        personal(nume, an_nastere,vechime),mentor(mentor) {}
istream& novice::read(istream& in){

    cout <<"nume\n";
    in>>this->nume;
    cout <<"an_nastere\n";
    in>>this->an_nastere;
    cout <<"vechime\n";
    in>>this->vechime;
    cout <<"mentor\n";
    in>>this->mentor;

    return in;
}

istream& operator>>(istream& in, novice& p){
    p.read(in);
    return in;
}
ostream& novice::print(ostream& out){
    out<<"Nume: "<<this->nume + " " + this->nume<<"\n";
    out<<"an_nastere: "<<this->an_nastere<<"\n";
    out<<"vechime: "<<this->vechime<<"\n";
    out<<"mentor: "<<this->mentor<<"\n";
    out<<"\n";
    return out;
}

ostream& operator<<(ostream& out, novice& p){
    p.print(out);
    return out;
}