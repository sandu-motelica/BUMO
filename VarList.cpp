#include "VarList.h"
using namespace std;


bool VarList::declareVariable(const string& name,const string& type){
    for(const Var& v: vars){
        if(name == v.name) {
            return false;
        }
    }
    Var i = {type,name};
    vars.push_back(i); 
    return true;  
}
bool VarList::isCompatibleValue(const string& type, const string& value) {
    cout<<type<<" "<<value<<endl;
    if (type == "integer") {
        // Verificare pentru tipul INTEGER
        try {
            std::stoi(value);
            return true;
        } catch (...) {
            return false;
        }
    } else if (type == "real") {
        // Verificare pentru tipul REAL
        try {
            std::stod(value);
            return true;
        } catch (...) {
            return false;
        }
    } else if (type == "boolean") {
        // Verificare pentru tipul BOOLEAN
        return (value == "true" || value == "false");
    } else if (type == "char") {
        if(value[0]=='\'' && value[value.length()-1]=='\'' && value.length() < 4 && value.length() > 1){
            return true;
        }
        return false;
    }else if(type == "string"){
        if(value[0]=='"' && value[value.length()-1]=='"' && value.length() > 1){
            return true;
        }
        return false;
    }
    return false;
}


bool VarList::assignValue(const string& name, const string& value){
    for (Var& v : vars) {
        if (name == v.name) {
            if (isCompatibleValue(v.type, value)) {
                // Atribuie valoarea
                // cout << "Variable " << name << " assigned value " << value << endl;
                return true;
            } else {
                cerr << "Incompatible value for variable " << name << " with type " << v.type << endl;
                return false;
            }
        }
    }

    cerr << "Variable " << name << " not declared!" << endl;
    return false;
}

// void IdList::addVar(const char* type, const char*name) {
//     IdInfo var = {string(type), string(name)};
//     vars.push_back(var);
// }


// bool IdList::existsVar(const char* var) {
//     string strvar = string(var);
//      for (const IdInfo& v : vars) {
//         if (strvar == v.name) { 
//             return true;
//         }
//     }
//     return false;
// }

// void IdList::printVars() {
//     for (const IdInfo& v : vars) {
//         cout << "name: " << v.name << " type:" << v.type << endl; 
//      }
// }



VarList::~VarList() {
    vars.clear();
}

