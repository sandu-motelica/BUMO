%{
#include <stdio.h>
#include "bumo.tab.h"
%}
%option noyywrap
%%
"program" {return PROGR;} 
"integer"|"real"|"char"|"string"|"boolean" {yylval.str = strdup(yytext);  return TYPE; }
"function" {return FUNCTION;}
"class" {return CLASS;}
"return" {return RETURN;}
"begin" { return BGIN; }
"end" { return END; }
"vars:" { return VAR; }
"methods:" { return MET; }
"constructor:" { return CONSTRUCTOR; }
"new" { return NEW; }
"types:" { return TYPES; }
"functions:" { return FUNCT; }
"true"|"false" {yylval.str = strdup(yytext); return BOOL_VALUE;}
"const" {return CONST;}
"if" {return IF;}
"else" {return ELSE;}
"then" {return THEN;}
"for" {return FOR;}
"while" {return WHILE;}
"Eval" {return EVAL;}
"TypeOf" {return TYPEOF;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.str = strdup(yytext); return IDENTIFIER;}
":=" {return ASSIGN;}
0|[1-9][0-9]* {yylval.str = strdup(yytext); return INT_VALUE;}
0\.[0-9]+|[1-9][0-9]*\.[0-9]+  { 
                            // char *real, *zecim, *ch = strdup(yytext);
                            // real = strtok(ch, ".");
                            // yylval.ftval = atoi(real);
                            // zecim = strtok(NULL,".");

                            // int k = 1;
                            // int n = strlen(zecim);
                            // while (n) { n--; k *= 10; }

                            // yylval.ftval += (float)atoi(zecim) / k;
                            yylval.str = strdup(yytext);
                            return REAL_VALUE;}
\'.\' {yylval.str = strdup(yytext); return CHAR_VALUE;}
\"[^"]*\" {yylval.str = strdup(yytext); return STRING_VALUE;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"\/" {return DIV;}
"%" {return MOD;}
"||" {return OR;}
"&&" {return AND;}
"!" {return NOT;}
"==" {return EQ;}
"!=" {return NQ;}
"<=" {return LE;}
">=" {return GE;}
">" {return GT;}
"<" {return LT;}
"//".*          {}
"/*"([^*]|\*+[^*/])*\*+"/"      {}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
