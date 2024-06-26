
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
void checkArr(const string& name,const string& var_type, const string& value, int index, int line);
void callFunction(const string&name, vector<string> args, int line);
bool toBool(const string& val);
int verifBool(const string& val);
void verificareCorectitudineVal(const string& value, const string& type, int line);
void verificareCorectitudineId(const string& id,const string& var_type, int line);
void verificareCorectitudineArray(const string& id, const string& var_type, int index, int line);
void verificareCorectitudineFunct(const string& id, int line);
void verificareCorectitudineClassId(const string& class_name, const string& class_var, int line);
string getFuncValue(const string& id);
vector<string> arr;
bool isReturn = false; 
string return_value = "none";
string scope = "main";
int funct_counter = 0; 
int class_counter = 0;
string exprflg = "none";

#define FILE_NAME "table.txt"
%}

%union {
    char* str;
    int intval;
    float ftval;
    bool bval;
    class ASTNode* node;

}
%token ASSIGN PROGR BGIN END CONST FUNCTION ADD SUB DIV MUL AND NOT OR IF ELSE THEN EQ NQ GT LT LE GE FOR WHILE EVAL TYPEOF RETURN CLASS TYPES VAR FUNCT MET CONSTRUCTOR NEW
%token<str> IDENTIFIER TYPE STRING_VALUE CHAR_VALUE BOOL_VALUE INT_VALUE REAL_VALUE
%type<node> expr relativ_expr
%type<str> valoare call_function eval_function tpof_function
%type<intval> dimensiune
%type<bval> relativ_condition
%start start

%left OR 
%left AND 
%left EQ NQ
%left GT LT LE GE
%left ADD SUB  
%left MUL DIV MOD
%left NOT 
%left UMINUS

%%

/***************** GENERAL RULES ******************/
/*************************************************/

start:
    name declaration_block BGIN statements_block END  '.' { variabile.checkSyntax(); printf("The programme is correct!\n");}
    ;

name:
    PROGR IDENTIFIER ';'
    ;

declaration_block :
    /*emptu*/
    | TYPES types_declarations VAR var_declarations FUNCT function_declarations
    ;

types_declarations:
    /*empty*/
    | class_declaration types_declarations
    ;

var_declarations:
    /*empty*/
    | var_declaration var_declarations 
    ;

function_declarations:
    /*empty*/
    | function_declaration function_declarations 
    ;

class_declaration:
    CLASS IDENTIFIER BGIN class_block END ';' {
        variabile.addLocationType(class_counter,$2); 
        if(!variabile.declareClass($2)){
            fprintf(stderr, "%d: Error: Variable '%s' is already defined\n",yylineno, $2);
            exit(EXIT_FAILURE); 
        }
        class_counter = 0;

    }
    ;

class_block:
    VAR var_declarations_class MET methods_block CONSTRUCTOR construct_function {}
    ;

var_declarations_class:
    /*empty*/
    | var_declaration var_declarations_class {class_counter++;}
    ;


methods_block:
    /*empty*/
    | function_declaration methods_block {class_counter++;}
    ;

construct_function:
    NEW '(' construct_args ')' ';'
    ;

construct_args:
    /*empty*/
    | construct_args_list
    ;

construct_args_list:
    construct_arg
    | construct_arg ',' construct_args_list
    ;

construct_arg:
    IDENTIFIER ':' TYPE
    ;


var_declaration:
    IDENTIFIER ':' TYPE ';' {   
                                if(!variabile.declareVariable($1, $3,false,scope,yylineno)){
                                fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
                                exit(EXIT_FAILURE); }
                                }                       
    | IDENTIFIER ':' IDENTIFIER ASSIGN NEW IDENTIFIER '(' ')' ';' {
        if(strcmp($3,$6)!=0){
            fprintf(stderr, "%d: Error: Invalid defined\n",yylineno);
            exit(EXIT_FAILURE);
        }
        if(!variabile.declareVariable($1,$3,false,scope,yylineno)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }
        variabile.initClassData($1, $3,yylineno);
    }
    | IDENTIFIER ':' TYPE dimensiune ';' { if(!variabile.declareArr($1, $3,false,scope,yylineno)){
            fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
            exit(EXIT_FAILURE); }}
    | IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' { declArr($1, $3, arr ,false, scope,$4,yylineno);
                                                                 arr.clear(); }
    | IDENTIFIER ':' TYPE ASSIGN valoare ';' { checkVarDecl($1,$3,$5,false,scope,yylineno); }
    | CONST IDENTIFIER ':' TYPE dimensiune ASSIGN '{' list '}' ';' { declArr($2, $4, arr ,true, scope,$5,yylineno);
                                                                 arr.clear(); }
    | CONST IDENTIFIER ':' TYPE ASSIGN valoare ';' { checkVarDecl($2,$4,$6,true,scope,yylineno); }
    ;

