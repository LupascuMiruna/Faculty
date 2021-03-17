//
// Created by User on 14.03.2021.
//

#ifndef INCERCARE1_PERSONAL_H
#define INCERCARE1_PERSONAL_H

#include<string>
#include<iostream>

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
            void set_post(string new_post);
            void set_vechime(int new_vechime);

            ///supraincarcare operatori
            friend ostream &operator<<(ostream &cout, const personal &persoana);
            friend istream &operator>>(istream &cin, personal &persoana);



        };

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


#endif //INCERCARE1_PERSONAL_H
