%{
#include <iostream>
#include <vector>
#include <stdbool.h>
#include "VarList.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
void createTable(const string& name,const string& type,const string& value, bool ct);
void initTable();
void clearTable();
class VarList variabile;
void checkVarDecl(const string& name,const string& type,const string& value, bool ct, int line);
void checkVarIsDecl(const string& name,const string& value, int line);
bool toBool(const string& val);

#define FILE_NAME "table.txt"
%}

%union {
    char* str;
    int intval;
    float ftval;
    bool bval;
}
%token ASSIGN PROGR BGIN END CONST FUNCTION ADD AND NOT OR IF ELSE THEN EQ NQ GT LT LE GE FOR WHILE
%token<str> IDENTIFIER TYPE STRING_VALUE CHAR_VALUE BOOL_VALUE
%token<intval> INT_VALUE 
%token<ftval> REAL_VALUE
%type<str> valoare_str 
%type<bval> bool_expr relativ_expr relativ_condition
%type<intval> int_expr 
%type<ftval> real_expr 
// %type<bloc> funct
// %type<param_type> 
%start st

%left NOT 
%left AND 
%left OR 
%left EQ NQ GT LT LE GE

%left ADD SUB  
%left MUL DIV 


%%

st:
    name declarations BGIN statements END '.'{printf("The programme is correct!\n");}
    ;

name:
    PROGR IDENTIFIER ';'
    ;
    /*empty*/
declarations:   //{  $$ = new VarList(""); }
    | declaration declarations
    ;

declaration:
    var_declaration  
    | function_declaration
    ;

