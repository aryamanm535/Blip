#include <iostream>
#include <string>
#include "Parse.h"
#include "database.h"
#include "BST.h"  
#include "Input.cpp"

BST symbolTable;  

bool isOperator(const std::string& op) {
    static const std::string ops[] = {
        "+", "-", "*", "/", "%", "&&", "||", "<", ">", "==",
        "!=", "<=", ">=", "!", "~"
    };
    for (const auto& o : ops)
        if (o == op) return true;
    return false;
}

bool isKeyword(const std::string& word) {
    return word == "text" || word == "output" || word == "var" || word == "set" || word == "//";
}

bool isNumeric(const std::string& token) {
    for (char c : token)
        if (!isdigit(c)) return false;
    return true;
}

int evaluateExpression() {
    std::string tokens[128];
    int count = 0;

    read_next_token();
    std::string token = next_token();

    while (next_token_type != END && !isKeyword(token)) {
        if (!isNumeric(token) && !isOperator(token)) {
            if (symbolTable.variableExists(token)) {
                token = std::to_string(symbolTable.getValue(token));
            } else {
                token = "0";  
            }
        }

        tokens[count++] = token;

        std::string peek = peek_next_token();
        if (next_token_type == END || isKeyword(peek)) break;

        read_next_token();
        token = next_token();
    }

    db evaluator(tokens, count);
    return evaluator.calculate();
}

void handleText() {
    read_next_token();  
    std::cout << next_token();
}

void handleOutput() {
    int result = evaluateExpression();
    std::cout << result;
}

void handleVar() {
    read_next_token();
    std::string varName = next_token();

    if (symbolTable.variableExists(varName)) {
        std::cout << "variable " << varName << " incorrectly re-initialized\n";
        symbolTable.changeValue(varName, evaluateExpression());
    } else {
        symbolTable.insert(varName, evaluateExpression());
    }
}

void handleSet() {
    read_next_token();
    std::string varName = next_token();

    if (!symbolTable.variableExists(varName)) {
        std::cout << "variable " << varName << " not declared\n";
        symbolTable.insert(varName, evaluateExpression());  // still create it
    } else {
        symbolTable.changeValue(varName, evaluateExpression());
    }
}

void run() {
    while (true) {
        read_next_token();
        if (next_token_type == END) break;

        std::string command = next_token();

        if (command == "//") {
            skip_line();
        } else if (command == "text") {
            handleText();
        } else if (command == "output") {
            handleOutput();
        } else if (command == "var") {
            handleVar();
        } else if (command == "set") {
            handleSet();
        }
    }
}
