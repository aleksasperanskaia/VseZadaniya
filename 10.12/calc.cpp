#include "calc.h"
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cctype>

double parseExpression(std::istringstream& ss);
double parseTerm(std::istringstream& ss);
double compute(double a, double b, char op);

double compute(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("division by zero is impossible");
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::runtime_error("unknown operation");
    }
}

double parseTerm(std::istringstream& ss) {
    double result;
    char op;

    if (isdigit(ss.peek()) || ss.peek() == '.') {
        std::string number;
        char c;
        bool pointSeen = false;

        while (ss >> c && (isdigit(c) || c == '.')) {
            if (c == '.') {
                if (pointSeen) {
                    throw std::runtime_error("dot at the end");
                }
                pointSeen = true;
            }
            number += c;
        }
        ss.putback(c);

        if (number.back() == '.') {
            throw std::runtime_error("Некорректное число: точка в конце");
        }

        result = std::stod(number);
    } else if (ss.peek() == '+' || ss.peek() == '-') {
        char sign = ss.get();
        result = parseTerm(ss);

        if (sign == '-') {
            result = -result;
        }
    } else {
        throw std::runtime_error("Incorrect expression");
    }

    while (ss >> std::ws && (ss.peek() == '*' || ss.peek() == '/' || ss.peek() == '^')) {
        ss.get(op);
        double nextTerm = parseTerm(ss);
        result = compute(result, nextTerm, op);
    }

    return result;
}

double parseExpression(std::istringstream& ss) {
    double result = parseTerm(ss);
    char op;

    while (ss >> std::ws && (ss.peek() == '+' || ss.peek() == '-')) {
        ss.get(op);

        if (op == '-' && ss.peek() == '-') {
            ss.get();
            op = '+';
        }

        double nextTerm = parseTerm(ss);
        result = compute(result, nextTerm, op);
    }

    return result;
}

double evaluate(const std::string& expression) {
    std::istringstream ss(expression);

    if (expression.empty()) {
        throw std::runtime_error("empty input");
    }

    double result = parseExpression(ss);

    if (ss >> std::ws && !ss.eof()) {
        throw std::runtime_error("Incorrect expression");
    }

    return result;
}
