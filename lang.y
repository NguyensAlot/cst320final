/* lang.y */
// Anthony Nguyen

%{
#include <iostream>
#include <string>
#include "lex.h"
%}

%locations

%union{
    int                 int_val;
    baseClass*          base;
    statement*          stmt;
    expression*         expr;
    identifier*         ident;
    }

%{
    int yyerror(const char *msg);
    int semantic_error(std::string msg);

    baseClass *yy_root;
%}

%start  program

%token <ident>      IDENTIFIER
%token <int_val>    INT_VAL

%token  OP
%token  PRINT
%token  END
%token  JUNK_TOKEN

%type <base> program
%type <stmt> stmt
%type <int_val> expr

%%

program: stmt                   { $$ = $1;
                                  yy_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }

stmt:       expr IDENTIFIER ';' 
                                { }
        |   expr PRINT ';'      { std::cout << to_string($1); }
        |   END ';'             { return 0; }

expr:       INT_VAL             { $$ = $1; }
        |   IDENTIFIER          { }
        |   expr expr '+'       { }//$$ = new stackCalc($1, $2, '+'); }
        |   expr expr '-'       { }//$$ = new stackCalc($1, $2, '+'); }
        |   expr expr '*'       { }//$$ = new stackCalc($1, $2, '+'); }
        |   expr expr '/'       { }//$$ = new stackCalc($1, $2, '+'); }
            
%%

int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
int semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg << " on line " << yylineno << "\n";
    
    yynerrs++;

    return 0;
}
