//
// Created by User on 23.04.2021.
//

#ifndef COLOCVIU_DEZINFECTANTVIRUSURI_H
#define COLOCVIU_DEZINFECTANTVIRUSURI_H
#include<bits/stdc++.h>
#include "Dezinfectant.h"
class DezinfectantVirusuri: virtual public Dezinfectant
{
public:
    ~DezinfectantVirusuri();
    DezinfectantVirusuri();
    DezinfectantVirusuri(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise);
    DezinfectantVirusuri(const DezinfectantVirusuri& obj);
    DezinfectantVirusuri &operator =(const DezinfectantVirusuri&  obj);
    friend std::istream &operator >> (std::istream &in, DezinfectantVirusuri& obj);
    friend std::ostream &operator <<(std::ostream &out, const DezinfectantVirusuri& obj);

    double eficienta()
    {
        return double(nr_organisme_ucise)/pow(10,8);
    }


};

#endif //COLOCVIU_DEZINFECTANTVIRUSURI_H
