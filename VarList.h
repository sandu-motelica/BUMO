#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
struct Var {
    string name;
    string type;
    bool constant;
    string scope;  // "main", numele funcției sau numele clasei în care este declarată variabila
};

struct Func {
    string name;
    string returnType;
    vector<pair<string, string>> parameters;  // (paramName, paramType)
};

struct Class {
    string name;
    vector<Var> variables;
    vector<Func> methods;
};

class VarList {
    private:
    vector<Var> vars;
    vector<Func> functions;
    vector<Class> classes;
    string currentScope;
   
    public:
    // VarList(const string& name){
    //     currentScope = name;
    // }
    void addFunction(const string& name,const string& type,vector<pair<string, string>> parameters){
        Func temp = {name,type,parameters};
        functions.push_back(temp);
    }
    bool declareVariable(const string& name,const string& type,bool constant);
    bool isCompatibleValue(const string& type, const string& value);
    int IsDeclareVariable(const string& name, const string& value);
    bool assignValue(const string& name, const string& value);
    bool isConstant(const string& name);
    ~VarList();
};

