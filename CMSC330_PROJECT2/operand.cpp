// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function parseName contained in the Operand class. That function
// parses the next token. When the next non-whitespace character is a digit, it assumes a literal is next. 
// When the next character is a left parenthesis, a recursive call is made to parse the subexpression.
// Otherwise the next token is assumed to a variable. No checks are made to ensure correct syntax.

#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"
#include "operand.h"

Expression* Operand::parse(stringstream& in) {
    char paren;
    int value;

    in >> ws;
    if (isdigit(in.peek())) {
        in >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (in.peek() == '(') {
        in >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName(in));
    return 0;
}