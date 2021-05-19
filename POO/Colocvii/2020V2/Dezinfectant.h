//
// Created by User on 19.05.2021.
//

#ifndef INC_2020V2_DEZINFECTANT_H
#define INC_2020V2_DEZINFECTANT_H
class Dezinfectant{
    vector<string> ingrediente;
    vector<string> suprafete;
    long long nr_specii;
    long long nr_total_specii;

public:

    Dezinfectant(long, long, vector<string>, vector<string>);
    Dezinfectant(const Dezinfectant&) = default;
    Dezinfectant& operator=(const Dezinfectant&) = default;

    double eficienta();
};

#endif //INC_2020V2_DEZINFECTANT_H
