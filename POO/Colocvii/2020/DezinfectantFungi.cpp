//
// Created by User on 23.04.2021.
//

#include "DezinfectantFungi.h"
DezinfectantFungi::DezinfectantFungi() {}
DezinfectantFungi::~DezinfectantFungi(){}
DezinfectantFungi::DezinfectantFungi(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise):
        Dezinfectant(suprafete, ingrediente,nr_organisme_ucise){}
DezinfectantFungi::DezinfectantFungi(const DezinfectantFungi& obj):Dezinfectant(obj){}
DezinfectantFungi  &DezinfectantFungi::operator =(const DezinfectantFungi&  obj)
{
    this->ingrediente = obj.ingrediente;
    this->suprafete = obj.suprafete;
    this->nr_organisme_ucise = nr_organisme_ucise;

    return *this;
}
std::istream &operator >>(std::istream &in, DezinfectantFungi &obj)
{
    int i, n;
    std:: string x;
    std::cout << "Introduceti nr_organisme_ucise: ";
    in >> obj.nr_organisme_ucise;
    std::cout << "Introduceti nr_ingrediente";
    in >> n;
    for(i = 1; i <= n; ++i)
    {
        std::cout << "Introduceti ingrediente: ";
        std::cin.get();
        getline(std::cin, x);

        obj.ingrediente.push_back(x);
    }
    std::cout << "Introduceti nr_suprafete";
    in >> n;
    for(i = 1; i <= n; ++i)
    {
        std::cout << "Introduceti suprafete: ";
        std::cin.get();
        getline(std::cin, x);
        obj.suprafete.push_back(x);
    }
    return in;
}
std::ostream& operator << (std::ostream &out, const DezinfectantFungi &obj)
{
    out<<"nr_organisme_ucise= "<<obj.nr_organisme_ucise<<", ";
    for(int i=0; i< obj.ingrediente.size(); i++)
    {
        out<<obj.ingrediente[i]<<", ";
    }
    for(int i=0; i< obj.suprafete.size(); i++)
    {
        out<<obj.suprafete[i]<<", ";
    }
    return out;
}