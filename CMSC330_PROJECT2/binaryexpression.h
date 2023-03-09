
#include <cmath>
#include <iostream>
#include <algorithm>
#include "expression.h"


class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* left, Expression* right, char op) {
        this->left = left;
        this->right = right;
        this->op = op;
    }
    double evaluate() {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            case '%':
                return (int)left->evaluate() % (int)right->evaluate();
            case '^':
                return pow(left->evaluate(), right->evaluate());
            case '<':
                return std::min(left->evaluate(), right->evaluate());
            case '>':
                return std::max(left->evaluate(), right->evaluate());
            case '&':
                return (left->evaluate() + right->evaluate()) / 2.0;
            default:
                throw "Invalid binary operator";
        }
    }
private:
    Expression* left;
    Expression* right;
    char op;
};