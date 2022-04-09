#ifndef BIG_INTEGER_ARITHMETIC_H
#define BIG_INTEGER_ARITHMETIC_H

#include <iostream>
#include <sstream>
#include "arithmetic-expression.hpp"
#include "stack.hpp"
#include "operand.hpp"
using namespace std;

class BigIntegerArithmetic
{
    public:
        BigIntegerArithmetic();
        BigIntegerArithmetic(ArithmeticExpression ae);
        int operandComp(string opt1, string opt2);
        void Length();
        void greatLenght();
        void makeStack();
        string getResults();

    private:
        string opt1;
        string opt2;
        char opt3;
        string result;
        int gL;
        int cL;
        int l1;
        int l2;
        int cary;
        string digit;
        int number;
        int number2;
        int num1;
        int num2;
        bool check;
        int borrow;
        int num3;
        int count;
        char char1;
        char char2;
        char char3;
        Stack stack1;
        Stack stack2;
        Stack stack3;
        stringstream word;
};

#endif