// var_list:
//     IDENTIFIER  {arr.push_back($1);}
//     // | IDENTIFIER ',' var_list {arr.push_back($1);}
//     ;

function_declaration:
    FUNCTION IDENTIFIER '(' params ')' ':' TYPE  function_block ';' {
                                            if(!variabile.isCompatibleValue($7,return_value)){
                                                fprintf(stderr, "%d: Error: Incompatible return type. The function should return '%s'.\n",yylineno, $7);
                                                exit(EXIT_FAILURE);
                                            }
                                            variabile.addScopeVars(funct_counter,$2);  variabile.addScopeParams($2); 
                                            if(!variabile.declareFunc($2, $7,"main",yylineno)){
                                                fprintf(stderr, "%d: Error: Variable '%s' is already defined\n",yylineno, $2);
                                                exit(EXIT_FAILURE); 
                                            }
                                            funct_counter = 0;}  
    ;

params: 
    /*empty*/
    | param_list
    ;

param_list:
    param 
    | param_list ',' param 
    ;

param:
    IDENTIFIER ':' TYPE {  
                              if(!variabile.declareVariable($1, $3,false,"func_param",yylineno)){
                                fprintf(stderr, "%d: Error: Variable %s is already defined\n",yylineno, $1);
                                exit(EXIT_FAILURE); }
                            } 
    ;

function_block:
    function_declarations_block BGIN statements_block END {
        if (!isReturn) {
            fprintf(stderr, "%d: Error: Function must have a return statement\n", yylineno);
            exit(EXIT_FAILURE);
        }
        isReturn = false; 
        scope = "main";
    }
    ;

function_declarations_block:
    /*empty*/
    | var_declaration function_declarations_block {funct_counter++; class_counter++;}
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
    | return_statement
    | statement statements
    | if_statement statements
    | for_statement statements
    | while_statement statements
    | return_statement statements
    ;

return_statement:
    RETURN valoare ';' {
        return_value = $2;
        isReturn = true;
    }

statement:     
    IDENTIFIER ASSIGN valoare ';'  {checkVarIsDecl($1,$3,yylineno);}
    | IDENTIFIER dimensiune ASSIGN valoare ';' { checkArr($1,"arr",$4,$2,yylineno); } 
    | IDENTIFIER '~' IDENTIFIER ASSIGN valoare ';' {  variabile.assignClassEl($1,$3,$5,yylineno);  }
    | statement_call_function ';'
    | tpof_function ';' { printf("Type of: %s\n",$1); }
    | eval_function ';' { printf("Eval: %s\n",$1); }
    ;

statement_call_function:
    IDENTIFIER '(' args_list ')'  {  callFunction($1,arr,yylineno); arr.clear(); }
    ;

call_function:
    IDENTIFIER '(' args_list ')'  { $$ = $1; callFunction($1,arr,yylineno); arr.clear(); }
    ;

args_list:
    /*empty*/
    | args 
    ;

args:
    arg
    | arg ',' args
    ;

arg:
    valoare { arr.push_back($1); }
    ;


eval_function:
    EVAL '(' valoare ')'   { $$ = $3; exprflg = "none";}
    ;

tpof_function:
    TYPEOF '(' valoare ')'   {
                             if(variabile.isCompatibleValue("integer",$3)) $$ = strdup("integer");
                             if(variabile.isCompatibleValue("real", $3)) $$ = strdup("real");
                             if(variabile.isCompatibleValue("boolean", $3)) $$ = strdup("boolean"); 
                             if(variabile.isCompatibleValue("string", $3)) $$ = strdup("string"); 
                             if(variabile.isCompatibleValue("char", $3)) $$ = strdup("char"); 
                             exprflg = "none";    
                          }
    ;

/************** control statements ****************/
/**************************************************/


if_statement : IF '(' condition ')' THEN '{' statements_block '}' 
    | IF '(' condition ')' THEN '{' statements_block '}' ELSE '{' statements_block '}'
    ;
