
#include <iostream>
#include "expression.h"

class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* value, Expression* left, Expression* middle, Expression* right) {
        this->value = value;
        this->left = left;
        this->middle = middle;
        this->right = right;
    }
    double evaluate() {
        if (value->evaluate() < 0) {
            return left->evaluate();
        }
        else if (value->evaluate() == 0) {
            return middle->evaluate();
        }
        else {
            return right->evaluate();
        }
    }
private:
    Expression* value;
    Expression* left;
    Expression* middle;
    Expression* right;
};