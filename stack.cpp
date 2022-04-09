#include <iostream>
#include "stack.hpp"
using namespace std;

Node::Node(int newValue)
{
    value = newValue;
    next = nullptr;
}

void Node::setNext(Node* newNext)
{
    if(newNext == nullptr)
    {
        next = nullptr;
    }

    else
    {
        next = newNext;
    }
}

int Node::getValue() const
{
    return value;
}

Node* Node::getNext()
{
    return next;
}


Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    Node* next;

    while(top != NULL)
    {
        next = top->next;
        delete top;
        top = next;
    }
}

int Stack::pop()
{
    if(empty())
    {
        return -1;
    }

    else
    {
        int tempValue = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return tempValue;
    }
}

int Stack::peek()
{
    if(!empty())
    {
        return top->value;
    }

    else
    {
        return 0;
    }
}

void Stack::push(int num)
{
    Node* n = new Node(num);

    if(empty())
    {
        top = n;
    }

    else
    {
        n->next = top;
        top = n;
    }
}

bool Stack::empty() const
{
    return (top == NULL);
}