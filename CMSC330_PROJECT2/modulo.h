
#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class Modulo : public SubExpression {
public:
    Modulo(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        int denominator = right->evaluate();
        if (denominator == 0) {
            throw "Division by zero error";
        }
        return (int)left->evaluate() % denominator;
    }
};