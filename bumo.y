
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
void initTable();
void clearTable();
class VarList variabile;
void checkVarDecl(const string& name,const string& type,const string& value, bool ct,const string& scope, int line);
void checkVarIsDecl(const string& name,const string& value, int line);
void declArr(const string& name, const string& type, vector<string> values , bool ct, const string& scope,int size, int line);
void checkArr(const string& name, const string& value, int index, int line);
bool toBool(const string& val);
int verifBool(const string& val);
vector<string> array;

string scope = "main";

#define FILE_NAME "table.txt"
%}

%union {
    char* str;
    const char* strconst;
    int intval;
    float ftval;
    bool bval;
}
%token ASSIGN PROGR BGIN END CONST FUNCTION ADD AND NOT OR IF ELSE THEN EQ NQ GT LT LE GE FOR WHILE EVAL TYPEOF
%token<str> IDENTIFIER TYPE STRING_VALUE CHAR_VALUE BOOL_VALUE
%token<intval> INT_VALUE 
%token<ftval> REAL_VALUE
%type<str> valoare 
%type<strconst> eval_function tpof_function
%type<bval> bool_expr relativ_expr relativ_condition
%type<intval> int_expr dimensiune
%type<ftval> real_expr 
// %type<bloc> funct
// %type<param_type> 
%start start

%left NOT 
%left AND 
%left OR 
%left EQ NQ GT LT LE GE

%left ADD SUB  
%left MUL DIV 
%left UMINUS

%%

// AS PUTEA CONVERTI TOATE TIPURILE DE DATE IN valoare SI SA NU MAI SCRIU ACEIASI CHESTIE DE MAI MULTE ORI

/***************** GENERAL RULES ******************/
/*************************************************/

start:
    name function_block '.' { scope="main"; printf("The programme is correct!\n");}
    ;

name:
    PROGR IDENTIFIER ';'
    ;

function_block: 
    declaration_block BGIN statements_block END 
    ;

declaration_block :
    /*empty*/
    | declarations
    ;

declarations:
    declaration
    | declaration declarations
    ;

declaration:
    var_declaration  
    | function_declaration
    ;

