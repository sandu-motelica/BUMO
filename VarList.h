#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Var {
    string type;
    string name;
    bool constant;
    string scope;
    string value;  
};

class VarList {
    private:
    vector<Var> vars;
   
    public:
    bool declareVariable(const string& name,const string& type,bool constant);
    bool isCompatibleValue(const string& type, const string& value);
    int IsDeclareVariable(const string& name, const string& value);
    void assignValue(const string& name, const string& value);
    void addVarToTable();
    string getValue(const string& name);
    bool isConstant(const string& name);
    ~VarList();
};

