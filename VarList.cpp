#include "VarList.h"

using namespace std;


void VarList::checkSyntax(){
    int i_counter = 0;
    for(const Var& i: vars){
        int j_counter = 0;
        for(const Var& j: vars){
            if(i.name == j.name && i.scope==j.scope && i_counter!=j_counter ){
                fprintf(stderr, "%d: Error: '%s' is already defined\n",j.linie, j.name.c_str());
                exit(EXIT_FAILURE);
            }
            j_counter++;
        }
        i_counter++;
    }
}

string getArrValues(vector<string> arr) {
    string result;

    for (const auto& element : arr) {
        result = result + element + " ";
    }
    // cout<<result<<endl;

    return result;
}


bool VarList::declareVariable(const string& name,const string& type, bool ct, const string& scope,int line){
    // for(const Var& v: vars){
    //     if(name == v.name && v.scope==scope) {
    //         return false;
    //     }
    // }
    string location_type = scope=="main" ? "global" : scope;
    Var i = {"var",type,name,ct,scope,location_type,"", line};
    vars.push_back(i); 
    
    return true;  
}

bool VarList::declareArr(const string& name,const string& type, bool ct, const string& scope, int line){
    // for(const Var& v: vars){
    //     if(name == v.name && v.scope==scope) {
    //         return false;
    //     }
    // }
    string location_type = scope=="main" ? "global" : scope;
    Var i = {"arr",type,name,ct,scope,location_type};
    vars.push_back(i); 
    
    return true;  
}

void VarList::initClassData(const string& name, const string& type, int line){
    for(const Var& v: vars){
        if(type == v.location_type) {   
            Var i = {v.var_type, v.type, v.name, v.constant, name, "class",v.value, line, v.arr,v.arrSize};
            vars.push_back(i);   
        }
    }
}

void VarList::assignClassEl(const string& class_name, const string& class_var, const string& val, int line) {
    bool exist = false;
    for(Var& v: vars){
        if(class_name == v.scope && class_var == v.name) {
            exist = true;
            if(!isCompatibleValue(v.type,val)){
                fprintf(stderr, "%d: Error: Invalid value for variable of type %s\n",line, v.type.c_str());
                exit(EXIT_FAILURE); 
            }
            if(isConstant(class_var)){
                fprintf(stderr, "%d: Error: Constant '%s' can't be changed\n",line, class_var.c_str());
                exit(EXIT_FAILURE);
            }
        v.value = val;
        }    
    }
    if(!exist){
        fprintf(stderr, "%d: Error: Variable '%s~%s' is not defined\n",line, class_name.c_str(),class_var.c_str());
        exit(EXIT_FAILURE); 
    }
}

string VarList::getArrayType(const string& name, int index,int line){
    bool exist = false;
    for(Var& v: vars){
        if(name == v.name) {
            if(v.var_type != "arr"){
                fprintf(stderr, "%d: Error: Variable %s is not an array\n",line, v.name.c_str());
                exit(EXIT_FAILURE); 
            }
            if(v.arr.size() <= index){
                fprintf(stderr, "%d: Error: Invalid index of array '%s'\n",line, v.name.c_str());
                exit(EXIT_FAILURE); 
            }
            exist = true;
            return v.type;
        }    
    }
    if(!exist){
        fprintf(stderr, "%d: Error: Array '%s' is not defined\n",line, name.c_str());
        exit(EXIT_FAILURE); 
    }
    return "";
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
    // cout<<"ajunge\n";
    int len = args.size();
    int count = 0;
    for(const Var& v:vars){
        if(v.location_type=="func_param" && v.scope==name) {
            count++;
            if(!isCompatibleValue(v.type,args.back())){
                fprintf(stderr, "%d: Error: Invalid value for param '%s' of type %s\n",line,v.name.c_str(), v.type.c_str());
                exit(EXIT_FAILURE);
            }
            // cout << v.name << " " << args.back()<< endl; 
            args.pop_back();
        }
    }
    if(len!=count){
        fprintf(stderr, "%d: Error: Invalid call function '%s'\n",line, name.c_str());
        exit(EXIT_FAILURE);
    }

}

bool VarList::existsVar(const string& name, const string& var_type){
    for(const Var& v: vars){
        if(name == v.name && var_type == v.var_type) {
            return true;
        }
    }
    return false; 
}

