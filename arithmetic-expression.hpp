#ifndef ARITHMETIC_EXPRESSION_H
#define ARITHMETIC_EXPRESSION_H

#include <iostream>
#include "operand.hpp"
using namespace std;

class ArithmeticExpression
{
    public:
        ArithmeticExpression();
        ArithmeticExpression(string op1, string op2, char operator1);
        string getOp1();
        string getOp2();
        char getOperator();
        void setAll(string op1, string op2, char operator1);

        Operand op1;
        Operand op2;
        Operand op3;
        char operator2;
};

#endif