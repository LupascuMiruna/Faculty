//
// Created by User on 23.04.2021.
//

#ifndef COLOCVIU_DEZINFECTANTBACTERII_H
#define COLOCVIU_DEZINFECTANTBACTERII_H

#include "Dezinfectant.h"
#include <bits/stdc++.h>

class DezinfectantBacterii: virtual public Dezinfectant
{
public:
~DezinfectantBacterii();
DezinfectantBacterii();
DezinfectantBacterii(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise);
DezinfectantBacterii(const DezinfectantBacterii& obj);
DezinfectantBacterii &operator =(const DezinfectantBacterii&  obj);
friend std::istream &operator >>(std::istream &in, DezinfectantBacterii& obj);
friend std::ostream &operator <<(std::ostream &out, const DezinfectantBacterii& obj);


double eficienta()
{
    return double(nr_organisme_ucise)/pow(10,9);
}

};


#endif //COLOCVIU_DEZINFECTANTBACTERII_H