var_declaration:
    IDENTIFIER ':' TYPE ';' { if(!variabile.declareVariable($1, $3,false,scope)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE dimensiune ';' { if(!variabile.declareVariable($1, $3,false,scope)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' { declArr($1, $3, array ,false, scope,$4,yylineno);
                                                                 array.clear(); }
    | IDENTIFIER ':' TYPE ASSIGN valoare ';' { checkVarDecl($1,$3,$5,false,scope,yylineno); }
    | CONST IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' { declArr($2, $4, array ,true, scope,$5,yylineno);
                                                                 array.clear(); }
    | CONST IDENTIFIER ':' TYPE ASSIGN valoare ';' { checkVarDecl($2,$4,$6,true,scope,yylineno); }
    ;


function_declaration:
    FUNCTION IDENTIFIER '(' param ')' ':' TYPE  function_block ';' {  variabile.addScope($2); { if(!variabile.declareFunc($2, $7,"main")){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $2);
            exit(EXIT_FAILURE); }}}  
    ;

param: 
    IDENTIFIER ':' TYPE  { printf("%s\n", $1); 
                              if(!variabile.declareVariable($1, $3,false,"func_param")){
                                fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
                                exit(EXIT_FAILURE); }
                            } 
    | IDENTIFIER ':' TYPE ',' param { printf("%s\n", $1); 
                              if(!variabile.declareVariable($1, $3,false,"func_param")){
                                fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
                                exit(EXIT_FAILURE); }
                            } 
    ;

statements_block:
    /*empty*/
    | statements
    ;

statements: 
    statement  
    | if_statement 
    | for_statement
    | while_statement
    | statement statements 
    | if_statement statements
    | for_statement statements
    | while_statement statements
    ;

statement:     
    IDENTIFIER ASSIGN valoare ';'  {checkVarIsDecl($1,$3,yylineno);}
    | IDENTIFIER dimensiune ASSIGN valoare ';' { checkArr($1,$4,$2,yylineno); } 
    ;

eval_function:
    EVAL '(' int_expr ')'   { $$ = to_string($3).c_str();  }
    | EVAL '(' real_expr ')' { $$ = to_string($3).c_str(); }
    | EVAL '(' bool_expr ')'  { $$ = $3 ? "true" : "false"; }
    | EVAL '('IDENTIFIER')'   { if(!variabile.existsVar($3)){
                                    fprintf(stderr, "%d: Error: Variable %s is not defined\n",yylineno, $3);
                                    exit(EXIT_FAILURE); }
                                $$ = variabile.getValue($3).c_str();
                                }
    ; // va trebui sa implementez int real si bool expresiile aparte (care sa nu contina identificator)

tpof_function:
    TYPEOF '(' int_expr ')'   {  $$ = "integer";}
    | TYPEOF '(' real_expr ')' { $$ = "real"; }
    | TYPEOF '(' bool_expr ')'  { $$ = "boolean"; }
    | TYPEOF '('IDENTIFIER')'   { if(!variabile.existsVar($3)){
                                    fprintf(stderr, "%d: Error: Variable %s is not defined\n",yylineno, $3);
                                    exit(EXIT_FAILURE); }
                                 $$ = variabile.getType($3).c_str();
                                }
    ; // va trebui sa implementez int real si bool expresiile aparte (care sa nu contina identificator)



/************** control statements ****************/
/**************************************************/


if_statement : IF '(' condition ')' THEN '{' statements_block '}'
    | IF '(' condition ')' THEN '{' statements_block '}' ELSE '{' statements_block '}'
    ;
for_statement :
    FOR '(' IDENTIFIER ASSIGN expression ';' condition ';' IDENTIFIER ASSIGN expression ')' control_statements_block
    | FOR '(' IDENTIFIER ':' TYPE  ASSIGN expression ';' condition ';' IDENTIFIER ASSIGN expression ')' control_statements_block
    ;

while_statement :
    WHILE '('condition')' control_statements_block

control_statements_block:
    BGIN statements_block END ';'

condition:
    bool_expr
    | relativ_condition
    ;

list: // verificarea cazului cu virgula in plus
    valoare { array.push_back($1); }
    | list ',' valoare { array.push_back($3); }
    ;

dimensiune:
    '[' INT_VALUE ']' {$$ = $2;}
    ;
/***************** Expressions *******************/
/************************************************/

valoare:
    CHAR_VALUE    {$$ = $1;}
    | STRING_VALUE  {$$ = $1;}
    | int_expr {$$ = strdup(to_string($1).c_str());}
    | real_expr {$$ = strdup(to_string($1).c_str());}
    | bool_expr {$$ = $1 ? strdup("true") : strdup("false");}
    | tpof_function {  
                      char temp[16]; 
                      snprintf(temp,sizeof(temp),"\"%s\"",$1);
                      $$ = strdup(temp);
                    }
    | eval_function {$$ = strdup($1);}
    ;

expression:
    bool_expr
    | int_expr
    | real_expr // le stocam ca string in expression
    ;

int_expr :  int_expr ADD int_expr  {$$ = $1 + $3;}
  |  int_expr SUB int_expr  {$$ = $1 - $3;}
  |  int_expr MUL int_expr  {$$ = $1 * $3;}
  |  int_expr DIV int_expr  {$$ = $1 / $3;}
  |  SUB int_expr %prec UMINUS {$$ = -$2;}
  |  '(' int_expr ')' {$$ = $2; }
  |  INT_VALUE {$$ = $1;}
//   |  IDENTIFIER {string  temp = variabile.getValue($1);
//                  if(!variabile.isCompatibleValue("integer",temp)){
//                         fprintf(stderr, "%d: Error: Variable '%s' is not of integer type\n",yylineno, $1);
//                          exit(EXIT_FAILURE);
//                  } 
//                  $$ = stoi(temp); 
//                  }
  ;
real_expr :  real_expr ADD real_expr  {$$ = $1 + $3;}
  |  real_expr SUB real_expr  {$$ = $1 - $3;}
  |  real_expr MUL real_expr  {$$ = $1 * $3;}
  |  real_expr DIV real_expr  {$$ = $1 / $3;}
  |  SUB real_expr %prec UMINUS {$$ = -$2;}
  |  '(' real_expr ')' {$$ = $2; }
  |  REAL_VALUE {$$ = $1;}
//   |  IDENTIFIER { string  temp = variabile.getValue($1);
//                  if(!variabile.isCompatibleValue("real",temp)){
//                         fprintf(stderr, "%d: Error: Variable '%s' is not of real type\n",yylineno, $1);
//                          exit(EXIT_FAILURE);
//                  } 
//                  $$ = stod(temp); 
//                  }
  ;

bool_expr :  bool_expr AND bool_expr  {  $$ = $1 && $3;}
  |  bool_expr OR bool_expr  {$$ = $1 || $3;}
  |  NOT bool_expr  {$$ = !$2;}
  |  '(' bool_expr ')' {$$ = $2; }
  |  BOOL_VALUE {$$ = toBool($1); }
//   |  IDENTIFIER { string temp = variabile.getValue($1);
//                     if(verifBool(temp)!=3){
//                          $$=toBool(temp);
//                     } else { fprintf(stderr, "%d: Error: Variable '%s' is not of boolean type\n",yylineno, $1);
//                         exit(EXIT_FAILURE);
//                     }
//                 }
  ;

relativ_expr : 
    bool_expr EQ bool_expr {$$ = ($1 == $3);}
    | bool_expr NQ bool_expr {$$ = ($1 != $3);}
    | int_expr EQ int_expr {$$ = ($1 == $3);}
    | int_expr NQ int_expr {$$ = ($1 != $3);}
    | int_expr LE int_expr {$$ = ($1 <= $3);}
    | int_expr GE int_expr {$$ = ($1 >= $3);}
    | int_expr GT int_expr {$$ = ($1 > $3);}
    | int_expr LT int_expr {$$ = ($1 < $3);}
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

void checkVarDecl(const string& name,const string& type,const string& value, bool ct, const string& scope,int line){
    if(!variabile.declareVariable(name, type,ct,scope)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",line, name.c_str());
            exit(EXIT_FAILURE); }
    if(!variabile.isCompatibleValue(type,value)){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
        exit(EXIT_FAILURE); 
    }
    variabile.assignValue(name,value);
    cout<< name<< " "<<type<<" "<< value<<endl;
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
    variabile.assignValue(name,value);
}

void declArr(const string& name, const string& type, vector<string> values , bool ct, const string& scope,int size, int line){
    for(const string& s: values){
        if(!variabile.isCompatibleValue(type,s)){
           fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
           exit(EXIT_FAILURE); 
        }
    }
    if(!variabile.declareVariable(name, type,ct,scope)){
        fprintf(stderr, "%d: Error: Variable %s is already defined\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }

    if(values.size() > size){
        fprintf(stderr, "%d: Error: Array '%s' index exceeds size '%d'.\n",line, name.c_str(),size);
           exit(EXIT_FAILURE); 
    }

    for(const string& s: values){
        if(!variabile.isCompatibleValue(type,s)){
           fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
           exit(EXIT_FAILURE); 
        }
    }
    variabile.addValuesToArr(name,values,size);    
}

void checkArr(const string& name, const string& value, int index, int line){
    if(!variabile.existsVar(name)){
        fprintf(stderr, "%d: Error: Variable %s is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    if(!variabile.isCompatibleValue(variabile.getType(name),value)){
           fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),variabile.getType(name).c_str());
           exit(EXIT_FAILURE); 
    }
    if(variabile.isConstant(name)){
        fprintf(stderr, "%d: Error: Constant %s can't be changed\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    variabile.assignValueArr(name, value, index, line);
}

int verifBool(const string& val){
    if(val == "true") return 1;
    else if(val=="false") return 2;
    return 3;
}
bool toBool(const string& val){
    if(val == "true") return true;
    return false;
}



void initTable() {
     FILE *file = fopen(FILE_NAME, "a");
       if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }
    fprintf(file, 
    "%-20s       %-20s      %-20s        %-20s            %-20s             %-20s %-20s",
    "ID",                 "TIP",       "VAL",              "SCOPE ",             "Location"    ,          "Var Type", "Function params");
    fprintf(file, "\n");

    // Close the file
    fclose(file);
}

void clearTable() {
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
     printf("%s\n",scope.c_str());
     variabile.addVarToTable();
} 
