
#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class Exponent : public SubExpression {
public:
    Exponent(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        return pow(left->evaluate(), right->evaluate());
    }
};