var_declaration:
    IDENTIFIER ':' TYPE ';' { if(!variabile.declareVariable($1, $3,false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE dimensiune ';' { if(!variabile.declareVariable($1, $3,false)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' 
    | IDENTIFIER ':' TYPE ASSIGN int_expr ';'  { checkVarDecl($1,$3,to_string($5),false,yylineno); }
    | IDENTIFIER ':' TYPE ASSIGN real_expr ';' { checkVarDecl($1,$3,to_string($5),false,yylineno); }
    | IDENTIFIER ':' TYPE ASSIGN valoare_str ';' { checkVarDecl($1,$3,$5,false,yylineno); }
    | IDENTIFIER ':' TYPE ASSIGN bool_expr ';' { checkVarDecl($1,$3,$5 ? "true" : "false",false,yylineno); }
    | CONST IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' 
    | CONST IDENTIFIER ':' TYPE ASSIGN int_expr ';'  { checkVarDecl($2,$4,to_string($6),true,yylineno); }
    | CONST IDENTIFIER ':' TYPE ASSIGN real_expr ';' { checkVarDecl($2,$4,to_string($6),true,yylineno); }
    | CONST IDENTIFIER ':' TYPE ASSIGN valoare_str ';' { checkVarDecl($2,$4,$6,true,yylineno); }
    | CONST IDENTIFIER ':' TYPE ASSIGN bool_expr ';' { checkVarDecl($2,$4,$6 ? "true" : "false",true,yylineno); }
    ;

function_declaration:
    FUNCTION IDENTIFIER '(' param ')' ':' TYPE  block  /*{  $$ = new VarList("main");
                                                            $$.addFunction($2,$7,$4); }*/
    ;

param: IDENTIFIER ':' TYPE    /* {$$.push_back(make_pair($1,$3))}*/
         | IDENTIFIER ':' TYPE ',' //param {$$.push_back(make_pair($1,$3))}
         ;
block:
    BGIN statements END ';'
    ;

valoare_str:
     CHAR_VALUE    {$$ = $1;}
    | STRING_VALUE  {$$ = $1;}
    ;
dimensiune:
    '[' INT_VALUE ']'
    | '[' INT_VALUE ']''[' INT_VALUE ']'
    ;


statements:
    /*empty*/
    | statement statements 
    | if_statement statements
    | for_statement statements
    | while_statement statements
    ;

statement:     
     IDENTIFIER ASSIGN int_expr ';'  {checkVarIsDecl($1,to_string($3),yylineno);}
    | IDENTIFIER ASSIGN real_expr ';'  {checkVarIsDecl($1,to_string($3),yylineno);}
    | IDENTIFIER ASSIGN bool_expr ';'  {checkVarIsDecl($1,$3 ? "true" : "false",yylineno);}
    | IDENTIFIER ASSIGN valoare_str ';'  {checkVarIsDecl($1,$3,yylineno);}
    | IDENTIFIER dimensiune ASSIGN valoare_str ';' // verificare
    | IDENTIFIER dimensiune ASSIGN int_expr ';' // verificare
    | IDENTIFIER dimensiune ASSIGN real_expr ';'  // verificare   
     ;


/******** control statements ******************/
/*********************************************/



if_statement : IF '(' condition ')' THEN '{' statements '}'
    | IF '(' condition ')' THEN '{' statements '}' ELSE '{' statements '}'
    ;
for_statement :
    FOR '(' IDENTIFIER ASSIGN expression ';' condition ';' IDENTIFIER ASSIGN expression ')' block
    | FOR '(' IDENTIFIER ':' TYPE  ASSIGN expression ';' condition ';' IDENTIFIER ASSIGN expression ')' block
    ;
while_statement :
    WHILE '('condition')' block

expression:
    bool_expr
    | int_expr
    | real_expr // le stocam ca string in expression
    ;
condition:
    bool_expr
    | relativ_condition
    ;

list: // verificarea cazului cu virgula in plus
    | int_expr
    | real_expr
    | valoare_str
    | list ',' int_expr
    | list ',' real_expr
    | list ',' valoare_str
    ;
int_expr :  int_expr ADD int_expr  {$$ = $1 + $3;}
  |  int_expr SUB int_expr  {$$ = $1 - $3;}
  |  int_expr MUL int_expr  {$$ = $1 * $3;}
  |  int_expr DIV int_expr  {$$ = $1 / $3;}
  |  '(' int_expr ')' {$$ = $2; }
  |  INT_VALUE {$$ = $1;}
  ;
real_expr :  real_expr ADD real_expr  {$$ = $1 + $3;}
  |  real_expr SUB real_expr  {$$ = $1 - $3;}
  |  real_expr MUL real_expr  {$$ = $1 * $3;}
  |  real_expr DIV real_expr  {$$ = $1 / $3;}
  |  '(' real_expr ')' {$$ = $2; }
  |  REAL_VALUE {$$ = $1;}
  ;

bool_expr :  bool_expr AND bool_expr  {  $$ = $1 && $3;}
  |  bool_expr OR bool_expr  {$$ = $1 || $3;}
  |  NOT bool_expr  {$$ = !$2;}
  |  '(' bool_expr ')' {$$ = $2; }
  |  BOOL_VALUE {$$ = toBool($1); }
  |  IDENTIFIER {$$ = toBool($1);}
  ;

relativ_expr : 
    bool_expr EQ bool_expr {$$ = ($1 == $3);}
    | bool_expr NQ bool_expr {$$ = ($1 != $3);}
    | int_expr EQ int_expr {$$ = ($1 == $3);}
    | int_expr NQ int_expr {$$ = ($1 != $3);}
    | int_expr LE int_expr {$$ = ($1 <= $3);}
    | int_expr GE int_expr {$$ = ($1 >= $3);}
    | int_expr GT int_expr {$$ = ($1 > $3);}
    | int_expr LT int_expr {$$ = ($1 > $3);}
    ;

relativ_condition:
    relativ_condition AND relativ_condition  {  $$ = $1 && $3;}
    |  relativ_condition OR relativ_condition  {$$ = $1 || $3;}
    |  NOT relativ_condition  {$$ = !$2;}
    |  '(' relativ_condition ')' {$$ = $2; }
    |  relativ_expr {$$ = $1; }
    ;

%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

void checkVarDecl(const string& name,const string& type,const string& value, bool ct,int line){
    if(!variabile.declareVariable(name, type,ct)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",line, name.c_str());
            exit(EXIT_FAILURE); }
    if(!variabile.isCompatibleValue(type,value)){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
        exit(EXIT_FAILURE); 
    }
    createTable(name,type, value,ct);
}
void checkVarIsDecl(const string& name,const string& value, int line){
    if(variabile.isConstant(name)){
        fprintf(stderr, "%d: Error: Constant %s can't be changed\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    if(variabile.IsDeclareVariable(name,value)==3){
        fprintf(stderr, "%d: Error: Variable %s is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE); }
    else if(variabile.IsDeclareVariable(name,value)==2){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s'\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }
}
bool toBool(const string& val){
    if(val == "true") return true;
    return false;
}

void createTable(const string& name,const string& type,const string& value, bool ct) {
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }

    fprintf(file, "%s       %s       %s        %s  ", name.c_str(),type.c_str(),value.c_str(), ct ? "true" : "false");
     fprintf(file, "\n");

    // Close the file
    fclose(file);

}

void initTable() {
     FILE *file = fopen(FILE_NAME, "a");
       if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }
    fprintf(file, "ID       TIP       VAL        CONST");
    fprintf(file, "\n");

    // Close the file
    fclose(file);
}

void clearTable() {
     // Specify the file path

    // Use the remove function to delete the file
    if (remove(FILE_NAME) != 0) {
        perror("Error deleting file");
    }

    printf("File %s deleted successfully.\n", FILE_NAME);
}

int main(int argc, char** argv){
    clearTable();
     initTable();
     yyin=fopen(argv[1],"r");
     yyparse();    
} 
