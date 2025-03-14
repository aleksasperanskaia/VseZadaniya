#ifndef CALC_H
#define CALC_H

#include <string>

double compute(double a, double b, char op);
double parseTerm(std::istringstream& ss);
double parseExpression(std::istringstream& ss);
double evaluate(const std::string& expression);

#endif