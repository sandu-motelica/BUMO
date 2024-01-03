#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Var {
    string var_type;//var | func | class
    string type;//int | string | floar | boolean
    string name;
    bool constant;
    string scope;
    string location_type;
    string value;  
};

class VarList {
    private:
    vector<Var> vars;
   
    public:
    bool declareVariable(const string& name,const string& type,bool constant,const string& scope);
    bool declareFunc(const string& name,const string& type,const string& scope);
    bool isCompatibleValue(const string& type, const string& value);
    int IsDeclareVariable(const string& name, const string& value);
    void assignValue(const string& name, const string& value);
    void addVarToTable();
    void addScope(const string& scope);
    bool existsVar(const string& name);
    string getValue(const string& name);
    string getType(const string& name);
    bool isConstant(const string& name);
    ~VarList();
};

