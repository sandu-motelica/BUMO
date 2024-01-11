#include "VarList.h"

using namespace std;


bool VarList::declareVariable(const string& name,const string& type, bool ct, const string& scope){
    for(const Var& v: vars){
        if(name == v.name) {
            return false;
        }
    }
    string location_type = scope=="main" ? "global" : scope;
    Var i = {"var",type,name,ct,scope,location_type};
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
        // cout<<type<<" "<<value<<endl;
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

bool VarList::isFunction(const string& name){
    for(const Var& v: vars){
        if(v.name==name && v.var_type=="function"){
            return true;
        }
    }
    return false;
}

void VarList::checkArgs(const string& name, vector<string> args,int line){
    reverse(args.begin(),args.end());
    cout<<"ajunge\n";
    int len = args.size();
    int count = 0;
    for(const Var& v:vars){
        if(v.location_type=="func_param" && v.scope==name) {
            count++;
            if(!isCompatibleValue(v.type,args.back())){
                fprintf(stderr, "%d: Error: Invalid value for param '%s' of type %s\n",line,v.name.c_str(), v.type.c_str());
                exit(EXIT_FAILURE);
            }
            cout << v.name << " " << args.back()<< endl; 
            args.pop_back();
        }
    }
    if(len!=count){
        fprintf(stderr, "%d: Error: Invalid call function '%s'\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }

}

bool VarList::existsVar(const string& name){
    for(const Var& v: vars){
        if(name == v.name) {
            return true;
        }
    }
    return false; 
}

void VarList::assignValue(const string& name, const string& value){
    for (Var& v : vars) {
        if (name == v.name) {
            v.value = value;
        }
    }
}
string VarList::getValue(const string& name){
    for (Var& v : vars) {
        if (name == v.name) {
            return v.value;
        }
    }
    return "";
}
string VarList::getType(const string& name){
    for (Var& v : vars) {
        if (name == v.name) {
            return v.type;
        }
    }
    return "";
}

void VarList::addValuesToArr(const string& name, vector<string> values, int size){

    for(Var& v: vars){
       if (name == v.name) {
            v.arrSize = size;
            v.var_type="array";
            for(const string& s: values){
                v.arr.push_back(s);
                cout << s <<" ";
            }
        } 
    }
    cout<<endl;
}
void VarList::assignValueArr(const string& name,const string& value, int index, int line){
    for (Var& v : vars) {
    if (name == v.name) {
        cout << name << " " << index << " " << v.arrSize << endl;
        if (v.arrSize < index) {
            fprintf(stderr, "%d: Error: Array index '%d' out of bounds.\n", line, index);
            exit(EXIT_FAILURE);
        }
        if (v.arr.size() < index) {
            fprintf(stderr, "%d: Error: Maximum possible index of assign is '%ld'.\n", line, v.arr.size());
            exit(EXIT_FAILURE);
        }
        if (v.arr.size() == index) {
            v.arr.push_back(value);
        } else {
            v.arr[index] = value;
        }
        for (const string& s : v.arr)
            cout << s << " ";
    }
}
    cout<<endl;
}

void VarList::addVarToTable(){
     FILE *file = fopen("table.txt", "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }

 for (Var& v : vars) {
    if(v.location_type!="func_param") {
        fprintf(file, "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s", 
        v.name.c_str(),v.type.c_str(),v.value.c_str(), v.scope.c_str(), v.location_type.c_str(), v.constant ? "constant" : v.var_type.c_str());
        //Print function params

 for (Var& param : vars) {
    if(param.location_type=="func_param" && param.scope==v.name) {
        fprintf(file, "%s:%s ", 
        param.name.c_str(), param.type.c_str()
        );
        //Print function params
    
    }
    }
        fprintf(file, "\n");
    }
    }
    fclose(file);
}





void VarList::addScopeParams(const string& scope){
       for (Var& v : vars) {
        if (v.scope=="func_param") {
            v.scope = scope;
        }
    }
}

void VarList::addScopeVars(int count, const string& scope){
    vector<Var>::iterator i = vars.end();
    i--;
    while (i != vars.begin() && count > 0)
    {
        i->scope = scope;
        cout<<count<< " "<< i->scope<<endl;
        count--;
        i--;
    } 
}

bool VarList::declareFunc(const string& name,const string& type,const string& scope){
    for(const Var& v: vars){
        if(name == v.name) {
            return false;
        }
    }
    string location_type = scope=="main" ? "global" : scope;
    Var i = {"function",type,name,false,scope,"location_type"};//update location_type (class implementation)
    vars.push_back(i); 
    
    return true;  
}

VarList::~VarList() {
    vars.clear();
}
