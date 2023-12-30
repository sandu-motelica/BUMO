%{
#include <stdio.h>
#include "bumo.tab.h"
%}
%option noyywrap
%%
"program" {return PROGR;} 
"integer" { return INTEGER; }
"real" { return REAL; }
"char" { return CHAR; }
"string" { return STRING; }
"boolean" { return BOOLEAN; }
"begin" { return BGIN; }
"end" { return END; }
[a-zA-Z][a-zA-Z0-9_]* { return IDENTIFIER;}
":=" {return ASSIGN;}
0|[1-9][0-9]* {return INT_VALUE;}
0\.[0-9]+|[1-9][0-9]*\.[0-9]+  {return REAL_VALUE;}
\'.\' {return CHAR_VALUE;}
\".*\" {return STRING_VALUE;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
