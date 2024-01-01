#include "VarList.h"
using namespace std;


bool VarList::declareVariable(const string& name,const string& type, bool ct){
    for(const Var& v: vars){
        if(name == v.name) {
            return false;
        }
    }
    Var i = {type,name,ct};
    vars.push_back(i); 
    
    return true;  
}

int VarList::IsDeclareVariable(const string& name, const string& value){
    for(const Var& v: vars){
        if(name == v.name) {
            if(isCompatibleValue(v.type,value))
                return 1;
            else return 2;
        }
    }
    return 3;  
}
bool VarList::isCompatibleValue(const string& type, const string& value) {
        cout<<type<<" "<<value<<endl;
    if (type == "integer") {
        // Verificare pentru tipul INTEGER
        try {
            size_t pos;
            stoi(value, &pos);
            return pos == value.length();
        } catch (...) {
            return false;
        }
    } else if (type == "real") {
        // Verificare pentru tipul REAL
        try {
            size_t pos1,pos2;
            stod(value, &pos1);
            stoi(value, &pos2);
            return pos1 != pos2;
        } catch (...) {
            return false;
        }
    } else if (type == "boolean") {
        // Verificare pentru tipul BOOLEAN
        return (value == "true" || value == "false");
    } else if (type == "char") {
        // Verificare pentru tipul CHAR
        if(value[0]=='\'' && value[value.length()-1]=='\'' && value.length() < 4 && value.length() > 1){
            return true;
        }
        return false;
    }else if(type == "string"){
        // Verificare pentru tipul STRING
        if(value[0]=='"' && value[value.length()-1]=='"' && value.length() > 1){
            return true;
        }
        return false;
    }
    return false;
}

bool VarList::isConstant(const string& name){
    for(const Var& v: vars){
        if(v.name==name){
            return v.constant;
        }
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

VarList::~VarList() {
    vars.clear();
}

