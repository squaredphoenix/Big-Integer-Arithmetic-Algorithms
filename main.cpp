#include <iostream>
#include "expression-reader.hpp"
using namespace std;

int main()
{
    int count;

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