for_statement :
    FOR '(' IDENTIFIER ASSIGN valoare ';' condition ';' IDENTIFIER ASSIGN valoare ')' control_statements_block
    | FOR '(' IDENTIFIER ':' TYPE  ASSIGN valoare ';' condition ';' IDENTIFIER ASSIGN valoare ')' control_statements_block
    ;

while_statement :
    WHILE '('condition')' control_statements_block

control_statements_block:
    BGIN statements_block END ';'

condition:
    relativ_condition { cout<<"Conditie: "<<$1<<endl;}
    ;

list:
    valoare { arr.push_back($1); }
    | list ',' valoare { arr.push_back($3); }
    ;

dimensiune:
    '[' INT_VALUE ']' {$$ = stoi($2);}
    ;
/***************** expressions *******************/
/************************************************/

valoare:
    CHAR_VALUE    {$$ = $1;}
    | STRING_VALUE  {$$ = $1;}
    | expr {$$ = strdup($1->evaluateAST().c_str()); exprflg = "none";}
    | relativ_condition { if($1) $$ = strdup("true");
                             else $$ = strdup("false");

                        }
    ;


expr: expr ADD expr { 
                    if(exprflg!="integer" && exprflg!="real"){
                        fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n",yylineno, exprflg.c_str());
                        exit(EXIT_FAILURE);     
                    }
                    $$ = new ASTNode(exprflg, "+"); $$->children.push_back($1); $$->children.push_back($3);

                    }
  |  expr SUB expr  { 
                    if(exprflg!="integer" && exprflg!="real"){
                        fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
                        exit(EXIT_FAILURE);     
                    }
                    $$ = new ASTNode(exprflg, "-"); $$->children.push_back($1); $$->children.push_back($3);
                }
  |  expr MUL expr  {
                    if(exprflg!="integer" && exprflg!="real"){
                        fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
                        exit(EXIT_FAILURE);     
                    }
                    $$ = new ASTNode(exprflg, "*"); $$->children.push_back($1); $$->children.push_back($3);
                }
  |  expr DIV expr  { 
                    if(exprflg != "integer" && exprflg != "real"){
                                fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
                                exit(EXIT_FAILURE);     
                        }
                    $$ = new ASTNode(exprflg, "/"); $$->children.push_back($1); $$->children.push_back($3);
  
                }
  |  expr MOD expr  {
                        if(exprflg!="integer"){
                                fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
                                exit(EXIT_FAILURE);     
                        }
                        $$ = new ASTNode(exprflg, "%%"); $$->children.push_back($1); $$->children.push_back($3);                      
                        }
  |  SUB expr %prec UMINUS { 
                        if(exprflg!="real" && exprflg!="integer"){
                                fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
                                exit(EXIT_FAILURE);     
                            }
                        $$ = new ASTNode(exprflg, "-"); $$->children.push_back($2); $$->children.push_back(nullptr);
                        }
  |  expr AND expr  { 
                        if(exprflg!="boolean"){
                            fprintf(stderr, "%d: Syntax error: casting is not support\n",yylineno);
                            exit(EXIT_FAILURE);     
                        }
                        $$ = new ASTNode(exprflg, "&&"); $$->children.push_back($1); $$->children.push_back($3);
  }
  |  expr OR expr  { 
                    if(exprflg!="boolean"){
                        fprintf(stderr, "%d: Syntax error: casting is not support\n",yylineno);
                        exit(EXIT_FAILURE);     
                    }
                    $$ = new ASTNode(exprflg, "||"); $$->children.push_back($1); $$->children.push_back($3);
                    }
  |  NOT expr  { 
                    if(exprflg!="boolean"){
                        fprintf(stderr, "%d: Syntax error: casting is not support\n", yylineno);
                        exit(EXIT_FAILURE);     
                    }
                    $$ = new ASTNode("", "!"); $$->children.push_back($2); $$->children.push_back(nullptr);
                    }

  |  '(' expr ')' { $$ = $2; }
  |  INT_VALUE { verificareCorectitudineVal(strdup($1),"integer", yylineno);  $$= new ASTNode("integer",$1);}
  |  BOOL_VALUE { verificareCorectitudineVal(strdup($1),"boolean", yylineno); $$= new ASTNode("boolean",$1);;}
  |  REAL_VALUE { verificareCorectitudineVal(strdup($1),"real", yylineno); $$= new ASTNode("real",$1);}
  |  IDENTIFIER { verificareCorectitudineId(strdup($1),"var", yylineno);  
                  string temp = variabile.getValue($1);
                  if(temp == ""){
                    fprintf(stderr, "%d: Error: Use of uninitialized variable '%s'\n",yylineno, $1);
                    exit(EXIT_FAILURE); 
                  }
                  $$= new ASTNode(variabile.getType($1,"var"),temp);
                  }
  |  call_function { verificareCorectitudineId(strdup($1),"function", yylineno); 
                     string temp = getFuncValue($1);
                     $$= new ASTNode(variabile.getType($1,"function"),temp);
                    }
  |  IDENTIFIER '~' IDENTIFIER { verificareCorectitudineClassId($1,$3,yylineno); 
                                string temp = variabile.getClassIdValue($1, $3);
                                if(temp == ""){
                                  fprintf(stderr, "%d: Error: Use of uninitialized variable '%s~%s'\n",yylineno, $1,$3);
                                  exit(EXIT_FAILURE); 
                                }

                                 $$ = new ASTNode(variabile.getType($3,"var"),temp);
                                }
  |  IDENTIFIER dimensiune { verificareCorectitudineArray($1,"arr",$2, yylineno);  
                             $$ = new ASTNode(variabile.getType($1,"arr"), variabile.getArrayValue($1, $2));
  }
  ;
    

