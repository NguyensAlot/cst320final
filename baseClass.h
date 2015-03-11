#pragma once
//*******************************************************
// Purpose: Similar to cAstNode
//
// Author: Anthony Nguyen
// Email:  anthony.nguyen@oit.edu
//
// Date: 3/10/2015
//
//*******************************************************
#include <iostream>
#include <string>

class baseClass
{
public:
    virtual std::string toString() = 0;
};