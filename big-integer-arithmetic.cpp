#include <iostream>
#include "big-integer-arithmetic.hpp"
#include "stack.hpp"
using namespace std;

BigIntegerArithmetic::BigIntegerArithmetic()
{
    opt1 = "";
    opt2 = "";
    opt3 = '0';
}

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression ae)
{
    opt1 = ae.getOp1();
    opt2 = ae.getOp2();
    opt3 = ae.getOperator();
}

int BigIntegerArithmetic::operandComp(string newOpt1, string newOpt2)
{
    if(newOpt1.length() > newOpt2.length())
    {
        return 1;
    }

    else if(newOpt1.length() < newOpt2.length())
    {
        return -1;
    }

    else
    {
        int x = newOpt1.compare(newOpt2);

        if(x > 0)
        {
            return 1;
        }

        else if(x < 0)
        {
            return -1;
        }
    }

    return 0;
}

int BigIntegerArithmetic::Length()
{
    l1 = 0;
    l2 = 0;

    l1 = opt1.length();
    l2 = opt2.length();

    if(operandComp(opt1, opt2) == 1)
    {
        return opt1.length();
    }

    else
    {
        return opt2.length();
    }
}

void BigIntegerArithmetic::greatLength()
{
    if(l1 > l2)
    {
        if(l1 > count)
        {
            gL = l1;
        }

        else
        {
            gL = count;
        }
    }

    else
    {
        if(l2 > count)
        {
            gL = l2;
        }

        else
        {
            gL = count;
        }
    }
}

void BigIntegerArithmetic::makeStack()
{
    for(int i = 0; i < l1; i++)
    {
        number = opt1[i] - '0';

        stack1.push(number);

        if(l1 < l2 && i > l1)
        {
            while(i < l2)
            {
                stack2.push(0);
                i++;
            }
        }
    }

    for(int i = 0; i < l2; i++)
    {
        number = opt2[i] - '0';

        stack2.push(number);

        if(l1 > l2 && i >= l2)
        {
            while(i < l1)
            {
                stack2.push(0);
                i++;
            }
        }
    }
}

string BigIntegerArithmetic::getResults()
{
    Length();

    makeStack();

    borrow = 0;

    if(opt3 == '+')
    {
        for(int i = 0; i <= Length(); i++)
        {
            if(!stack1.empty() || !stack2.empty() || check)
            {
                if(!stack1.empty())
                {
                    num1 = stack1.pop();
                }

                else
                {
                    num1 = 0;
                }

                if(!stack2.empty())
                {
                    num2 = stack2.pop();
                }

                else
                {
                    num2 = 0;
                }

                number2 = num1 + num2 + cary;

                check = false;

                if(number2 > 9)
                {
                    digit = to_string(number2);
                    cary = digit[0] - '0';
                    number2 = digit[1] - '0';
                    check = true;
                }

                else
                {
                    cary = 0;
                }

                if(number2 < 0)
                {
                    number2 = number2 * -1;
                }

                stack3.push(number2);
            }
        }
    }

    else
    {
        if(operandComp(opt1, opt2) == -1) // works
        {
            for(int i = 0; i < Length(); i++)
            {
                if(!stack1.empty())
                {
                    num1 = stack1.pop();
                }

                else
                {
                    num1 = 0;
                }

                if(!stack2.empty())
                {
                    num2 = stack2.pop() - borrow;
                }

                else
                {
                    num2 = 0;
                }
                
                if(operandComp(to_string(num1), to_string(num2)) == 1)
                {
                    borrow = 1;
                    num2 = num2 + 10;
                }

                else
                {
                    borrow = 0;
                }

                number2 = num2 - num1;
                
                if(!stack2.empty() || !(num2 == 0))
                {
                    stack3.push(number2);
                }
            }
        }

        else
        {
            for(int i = 0; i < Length(); i++)
            {
                num1 = stack1.pop() - borrow;

                if(!stack2.empty())
                {
                    num2 = stack2.pop();
                }

                else
                {
                    num2 = 0;
                }
                
                if(operandComp(to_string(num1), to_string(num2)) == -1)
                {
                    borrow = 1;
                    num1 = num1 + 10;
                }

                else
                {
                    borrow = 0;
                }

                number2 = num1 - num2;
                
                if(!stack2.empty() || !(num2 == 0))
                {
                    stack3.push(number2);
                }
            }
        }
    }

    count = 0;

    while(!stack3.empty())
    {
        num3 = stack3.pop();

        if(count == 0 && opt3 == '-' && operandComp(opt1, opt2) == -1)
        {
            num3 = num3 * -1;
        }

        count++;

        result += to_string(num3); 
    }

    greatLength();

    word << setfill(' ') << setw(gL + 1) << opt1 << '\n' << setfill(' ') << setw(1) << opt3 << setfill(' ') << setw(gL) <<  opt2 << '\n' << setfill(' ') << setw(gL + 1) << result;

    return word.str();
}

