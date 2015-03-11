#pragma once
#include <iostream>
#include <string>
#include "statement.h"

using namespace std;

class printExpr : public statement
{
public:
    printExpr(int expr)
    {
        _expr = expr;
    }
    
    string toString()
    {
        return to_string(_expr) + "\n";
    }
private:
    int _expr;
    
};