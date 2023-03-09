// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp. 


#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "operand.h"
#include "multiply.h"
#include "divide.h"
#include "modulo.h"
#include "less_than.h"
#include "greater_than.h"
#include "average.h"
#include "exponent.h"
  

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    char operation, paren;
    
    left = Operand::parse(in);
    in >> operation;
    switch (operation) {
        case '+':
        case '-':
            // Handle Plus and Minus operators as before
            right = Operand::parse(in);
            in >> paren;
            if (operation == '+') {
                return new Plus(left, right);
            } else {
                return new Minus(left, right);
            }
            break;
        case '*':
            // Handle Multiply operator
            right = Operand::parse(in);
            in >> paren;
            return new Multiply(left, right);
            break;
        case '/':
            // Handle Divide operator
            right = Operand::parse(in);
            in >> paren;
            return new Divide(left, right);
            break;
        case '%':
            // Handle Modulo operator
            right = Operand::parse(in);
            in >> paren;
            return new Modulo(left, right);
            break;
        case '^':
            // Handle Exponent operator
            right = Operand::parse(in);
            in >> paren;
            return new Exponent(left, right);
            break;
        case '<':
            // Handle LessThan operator
            right = Operand::parse(in);
            in >> paren;
            return new LessThan(left, right);
            break;
        case '>':
            // Handle GreaterThan operator
            right = Operand::parse(in);
            in >> paren;
            return new GreaterThan(left, right);
            break;
        case '&':
            // Handle Average operator
            right = Operand::parse(in);
            in >> paren;
            return new Average(left, right);
            break;
        default:
            // Handle invalid operators
            throw "Invalid operator";
    }
    return 0;
}
