#include "RPN.h"

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string rpn = infix_RPN(infix);
    cout << "Expression in RPN: " << rpn << endl;
    double result = calcRPN(rpn);
    cout << "Result: " << result;
    return 0;
}
