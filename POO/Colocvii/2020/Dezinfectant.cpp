//
// Created by User on 22.04.2021.
//
using namespace std;
#include "Dezinfectant.h"
Dezinfectant::Dezinfectant() {}
Dezinfectant::~Dezinfectant(){}
Dezinfectant::Dezinfectant(std::vector<std::string>suprafete, std::vector<std::string>ingrediente,int nr_organisme_ucise):
suprafete(suprafete), ingrediente(ingrediente), nr_organisme_ucise(nr_organisme_ucise){}
Dezinfectant::Dezinfectant(const Dezinfectant& obj):
suprafete(obj.suprafete), ingrediente(obj.ingrediente),nr_organisme_ucise(obj.nr_organisme_ucise){}
Dezinfectant  &Dezinfectant::operator =(const Dezinfectant&  obj)
{
    this->ingrediente = obj.ingrediente;
    this->suprafete = obj.suprafete;
    this->nr_organisme_ucise = nr_organisme_ucise;

    return *this;
}
std::istream &operator >>(std::istream &in, Dezinfectant &obj)
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
std::ostream& operator << (std::ostream &out, const Dezinfectant &obj)
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

std::vector<std::string> Dezinfectant::get_ingrediente() const
{
    return ingrediente;
}
std::vector<std::string> Dezinfectant::get_suprafete() const
{
    return suprafete;
}
int Dezinfectant::get_nr_oganisme_ucise() const
{
    return nr_organisme_ucise;
}

void Dezinfectant::set_ingrediente(std::string& x)////////////////////////////////////////////////////////
{
    ingrediente.emplace_back(x);
}
void Dezinfectant::set_suprafete(std::string& x)
{
    suprafete.emplace_back(x);
}