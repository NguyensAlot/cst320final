%{
// Calc Parser
// Anthony Nguyen

#include "lex.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option nounput
%option yylineno


whitespace      [' ''\t''\n']
operator        [+\-*/]
integer         -?0|(-?[1-9][0-9]*)
identifier      [a-z]+

%%

"//"(.)+$                   {}
{whitespace}+               {}
{operator}                  RETURN(yytext[0]);
"print"                     RETURN(PRINT);
"end"                       RETURN(END);
{integer}                   yylval.int_val = atoi(yytext); RETURN(INT_VAL);
{identifier}                RETURN(yytext[0]);
.                           RETURN(JUNK_TOKEN);   // discard anything not recognized

%%

static int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
