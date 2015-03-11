#pragma once
//*******************************************************
// Purpose: similar to cSymbol class written in lab
//
// Author: Anthony Nguyen
// Email:  anthony.nguyen@oit.edu
//
// Date: 3/10/2015
//
//*******************************************************
#include <iostream>
#include <string>

using namespace std;

class identifier
{
public:
    identifier()
    {
    }
    
    string toString()
    {
        return to_string(_value);
    }
    string getName()
    {
        return _identifier;
    }
    void setName(string identifier)
    {
        _identifier = identifier;
    }
    int getValue()
    {
        return _value;
    }
    void setValue(int value)
    {
        _value = value;
    }
private:
    string _identifier;
    int _value;
};