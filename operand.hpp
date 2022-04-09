#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
using namespace std;

class Operand
{
    public:
        Operand();
        Operand(string num);
        bool isNegative();
        string getValue();
        void setValue(string num);
        void flipSign();

    private:
        string number;
};

#endif