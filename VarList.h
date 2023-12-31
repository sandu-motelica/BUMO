#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
struct Var {
    string type;
    string name;
};

class VarList {
    private:
    vector<Var> vars;
   
    public:
    bool declareVariable(const string& name,const string& type);
    bool isCompatibleValue(const string& type, const string& value);
    bool assignValue(const string& name, const string& value);
    ~VarList();
};
