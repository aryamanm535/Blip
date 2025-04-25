# Blip
A Programming Language Made With C++
The Blip language supports basic variable assignment, arithmetic and logical expressions, and output statements. This project demonstrates parsing, memory management, and expression evaluation in C++.

*Work-in-progress*
Currently working on integrating loops and ADTs.

# Features
Variable Assignment & Initialization: Supports var and set statements for creating and updating variables.

Expression Parsing: Evaluates arithmetic, logic, and comparison expressions in prefix notation.

Output: Displays integer results and text messages via the output and text commands.

Error Handling: Provides error messages for uninitialized variables, duplicate assignments, and invalid expressions.

Data Structures
Symbol Table: Utilizes maps to store variables and their values.

Expression Parsing: Implements recursion and stacks to evaluate prefix expressions efficiently.

# Requirements
C++ compiler (C++11 or higher)

Understanding of C++ and recursion

# Usage
Clone this repository.

Compile the C++ files.

Create a .blip program file with valid Blip code.

Run the interpreter.

bash
Copy
g++ main.cpp -o blip_interpreter
./blip_interpreter test_grader.blip
Example
Blip Code (test.blip):

arduino
Copy
text "Hello, World!"
var x 5
set x + x 10
output x
Output:

Copy
Hello, World!
15
