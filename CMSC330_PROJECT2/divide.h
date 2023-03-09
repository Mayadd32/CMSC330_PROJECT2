

#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"

class Divide : public SubExpression {
public:
    Divide(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        double denominator = right->evaluate();
        if (denominator == 0) {
            throw "Division by zero error";
        }
        return left->evaluate() / denominator;
    }
};