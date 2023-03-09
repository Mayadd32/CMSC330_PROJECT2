
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class Multiply : public SubExpression {
public:
    Multiply(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return left->evaluate() * right->evaluate();
    }
};