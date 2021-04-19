//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PERSONAL_H
#define INCERCARE1_PERSONAL_H


#include<iostream>

using namespace std;

class personal
        {
        protected:
            std::string nume;
            int an_nastere;
            int vechime;
            //int salariu;

        public:
            ///constructori
            personal();
            personal(std::string nume, int an_nastere, int vechime);
            ///destructor virtual
            virtual ~personal();
            ///copy constructor
            personal(const personal& pers);
            ///operator =
            personal &operator=(const personal &personal);

            ///setteri, getteri
            string get_nume();
            int get_vechime();
            void set_nume(std::string new_nume);
            void set_an_nastere(int new_an_nastere);
            void adauga_vechime();

            ///functie pentru salariu
            void print_salariu();


            ///supraincarcare operatori
            friend ostream &operator<<(std::ostream &out, const personal &persoana);
            friend istream &operator>>(std::istream &in, personal &persoana);


        };



#endif //INCERCARE1_PERSONAL_H
