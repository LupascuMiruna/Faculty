//
// Created by User on 19.05.2021.
//
#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

#ifndef INC_2020V2_IO_H
#define INC_2020V2_IO_H

class IO
        {
        public:
            virtual ~IO();
            friend istream& operator>>(istream& in, IO&ob);
            friend ostream& operator<<(ostream& out, IO&ob);

            virtual void read(istream&) = 0;
            virtual void write(ostream&)const = 0;
        };

#endif //INC_2020V2_IO_H
