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
            ///destructori
            ~personal();
            ///copy constructor
            personal(const personal& pers);
            ///operator =
            personal &operator=(const personal &personal);

            ///setteri, getteri
            string get_nume();
            string get_post();
            int get_vechime();
            void set_nume(string new_nume);
            void set_post(string new_post);
            void set_vechime(int new_vechime);

            ///supraincarcare operatori
            friend ostream &operator<<(ostream &out, const personal &persoana);
            friend istream &operator>>(istream &in, personal &persoana);

            void schimba_post(string new_post);
            void adauga_vechime();

        };



#endif //INCERCARE1_PERSONAL_H
