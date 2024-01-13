#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>  

using namespace std;

struct Var {
    string var_type; // var | func | class | arr
    string type; // int | string | floar | boolean
    string name;
    bool constant;
    string scope;
    string location_type;
    string value;  
    vector<string> arr;
    int arrSize;
};

class VarList {
    private:
    vector<Var> vars;
   
    public:
    bool declareVariable(const string& name,const string& type,bool constant,const string& scope);
    void initClassData(const string& name,const string& type);
    bool declareFunc(const string& name,const string& type,const string& scope);
    bool declareClass(const string& name);
    bool isCompatibleValue(const string& type, const string& value);
    int IsDeclareVariable(const string& name, const string& value);
    void assignValue(const string& name, const string& value);
    void addValuesToArr(const string& name, vector<string> values, int size);
    void assignValueArr(const string& name,const string& value, int index, int line);
    bool isFunction(const string& name);
    void checkClassIsDecl(const string& class_name,const string& class_var, string& value, int line);
    void checkArgs(const string& name, vector<string> args,int line);
    void addVarToTable();
    void addScopeParams(const string& scope);
    void addScopeVars(int count, const string& scope);
    void addLocationType(int count, const string& location);
    bool existsVar(const string& name);
    string getValue(const string& name);
    string getType(const string& name);
    bool isConstant(const string& name);
    ~VarList();
};

