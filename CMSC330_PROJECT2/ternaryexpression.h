
#include <iostream>
#include "expression.h"


class TernaryExpression : public Expression {
public:
    TernaryExpression(Expression* condition, Expression* left, Expression* right) {
        this->condition = condition;
        this->left = left;
        this->right = right;
    }
    double evaluate() {
        if (condition->evaluate() != 0) {
            return left->evaluate();
        }
        else {
            return right->evaluate();
        }
    }
private:
    Expression* condition;
    Expression* left;
    Expression* right;
};