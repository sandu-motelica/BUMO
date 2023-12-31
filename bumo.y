%{
#include <iostream>
#include <vector>
#include "VarList.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class VarList variabile;
void checkVar(const string& name,const string& type,const string& value, int line);
%}

%union {
    char* str;
    int intval;
    float ftval;
}
%token ASSIGN INT_VALUE CHAR_VALUE REAL_VALUE BOOL_VALUE PROGR BGIN END
%token<str> IDENTIFIER TYPE STRING_VALUE
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
    IDENTIFIER ':' TYPE ';' { if(!variabile.declareVariable($1, $3)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE ASSIGN INT_VALUE ';'  { if(!variabile.declareVariable($1, $3)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE ASSIGN REAL_VALUE ';' { if(!variabile.declareVariable($1, $3)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE ASSIGN CHAR_VALUE ';' { if(!variabile.declareVariable($1, $3)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE ASSIGN STRING_VALUE ';' { checkVar($1,$3,$5,yylineno); }
    | IDENTIFIER ':' TYPE ASSIGN BOOL_VALUE ';' { if(!variabile.declareVariable($1, $3)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); 
            }}
    ;

statements:
    /*empty*/
    | statement statements
    ;
statement:
    IDENTIFIER ASSIGN IDENTIFIER ';';
    | IDENTIFIER ASSIGN INT_VALUE ';';
    | IDENTIFIER ASSIGN CHAR_VALUE ';';
    | IDENTIFIER ASSIGN REAL_VALUE ';';
    | IDENTIFIER ASSIGN STRING_VALUE ';';
    | IDENTIFIER ASSIGN BOOL_VALUE ';';


%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

void checkVar(const string& name,const string& type,const string& value, int line){
    if(!variabile.declareVariable(name, type)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",line, name);
            exit(EXIT_FAILURE); }
    if(!variabile.isCompatibleValue(type,value)){
        fprintf(stderr, "%d: Error: Variable %s type is illegal\n",line, name);
        exit(EXIT_FAILURE); 
    }
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();    
} 
