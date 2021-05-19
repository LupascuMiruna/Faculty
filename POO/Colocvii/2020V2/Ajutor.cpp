//
// Created by User on 19.05.2021.
//

#include "Ajutor.h"
unsigned int Ajutor::alege(istream& in, string ob, vector<string> optiuni)
{
    string optiune = "";
    bool first = false;
    bool cond = false;
    unsigned int result;
    do
    {
        if(first)
        {
            cout << "optiune invalida" << endl;
            cout << "optiuni valide:" << endl;
            for(int i = 0; i < optiuni.size(); ++i)
                cout << optiuni[i] << endl;
        }
        cout << "alegeti tipul de " << ob << ":" << endl;
        in >> optiune;
        first = true;
        for(unsigned int i = 0; i < optiuni.size(); i++)
            if(equal(optiune.begin(), optiune.end(), optiuni[i].begin(), optiuni[i].end(),
                     [](char a, char b){
                         return toupper(a) == toupper(b);

                     }
            ))
            {
                cond = true;
                result = i;
            }
    }while(cond == false);

    return result;
}
