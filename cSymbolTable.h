/*****************************************************
 * Class: cSymbolTable
 * Author: Anthony Nguyen
 * 
 * Description: Takes care of cSymbol maps
 * **************************************************/
#pragma once
#include <iostream>
#include <list>
#include <map>
#include <string>
#include "identifier.h"

using namespace std;

class cSymbolTable
{
public:
    cSymbolTable();
    identifier* Insert(string symbol);
    identifier* Insert(identifier* csymbol);
    identifier* LookupSym(string symbol);
private:
    list<map<string, identifier*>*> mapList;
};