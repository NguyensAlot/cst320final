#pragma once
//*******************************************************
// Purpose: This file holds global variables and references to all class types
//
// Author: Anthony Nguyen
// Email:  anthony.nguyen@oit.edu
//
// Date: 3/10/2015
//
//*******************************************************
#include "baseClass.h"
#include "statement.h"
#include "stackCalc.h"
#include "expression.h"
#include "printExpr.h"
#include "identifier.h"
#include "cSymbolTable.h"

#include "langparse.h"

int yylex();

extern char *yytext;
extern int yylineno;
extern int yynerrs;
extern FILE *yyin;
