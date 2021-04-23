//
// Created by User on 23.04.2021.
//

#ifndef COLOCVIU_DEZINFECTANTFUNGI_H
#define COLOCVIU_DEZINFECTANTFUNGI_H
#include "Dezinfectant.h"
class DezinfectantFungi: virtual public Dezinfectant
{
public:
    ~DezinfectantFungi();
    DezinfectantFungi();
    DezinfectantFungi(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise);
    DezinfectantFungi(const DezinfectantFungi& obj);
    DezinfectantFungi &operator =(const DezinfectantFungi&  obj);
    friend std::istream &operator >> (std::istream &in, DezinfectantFungi& obj);
    friend std::ostream &operator <<(std::ostream &out, const DezinfectantFungi& obj);

    double eficienta()
    {
        return double(nr_organisme_ucise)/(1,5 * pow(10,6));
    }
};
#endif //COLOCVIU_DEZINFECTANTFUNGI_H
