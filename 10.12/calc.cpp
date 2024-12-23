#include "calc.h"
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cctype>

double compute(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Не делю на ноль");
        return a / b;
        case '^': return std::pow(a, b);
        default: throw std::runtime_error("Не понимаю");
    }
}

double parseExpression(std::istringstream &ss) {
    double result = 0;
    char op = '+';
    double term;

    while (ss >> std::ws) {
        char c = ss.peek();
        if (isdigit(c) || c == '.') {
            ss >> term;
            result = compute(result, term, op);
        } else if (c == '(') {
            ss.get();
            term = parseExpression(ss);
            result = compute(result, term, op);
        } else if (c == ')') {
            ss.get();
            return result;
        } else if (c == '+' || c == '*' || c == '^') {
            op = c;
            ss.get();
        } else {
            throw std::runtime_error("Что за символ?");
        }
    }

    return result;
}

double evaluate(const std::string& expression) {
    std::istringstream ss(expression);
    return parseExpression(ss);
}