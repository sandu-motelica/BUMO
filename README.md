## Custom Programming Language using YACC/BISON


### Overview

This project implements a custom-designed programming language named **BUMO** using **YACC/BISON** for grammar parsing and **C++** for symbol management and semantic analysis. The language supports features such as predefined types, classes, arrays, function definitions, and control statements. This repository contains all necessary files and scripts to compile and run programs written in **BUMO**.

---

### Features

#### 1. Syntax Specifications
- **Predefined Types**: `integer`, `real`, `char`, `string`, `boolean`.
- **Array Support**: Enables the creation and usage of array types.
- **Classes**:
  - Syntax for defining and initializing objects.
  - Specific syntax for accessing fields and methods.
  - Classes can only be defined in the global scope.
- **Control Statements**: `if`, `for`, `while`.
- **Functions**: 
  - Custom function definitions.
  - Two predefined functions:
    - `Eval(expr)`: Evaluates an expression and prints its result.
    - `TypeOf(expr)`: Prints the type of the given expression.
- **Assignments**:
  - Supports assignments with identifiers, array elements, and class members.
- **Expressions**:
  - Includes arithmetic and Boolean expressions.
  - Supports `true` and `false` as Boolean values.

---

#### 2. Symbol Tables
The **BUMO** compiler uses symbol tables to manage variable, function, and class scopes:
- **Global Scope**: Includes all global variables, classes, and functions.
- **Block Scope**: Created by control statements (`if`, `for`, `while`).
- **Function Scope**: Introduced by each function definition.
- **Class Scope**: Defined for each class.

The symbol table implementation ensures:
- Variables and functions are declared before use.
- No duplicate declarations within the same scope.
- Operands in expressions and assignments match the expected types.
- Function arguments conform to parameter types.

---

#### 3. Semantic Analysis
The compiler performs semantic checks:
- Validates that all variables and functions are declared before use.
- Ensures no duplicate variable declarations in the same scope.
- Confirms type consistency for expressions and assignments.
- Validates that function call arguments match the expected parameter types.

---

#### 4. Abstract Syntax Trees (AST)
- **AST Nodes**: Represent expressions and store their types and values.
- **AST Evaluations**: Compute values and validate types for expressions and assignments.

The compiler uses AST evaluations for:
- Expression computation (e.g., `Eval(expr)`).
- Type validation (e.g., `TypeOf(expr)`).
- Detecting errors in invalid assignments.

---

### Files in the Repository
- **Grammar Files**:
  - `bumo.y`: YACC/BISON grammar definition file for parsing the syntax of **BUMO**.
  - `bumo.l`: Lexical analyzer using Flex, handling token generation for the parser.
- **Source Files**:
  - `VarList.cpp` and `VarList.h`: Manage symbol tables and variable handling in **BUMO**.
  - `lex.yy.c`: Auto-generated lexical analyzer file by Flex.
- **Input and Output**:
  - `input.txt`: Example input program in the **BUMO** language.
  - `table.txt`: Output file containing symbol table details after parsing.
- **Utility Scripts**:
  - `compile.sh`: Script to compile the **BUMO** compiler.

---

### Usage

#### Compilation
To compile the project, run the following command:
```bash
./compile.sh bumo
```

#### Running the Program
1. Write your program in `input.txt`.
2. Execute the compiled binary:
   ```bash
   ./bumo < input.txt
   ```

#### Output
- Compilation errors or success messages are displayed in the console.
- The symbol table is saved in `table.txt`.

---

### Example Program (input.txt)
```plaintext
program MyProgram;
types:
class MyType
begin
  vars:
    x:integer;
    y:integer;
  methods:
    function add(a:integer, b:integer):integer
    begin
      return a + b;
    end;
end;

vars:
gix:integer := 5;

functions:
function add_global(a:integer, b:integer):integer
begin
  return a + b;
end;

begin
  Eval(add_global(5, gix));
  TypeOf(gix);
end.
```

---

### Error Handling
- **Undeclared Variables**: Reports an error when variables or functions are used without prior declaration.
- **Duplicate Declarations**: Reports duplicate variable or function declarations in the same scope.
- **Type Mismatches**: Reports mismatched types in expressions or assignments.
- **Invalid Function Calls**: Reports mismatches between provided arguments and expected parameters.

---

### Contributions
This project demonstrates compiler design principles, including grammar parsing, semantic analysis, and AST evaluation. It was developed as an educational project for a Formal Langauges, Automata and Compilers course.

