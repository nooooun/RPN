#ifndef RPN_STACK_H
#define RPN_STACK_H

#endif //RPN_STACK_H

#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <sstream>

using namespace std;

template <typename T>

class Stack {
private:
    T* stack;
    int size;
    int capacity;
public:
    Stack(int capacity = 100) : size(0), capacity(capacity)
    {
        stack = new T[capacity];
    }

    ~Stack()
    {
        delete[] stack;
    }

    void push(T element)
    {
        if (size < capacity)
        {
            stack[size++] = element;
        }
        else
        {
            cerr << "Stack overflow" << endl;
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void pop() {
        if (!isEmpty())
        {
            --size;
        }
        else
        {
            cerr << "Stack is empty" << endl;
        }
    }

    T top()
    {
        if (!isEmpty())
        {
            return stack[size - 1];
        }
        else
        {
            cerr << "Stack is empty" << endl;
            return T();
        }
    }
};