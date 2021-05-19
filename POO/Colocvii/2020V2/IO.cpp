//
// Created by User on 19.05.2021.
//

#include "IO.h"
IO::~IO(){};
istream &operator >>(istream& in, IO&obj)
{
    obj.read(in);
    return in;
}
ostream &operator<<(ostream&out, IO& obj)
{
    obj.write(out);
    return out;
}