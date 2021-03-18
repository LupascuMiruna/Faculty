//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PERSONAL_H
#define INCERCARE1_PERSONAL_H


#include<iostream>

using namespace std;

class personal
        {
            string nume;
            int varsta;
            string post;//manager, contabil, bucatar, casier
            int vechime;

        public:
            ///constructori
            personal();
            personal(string nume, int varsta, string post);

            ///setteri, getteri
            string get_nume();
            void set_nume(string new_nume);
            void set_post(string new_post);
            void set_vechime(int new_vechime);

            ///supraincarcare operatori
            friend ostream &operator<<(ostream &cout, const personal &persoana);
            friend istream &operator>>(istream &cin, personal &persoana);

        };



#endif //INCERCARE1_PERSONAL_H
