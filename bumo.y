%{
#include <iostream>
#include <vector>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
%}

%union {
}
%token ASSIGN INT_VALUE CHAR_VALUE STRING_VALUE REAL_VALUE PROGR BGIN END IDENTIFIER INTEGER REAL CHAR STRING BOOLEAN

%start st

%%

st:
    name declarations BGIN statements END '.' {printf("The programme is correct!\n");}
    ;

name:
    PROGR IDENTIFIER ';'
    ;
declarations:
    /*empty*/
    | declaration declarations
    ;
declaration:
    IDENTIFIER ':' type ';'
    | IDENTIFIER ':' type ASSIGN INT_VALUE ';'
    | IDENTIFIER ':' type ASSIGN REAL_VALUE ';'
    | IDENTIFIER ':' type ASSIGN CHAR_VALUE ';'
    | IDENTIFIER ':' type ASSIGN STRING_VALUE ';'
    ;

statements:
    /*empty*/
    | statement statements
    ;
statement:
    IDENTIFIER ASSIGN INT_VALUE ';';
    | IDENTIFIER ASSIGN CHAR_VALUE ';';
    | IDENTIFIER ASSIGN REAL_VALUE ';';
    | IDENTIFIER ASSIGN STRING_VALUE ';';
type:
    INTEGER
    | REAL
    | BOOLEAN
    | CHAR
    | STRING
    ;

%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();    
} 
