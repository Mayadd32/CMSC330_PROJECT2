

#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class LessThan : public SubExpression {
public:
    LessThan(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        return std::min(left->evaluate(), right->evaluate());
    }
    
};