#include <iostream>
#include "expression-reader.hpp"
using namespace std;

ExpressionReader::ExpressionReader(string newEr)
{
    iFile.open(newEr);
}

bool ExpressionReader::readNextExpression()
{
    iFile >> num1;

    if(!iFile.eof())
    {
        iFile >> char1; 
        iFile >> num2;

        ae = ArithmeticExpression(num1, num2, char1);
        bia = BigIntegerArithmetic(ae);

        return true;
    }

    else
    {
        iFile.close();
        return false;
    }

    return false;
}

string ExpressionReader::getResult()
{
    return bia.getResults();
}