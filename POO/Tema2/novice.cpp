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