relativ_expr : 
    expr EQ expr { $$ = new ASTNode("", "=="); $$->children.push_back($1); $$->children.push_back($3);}
    | expr NQ expr {$$ = new ASTNode("", "!="); $$->children.push_back($1); $$->children.push_back($3);}
    | expr LE expr {
        if(exprflg != "integer" && exprflg != "real"){
             fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
             exit(EXIT_FAILURE);     
        }
        $$ = new ASTNode(exprflg, "<="); $$->children.push_back($1); $$->children.push_back($3);
    }
    | expr GE expr {
        if(exprflg != "integer" && exprflg != "real"){
             fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
             exit(EXIT_FAILURE);     
        }
        $$ = new ASTNode(exprflg, ">="); $$->children.push_back($1); $$->children.push_back($3);
    }
    | expr GT expr {
        if(exprflg != "integer" && exprflg != "real"){
             fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
             exit(EXIT_FAILURE);     
        }
        $$ = new ASTNode(exprflg, ">"); $$->children.push_back($1); $$->children.push_back($3);
    }
    | expr LT expr {
        if(exprflg != "integer" && exprflg != "real"){
             fprintf(stderr, "%d: Syntax error: Invalid operator for %s type\n", yylineno, exprflg.c_str());
             exit(EXIT_FAILURE);     
        }
        $$ = new ASTNode(exprflg, "<"); $$->children.push_back($1); $$->children.push_back($3);
    }
    ;

relativ_condition:
    relativ_condition AND relativ_condition  {  $$ = $1 && $3;}
    |  relativ_condition OR relativ_condition  {$$ = $1 || $3;}
    |  relativ_condition EQ relativ_condition  {$$ = ($1 == $3);}
    |  relativ_condition NQ relativ_condition  {$$ = ($1 != $3);}
    |  NOT relativ_condition  {$$ = !$2;}
    |  '(' relativ_condition ')' {$$ = $2; }
    |  relativ_expr { if ($1->evaluateAST() == "true") $$ = true;
                      else $$ = false; 
                      exprflg = "none"; }
    ;

%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

