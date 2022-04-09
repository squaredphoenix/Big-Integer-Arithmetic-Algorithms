#include <iostream>
#include "operand.hpp"
using namespace std;

Operand::Operand()
{
    number = "";
}

Operand::Operand(string num)
{
    setValue(num);
}

bool Operand::isNegative()
{
    return number[0] == '-';
}

string Operand::getValue()
{
    if(number[0] == '+' && number.length() > 1)
    {
        number.erase(0, 1);
    }

    return number;
}

void Operand::setValue(string num)
{
    number = num;
}

void Operand::flipSign()
{
    if(number[0] == '-')
    {
        string n1 = "+";

        number.replace(0, 1, n1);
    }

    else if(number[0] == '+')
    {
        string n1 = "-";

        number.replace(0, 1, n1);
    }
}