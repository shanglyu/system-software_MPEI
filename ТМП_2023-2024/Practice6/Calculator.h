#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
private:
    static int precedence(char op);

public:
    static std::string infixToPostfix(const std::string& infixExpression);
    static double evaluatePostfix(const std::string& postfixExpression);
};

#endif  // CALCULATOR_H