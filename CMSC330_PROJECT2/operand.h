// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the definition of the Operand class, which is a subclass of Expression. It is an
// abstract class because it does not implement the evaluate function. It contains one static (class)
// function parse that parses an operand as either a literal or variable.


#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "multiply.h"
#include "divide.h"
#include "modulo.h"
#include "less_than.h"
#include "greater_than.h"
#include "average.h"
#include "exponent.h"

class Operand: public Expression {
public:
    static Expression* parse(stringstream& in);

protected:
    static double parseNumber(stringstream& in);
    static string parseName(stringstream& in);
};

double Operand::parseNumber(stringstream& in) {
    double value;
    in >> value;
    return value;
}

string Operand::parseName(stringstream& in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()) || in.peek() == '_') {
        in >> alnum;
        name += alnum;
    }
    return name;
}

Expression* Operand::parse(stringstream& in) {
    char paren;
    double value;

    in >> ws;
    if (isdigit(in.peek())) {
        value = parseNumber(in);
        if (in.peek() == '.') {
            in.ignore();
            value += parseNumber(in) / pow(10, in.precision());
        }
        Expression* literal = new Literal(value);
        return literal;
    }
    if (isalpha(in.peek())) {
        return new Variable(parseName(in));
    }
    if (in.peek() == '(') {
        in >> paren;
        return SubExpression::parse(in);
    }
    return 0;
}
 
