#pragma once
#include <iostream>
#include <string>
#include "expression.h"

using namespace std;

class stackCalc : public expression
{
public:
    stackCalc(expression* expr1, expression* expr2, char op)
    {
        _expr1 = expr1;
        _expr2 = expr2;
        _op = op;
    }
    
    string toString()
    {
        return _expr1->toString() + ' ' + _expr2->toString() + ' ' + _op;
    }
    
private:
    expression* _expr1;
    expression* _expr2;
    char _op;
};