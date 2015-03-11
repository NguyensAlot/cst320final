#pragma once
#include <iostream>
#include <string>
#include "baseClass.h"

using namespace std;

class identifier
{
public:
    identifier(expression* expr, string identifier)
    {
        _expr = expr;
        _identifier = identifier;
    }
    
    string toString()
    {
        return "identifier class";
    }
    string getName()
    {
        return _identifier;
    }
private:
    expression* _expr;
    string _identifier;
};