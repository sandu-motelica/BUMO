%{
#include <stdio.h>
#include "bumo.tab.h"
%}
%option noyywrap
%%
"program" {return PROGR;} 
"integer"|"real"|"char"|"string"|"boolean" {yylval.str = strdup(yytext);  return TYPE; }
"function" {return FUNCTION;}
"begin" { return BGIN; }
"end" { return END; }
"true"|"false" {yylval.str = strdup(yytext); return BOOL_VALUE;}
"const" {return CONST;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.str = strdup(yytext); return IDENTIFIER;}
":=" {return ASSIGN;}
0|[1-9][0-9]* {yylval.intval = atoi(yytext); return INT_VALUE;}
0\.[0-9]+|[1-9][0-9]*\.[0-9]+  { 
                            char *real, *zecim, *ch = strdup(yytext);
                            real = strtok(ch, ".");
                            yylval.ftval = atoi(real);
                            zecim = strtok(NULL,".");

                            int k = 1;
                            int n = strlen(zecim);
                            while (n) { n--; k *= 10; }

                            yylval.ftval += (float)atoi(zecim) / k;
                            return REAL_VALUE;}
\'.\' {yylval.str = strdup(yytext); return CHAR_VALUE;}
\"[^"]*\" {yylval.str = strdup(yytext); return STRING_VALUE;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"\/" {return DIV;}
"||" {return OR;}
"&&" {return AND;}
"!" {return NOT;}
"//".*          {}
"/*".*"*/"      {}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
