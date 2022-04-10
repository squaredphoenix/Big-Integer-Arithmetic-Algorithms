#include <iostream>
#include "expression-reader.hpp"
#include "arithmetic-expression.hpp"
#include "big-integer-arithmetic.hpp"
#include "operand.hpp"
#include "stack.hpp"
using namespace std;

int main()
{
    ExpressionReader er("expressions.txt");

    while(er.readNextExpression())
    {
        cout << er.getResult() << endl;
        cout << "----------" << endl;
    }
}