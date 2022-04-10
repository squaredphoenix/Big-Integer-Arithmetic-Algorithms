#include <iostream>
#include "expression-reader.hpp"
#include "arithmetic-expression.hpp"
#include "big-integer-arithmetic.hpp"
#include "operand.hpp"
#include "stack.hpp"
using namespace std;

int main()
{
    int count = 0;

    ExpressionReader er("expressions.txt");

    while(er.readNextExpression())
    {
        if(count > 3)
        {
            cout << er.getResult() << endl;
            cout << "----------" << endl;
        }

        count++;
    }
}