bool VarList::existsClassId(const string& class_name, const string& class_var){
    for(const Var& v: vars){
        if(class_var == v.name && class_name == v.scope) {
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

string VarList::getArrayValue(const string& name, int index){
    for (Var& v : vars) {
        if (name == v.name) {
            return v.arr[index];
        }
    }
    return "";
}

string VarList::getClassIdValue(const string& class_name, const string& class_var){
     for (Var& v : vars) {
        if (class_var == v.name && class_name == v.scope) {
            return v.value;
        }
    }
    return "";
}

string VarList::getType(const string& name,const string& var_type){
    for (Var& v : vars) {
        if (name == v.name && v.var_type==var_type) {
            return v.type;
        }
    }
    return "";
}

void VarList::addValuesToArr(const string& name, vector<string> values, int size){

    for(Var& v: vars){
       if (name == v.name) {
            v.arrSize = size;
            v.var_type="arr";
            for(const string& s: values){
                v.arr.push_back(s);
                // cout << s <<" ";
            }
        } 
    }
    // cout<<endl;
}
void VarList::assignValueArr(const string& name,const string& value, int index, int line){
    for (Var& v : vars) {
    if (name == v.name) {
        // cout << name << " " << index << " " << v.arrSize << endl;
        if (v.arrSize < index) {
            fprintf(stderr, "%d: Error: arr index '%d' out of bounds.\n", line, index);
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
        cout <<name<<"["<<index<<"]"<<" "<< value << endl;
    }
    }
 
}

void VarList::addVarToTable(){
     FILE *file = fopen("table.txt", "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
    }

 for (Var& v : vars) {
    if((v.location_type!="func_param" && v.var_type!="class") &&( v.location_type=="global" || v.location_type=="class") && v.var_type!="function") {
        if( v.arrSize ==0) {
            fprintf(file, "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s\n", 
            v.name.c_str(),v.type.c_str(),v.value.c_str(), v.scope.c_str(), v.location_type.c_str(), v.constant ? "constant" : v.var_type.c_str());
        }
        else {
            fprintf(file, "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s\n", 
            v.name.c_str(),v.type.c_str(),getArrValues(v.arr).c_str(), v.scope.c_str(), v.location_type.c_str(), v.constant ? "constant" : v.var_type.c_str());
        }

    }
 }
 for (Var& v : vars) {
    if((v.location_type!="func_param" && v.var_type!="class") &&( v.location_type=="global" || v.location_type=="class") && v.var_type=="function") {
        if( v.arrSize ==0) {
            fprintf(file, "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s", 
            v.name.c_str(),v.type.c_str(),v.value.c_str(), v.scope.c_str(), v.location_type.c_str(), v.constant ? "constant" : v.var_type.c_str());
        }
        else {
            fprintf(file, "%-20s        %-20s      %-20s        %-20s            %-20s         %-20s", 
            v.name.c_str(),v.type.c_str(),getArrValues( v.arr).c_str(), v.scope.c_str(), v.location_type.c_str(), v.constant ? "constant" : v.var_type.c_str());
        }

    for (Var& param : vars) {
        if(param.location_type=="func_param" && param.scope==v.name ) {
            fprintf(file, "%s:%s ", 
            param.name.c_str(), param.type.c_str()
            );        
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
        // cout<<count<< " "<<i->name<<" "<< i->scope<<endl;
        count--;
        i--;
        if(count>0 && i == vars.begin()){
            i->scope = scope;
            // cout<<count<< " "<<i->name<<" "<< i->scope<<endl;
            count--;
        }
    } 
    
}
void VarList::addLocationType(int count, const string& location){
    vector<Var>::iterator i = vars.end();
    i--;
    while (i != vars.begin() && count > 0)
    {
        if(i->location_type != "func_param"){
            i->location_type = location;
            count--;
        }
        // cout<<"clasa: "<<count<< " "<<i->name<<" "<<i->scope<<" "<< i->location_type<<endl;
        i--;
        if(count > 0 && i == vars.begin()){
            if(i->location_type != "func_param"){
                i->location_type = location;
                count--;
            }
        // cout<<"Clasa: "<<count<< " "<<i->name<<" "<<i->scope<<" "<< i->location_type<<endl;
        }
    } 
    
}

bool VarList::declareFunc(const string& name,const string& type,const string& scope,int line){
    // for(const Var& v: vars){
    //     if(name == v.name) {
    //         return false;
    //     }
    // }
    string location_type = scope=="main" ? "global" : scope;
    Var i = {"function",type,name,false,scope,"global","",line};//update location_type (class implementation)
    vars.push_back(i); 
    
    return true;  
}

bool VarList::declareClass(const string& name){
    for(const Var& v: vars){
        if(name == v.name && v.var_type=="class") {
            return false;
        }
    }
    Var i = {"class",name, name, false,"main","global"}; //update location_type (class implementation)
    vars.push_back(i); 
    
    return true;  
}

VarList::~VarList() {
    vars.clear();
}


//Helpers
