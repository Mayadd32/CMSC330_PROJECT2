#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class GreaterThan : public SubExpression {
public:
    GreaterThan(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        return std::max(left->evaluate(), right->evaluate());
    }
};