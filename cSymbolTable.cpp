/*****************************************************
 * Class: cSymbolTable
 * Author: Anthony Nguyen

 * Description: Implementation of cSymboTable.h
 * **************************************************/
#include "cSymbolTable.h"

using namespace std;

cSymbolTable::cSymbolTable()
{
    mapList.push_front(new map<string, cSymbol*>());
}

//brings in symbol and inserts it into default map
identifier* cSymbolTable::Insert(string symbolCharPointer)
{
    identifier* retVal = nullptr;
    map<string,identifier*>::iterator it = mapList.front()->find(symbolCharPointer);
    
    if (it == mapList.front()->end())
    {
        retVal = new cSymbol(symbolCharPointer);
        mapList.front()->insert(pair<string,identifier*>(symbolCharPointer,retVal));
    }
    else 
        retVal = it->second;
        
    return retVal;
}
identifier* cSymbolTable::Insert(identifier* ident)
{
    identifier * retVal = nullptr;
    
    //now passing in the ident mSymbol instead of the string in the parameters
    map<string,identifier*>::iterator it = mapList.front()->find(ident->getName());
    
    if (it == mapList.front()->end())
    {
        mapList.front()->insert(pair<string,identifier*>(ident->getName(),ident));
    }
    else 
    {
        ident = it->second;
    }
    return retVal;
}

identifier* cSymbolTable::LookupSym(string ident)
{
    //Iterator for list of maps
    list<map<string,identifier*>*>::iterator tableList;
    for(tableList = mapList.begin(); tableList != mapList.end(); ++tableList)
    {
        //Search map for identifier
        map<string,identifier*>::iterator sym = (*tableList)->find(ident);
        
        //If found return identifier
        if(sym != (*tableList)->end())
            return sym->second;
    }
    
    //return nothing
    return nullptr;
};