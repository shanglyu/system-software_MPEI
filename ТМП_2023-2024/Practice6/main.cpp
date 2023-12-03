#include <iostream>
#include "Calculator.h"

using namespace std;
int main() {
    try {
        string infixExpression;
        
        cout << "Enter an arithmetic expression in infix notation: ";
        getline(cin, infixExpression);
        
        string postfixExpression = Calculator::infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
        
        double result = Calculator::evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
    
    return 0;
}