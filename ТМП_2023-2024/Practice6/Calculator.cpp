#include "Calculator.h"
#include <stdexcept>
#include <sstream>
#include <cmath>

using namespace std;

int Calculator::precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string Calculator::infixToPostfix(const string& infixExpression) {
    stack<char> operators;
    stringstream postfix;

    for (char c : infixExpression) {
        if (c == ' ' || c == '\t') {
            continue;
        }

        if (isdigit(c) || c == '.') {
            postfix << c;
            postfix << ' ';  // Add space after each operand
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix << ' ' << operators.top();
                operators.pop();
            }

            if (operators.empty()) {
                throw runtime_error("Mismatched parentheses");
            }

            operators.pop();  // Remove the opening parenthesis
        } else {
            while (!operators.empty() && operators.top() != '(' && precedence(c) <= precedence(operators.top())) {
                postfix << ' ' << operators.top();
                operators.pop();
            }

            operators.push(c);
            postfix << ' ';  
            // Add space after each operator
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            throw runtime_error("Mismatched parentheses");
        }

        postfix << ' ' << operators.top();
        operators.pop();
    }

    return postfix.str();
}

double Calculator::evaluatePostfix(const string& postfixExpression) {
    stack<double> operands;
    stringstream ss(postfixExpression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(stod(token));
        } else {
            if (operands.size() < 2) {
                throw runtime_error("Invalid postfix expression");
            }

            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            double result = 0.0;

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
                    if (operand2 == 0.0) {
                        throw runtime_error("Division by zero");
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                default:
                    throw runtime_error("Invalid operator");
            }

            operands.push(result);
        }
    }

    if (operands.size() != 1) {
        throw runtime_error("Invalid postfix expression");
    }

    return operands.top();
}