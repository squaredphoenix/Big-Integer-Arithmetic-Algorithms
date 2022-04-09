#ifndef EXPRESSION_READER_H
#define EXPRESSION_READER_H

#include <iostream>
#include <fstream>
#include "big-integer-arithmetic.hpp"
#include "arithmetic-expression.hpp"
#include "operand.hpp"
using namespace std;

class ExpressionReader
{
    public:
        ExpressionReader(string er);
        bool readNextExpression();
        string getResult();

    private:
        string er;
        ArithmeticExpression ae;
        BigIntegerArithmetic bia;
        ifstream iFile;
        string num1;
        string num2;
        char char1;
        string line;
        int count;
};

#endif