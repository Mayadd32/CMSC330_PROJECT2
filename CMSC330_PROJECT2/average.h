#include <cmath>
#include <algorithm>
#include <iostream>
#include "expression.h"
#include "subexpression.h"


class Average : public SubExpression {
public:
    Average(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        return (left->evaluate() + right->evaluate()) / 2.0;
    }
};