#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>  

using namespace std;



class ASTNode {
public:
    string type;
    string value;
    vector<ASTNode*> children;

    ASTNode(string t, string val) : type(t), value(val) { }
    string evaluateAST() {
            if (this->value == "+") {
                if(this->type == "integer"){
                    int stanga = stoi(children[0]->evaluateAST());
                    int dreapta = stoi(children[1]->evaluateAST());
                    int res = stanga + dreapta;
                    return to_string(res);
                }
                else{
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    float res = stanga + dreapta;
                    return to_string(res);
                } 
            }
            else if (this->value == "-") {
                if(children[1] == nullptr){
                         string temp = children[0]->evaluateAST();
                         string res = "-" + temp;
                         return res;
                }
                if(this->type == "integer"){
                    int stanga = stoi(children[0]->evaluateAST());
                    int dreapta = stoi(children[1]->evaluateAST());
                    int res = stanga - dreapta;
                    return to_string(res);
                }
                else{
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    float res = stanga - dreapta;
                    return to_string(res);
                } 
            }
            else if (this->value == "*") {
                if(this->type == "integer"){
                    int stanga = stoi(children[0]->evaluateAST());
                    int dreapta = stoi(children[1]->evaluateAST());
                    int res = stanga * dreapta;
                    return to_string(res);
                }
                else{
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    float res = stanga * dreapta;
                    return to_string(res);
                } 
            }
            else if (this->value == "/") {
                if(this->type == "integer"){
                    int stanga = stoi(children[0]->evaluateAST());
                    int dreapta = stoi(children[1]->evaluateAST());
                    int res = stanga / dreapta;
                    return to_string(res);
                }
                else{
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    float res = stanga / dreapta;
                    return to_string(res);
                } 
            }
            else if (this->value == "%%") {
                    int stanga = stoi(children[0]->evaluateAST());
                    int dreapta = stoi(children[1]->evaluateAST());
                    int res = stanga % dreapta;
                    return to_string(res); 
            }  
            else if (this->value == "&&") {
                    bool stanga, dreapta, res;
                    if(children[0]->evaluateAST() == "true") stanga = true;
                    else stanga = false; 
                    if(children[1]->evaluateAST() == "true") dreapta = true;
                    else dreapta = false; 
                    res = stanga && dreapta;
                    return res? "true" : "false"; 
            }  
            else if (this->value == "||") {
                    bool stanga, dreapta, res;
                    if(children[0]->evaluateAST() == "true") stanga = true;
                    else stanga = false; 
                    if(children[1]->evaluateAST() == "true") dreapta = true;
                    else dreapta = false; 
                    res = stanga || dreapta;
                    return res? "true" : "false"; 
            }  
            else if (this->value == "!") {
                    bool stanga, res;
                    if(children[0]->evaluateAST() == "true") stanga = true;
                    else stanga = false;  
                    return stanga ? "false" : "true"; 
            }  
            else if (this->value == "<=") {
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    bool res = (stanga <= dreapta);
                    return res ? "true" : "false";
            }
            else if (this->value == ">=") {
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    bool res = (stanga >= dreapta);
                    return res ? "true" : "false";
            }
            else if (this->value == "<") {
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    bool res = (stanga < dreapta);
                    return res ? "true" : "false";
            }
            else if (this->value == ">") {
                    float stanga = stof(children[0]->evaluateAST());
                    float dreapta = stof(children[1]->evaluateAST());
                    bool res = (stanga > dreapta);
                    return res ? "true" : "false";
            }
            else if (this->value == "==") {
                string stanga = children[0]->evaluateAST();
                string dreapta = children[1]->evaluateAST();
                bool res = (stanga == dreapta);
                return res ? "true" : "false";
            }
            else if (this->value == "!=") {
                string stanga = children[0]->evaluateAST();
                string dreapta = children[1]->evaluateAST();
                bool res = (stanga != dreapta);
                return res ? "true" : "false";
            }
            else   return this->value;
    }
    string getTypeof(){
        if(children[0]->getTypeof()!=children[1]->getTypeof()){
             return nullptr;
        }
        else return this->type;
    }
};


struct Var {
    string var_type; // var | func | class | arr
    string type; // int | string | floar | boolean
    string name;
    bool constant;
    string scope;
    string location_type;
    string value;  
    int linie;
    vector<string> arr;
    int arrSize;
};

class VarList {
    private:
    vector<Var> vars;
   
    public:
    bool declareVariable(const string& name,const string& type,bool constant,const string& scope,int line);
    bool declareArr(const string& name,const string& type,bool constant,const string& scope, int line);
    void initClassData(const string& name,const string& type, int line);
    bool declareFunc(const string& name,const string& type,const string& scope, int line);
    bool declareClass(const string& name);
    bool isCompatibleValue(const string& type, const string& value);
    int IsDeclareVariable(const string& name, const string& value);
    void assignValue(const string& name, const string& value);
    void addValuesToArr(const string& name, vector<string> values, int size);
    void assignValueArr(const string& name,const string& value, int index, int line);
    bool isFunction(const string& name);
    string getArrayType(const string& name, int index,int line);
    string getArrayValue(const string& name, int index);
    void assignClassEl(const string& class_name,const string& class_var, const string& value, int line);
    bool existsClassId(const string& class_name, const string& class_var);
    void checkArgs(const string& name, vector<string> args,int line);
    void addVarToTable();
    void addScopeParams(const string& scope);
    void addScopeVars(int count, const string& scope);
    void addLocationType(int count, const string& location);
    bool existsVar(const string& name,const string& var_type);
    string getValue(const string& name);
    string getClassIdValue(const string& class_name, const string& class_var);
    string getType(const string& name, const string& var_type);
    bool isConstant(const string& name);
    void checkSyntax();
    ~VarList();
};

