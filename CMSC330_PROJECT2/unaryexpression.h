
#include <iostream>
#include "expression.h"

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression* expr, char op) {
        this->expr = expr;
        this->op = op;
    }
    double evaluate() {
        if (op == '~') {
            return ~(int)expr->evaluate();
        }
        else {
            throw "Invalid unary operator";
        }
    }
private:
    Expression* expr;
    char op;
};