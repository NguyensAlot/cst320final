#pragma once
//*******************************************************
// Purpose: Prints out the expression when print token is found
//
// Author: Anthony Nguyen
// Email:  anthony.nguyen@oit.edu
//
// Date: 3/10/2015
//
//*******************************************************
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