#include <iostream>
#include "Arithmetic-Expression.hpp"
using namespace std;

ArithmeticExpression::ArithmeticExpression()
{
    op1.setValue("");
    op2.setValue("");
    op3.setValue("");
}

ArithmeticExpression::ArithmeticExpression(string op1, string op2, char operator1)
{
    setAll(op1, op2, operator1);
}

string ArithmeticExpression::getOp1()
{
    return op1.getValue();
}

string ArithmeticExpression::getOp2()
{
    return op2.getValue();
}

char ArithmeticExpression::getOperator()
{
    operator2 = (op3.getValue())[0];

    return operator2;
}

void ArithmeticExpression::setAll(string newOp1, string newOp2, char newOperator1)
{
    string newOperator(1,newOperator1);

    op1.setValue(newOp1);
    op2.setValue(newOp2);
    op3.setValue(newOperator);

    if(op2.isNegative())
    {
        op2.flipSign();
        op3.flipSign();
    }
}