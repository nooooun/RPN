#ifndef RPN_RPN_H
#define RPN_RPN_H

#endif //RPN_RPN_H

#pragma once
#include "Stack.h"

bool isOperator(char ch);
bool isNumber(char ch);
int prior(char ch);


string infix_RPN(const string& infix)
{
    stringstream output;
    Stack<char> operators;
    stringstream input(infix);
    char ch;
    while (input >> ch)
    {
        if (isNumber(ch))
        {
            output << ch;
            while (input.peek() and isNumber(input.peek()))
            {
                input >> ch;
                output << ch;
            }
            output << ' ';
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (!operators.isEmpty() and operators.top() != '(')
            {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(ch))
        {
            while (!operators.isEmpty() and prior(operators.top()) >= prior(ch))
            {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.isEmpty())
    {
        output << operators.top() << ' ';
        operators.pop();
    }

    return output.str();
}

double calcRPN(const string& rpn)
{
    Stack<double> operands;
    stringstream input(rpn);
    string token;
    while (input >> token)
    {
        if (isdigit(token[0]))
        {
            operands.push(stod(token));
        }
        else if (isOperator(token[0]))
        {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            double result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }
            operands.push(result);
        }
    }
    return operands.top();
}

bool isOperator(char ch)
{
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^';
}

bool isNumber(char ch)
{
    return isdigit(ch) or ch == '.';
}

int prior(char op)
{
    if (op == '+' or op == '-')
        return 1;
    if (op == '*' or op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}