void checkVarDecl(const string& name,const string& type,const string& value, bool ct, const string& scope,int line){
    if(!variabile.declareVariable(name, type,ct,scope,line)){
            fprintf(stderr, "%d: Error: Variable '%s' is already defined\n",line, name.c_str());
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
        fprintf(stderr, "%d: Error: Constant '%s' can't be changed\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    if(variabile.IsDeclareVariable(name,value)==3){
        fprintf(stderr, "%d: Error: Variable '%s' is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE); }
    else if(variabile.IsDeclareVariable(name,value)==2){
        fprintf(stderr, "%d: Error: Invalid value for variable '%s'\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }
    variabile.assignValue(name,value);
    cout<< name<< " "<<" "<< value<<endl;
}


void declArr(const string& name, const string& type, vector<string> values , bool ct, const string& scope,int size, int line){
    for(const string& s: values){
        if(!variabile.isCompatibleValue(type,s)){
           fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),type.c_str());
           exit(EXIT_FAILURE); 
        }
    }
    if(!variabile.declareVariable(name, type,ct,scope,line)){
        fprintf(stderr, "%d: Error: Variable '%s' is already defined\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }

    if(values.size() > size){
        fprintf(stderr, "%d: Error: arr '%s' index exceeds size '%d'.\n",line, name.c_str(),size);
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

void checkArr(const string& name,const string& var_type, const string& value, int index, int line){
    if(!variabile.existsVar(name,var_type)){
        fprintf(stderr, "%d: Error: Variable '%s' is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    if(!variabile.isCompatibleValue(variabile.getType(name,"arr"),value)){
           fprintf(stderr, "%d: Error: Invalid value for variable '%s' of type %s\n",line, name.c_str(),variabile.getType(name,"arr").c_str());
           exit(EXIT_FAILURE); 
    }
    if(variabile.isConstant(name)){
        fprintf(stderr, "%d: Error: Constant '%s' can't be changed\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }
    variabile.assignValueArr(name, value, index, line);
}

void callFunction(const string&name, vector<string> args, int line){
    if(!variabile.isFunction(name)){
         fprintf(stderr, "%d: Error: Variable '%s' is not defined or is not a function\n",line, name.c_str());
         exit(EXIT_FAILURE);
    }
    variabile.checkArgs(name, args, line);
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

void verificareCorectitudineVal(const string& value, const string& type, int line){
    if(exprflg == "none"){
        exprflg = type;
    }
    else if(exprflg != type){
        // cout<<"Val "<< exprflg << " "<<type<<" linie: "<<line<<endl;
        fprintf(stderr, "%d: Syntax error: casting is not support\n",line);
        exit(EXIT_FAILURE);
    }
}

void verificareCorectitudineId(const string& id, const string& var_type, int line){
    if(!variabile.existsVar(id,var_type)){
        fprintf(stderr, "%d: Error: Variable '%s' is not defined\n",line, id.c_str());
        exit(EXIT_FAILURE);
    }
    string type = variabile.getType(id,var_type);
    if(exprflg == "none"){
        exprflg = type;
    }
    else if(exprflg != type){
        // cout<<"Id "<<exprflg<< "  "<<id<<"  " << type<<endl;
        fprintf(stderr, "%d: Syntax error: casting is not support\n",line);
        exit(EXIT_FAILURE);
    }
}
void verificareCorectitudineArray(const string& id, const string& var_type, int index, int line){
    if(!variabile.existsVar(id,var_type)){
        fprintf(stderr, "%d: Error: Variable '%s' is not defined\n",line, id.c_str());
        exit(EXIT_FAILURE);
    }
    
    string type = variabile.getArrayType(id,index,line);
    if(exprflg == "none"){
        
        exprflg = type;
    }
    else if(exprflg != type){
        // cout<<"Arr "<<exprflg<< "  "<<id<<"  " << type<<endl;
        fprintf(stderr, "%d: Syntax error: casting is not support\n",line);
        exit(EXIT_FAILURE);
    }
}
void verificareCorectitudineClassId(const string& class_name, const string& class_var, int line){
    if(!variabile.existsClassId(class_name,class_var)){
        fprintf(stderr, "%d: Error: Variable '%s~%s' is not defined\n",line, class_name.c_str(), class_var.c_str());
        exit(EXIT_FAILURE);
    }
    string type = variabile.getType(class_var,"var");
    if(exprflg == "none"){
        exprflg = type;
    }
    else if(exprflg != type){
        // cout<<"Cl "<<exprflg<< "  "<<class_name<<"."<< class_var<<"  " << type<<endl;
        fprintf(stderr, "%d: Syntax error: casting is not support\n",line);
        exit(EXIT_FAILURE);
    }
}

string getFuncValue(const string& id){
    const string type = variabile.getType(id,"function");
    if(type == "integer") return "12";
    else if(type == "real") return "12.0";
    else if(type == "boolean") return "true";
    else if(type == "string") return "\"sir\"";
    return "\'c\'";
}


void initTable() {
     FILE *file = fopen(FILE_NAME, "a");
       if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }
    fprintf(file, 
    "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s %-20s",
    "ID","TIP","VAL", "SCOPE","Location","Var_Type", "Function params");
    fprintf(file, "\n");
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
