#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Node
{
    public:
        Node(int value);
        void setNext(Node* next);
        int getValue() const;
        Node* getNext();
        int value;
        Node* next;
};

class Stack
{
    public:
        Stack();
        ~Stack();
        int pop();
        int peek();
        void push(int num);
        bool empty() const;

    private:
        Node* top;
};

#endif