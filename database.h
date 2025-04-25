#ifndef DATABASE_H
#define DATABASE_H

#include "Project8.h"
#include <iostream>
#include <string>
#include <stack>

class db {
private:
    std::string* tokens;
    int size;

    bool isOperator(const std::string& str) {
        return str == "+" || str == "-" || str == "*" || str == "/" || str == "%" ||
               str == "&&" || str == "||" || str == "<" || str == ">" || str == "==" ||
               str == "!=" || str == "<=" || str == ">=" || str == "!" || str == "~";
    }

    bool isUnary(const std::string& str) {
        return str == "!" || str == "~";
    }

    int applyOperator(const std::string& op, int left, int right = 0) {
        if (op == "+") return left + right;
        if (op == "-") return left - right;
        if (op == "*") return left * right;
        if (op == "/") return left / right;
        if (op == "%") return left % right;
        if (op == "&&") return left && right;
        if (op == "||") return left || right;
        if (op == "<") return left < right;
        if (op == ">") return left > right;
        if (op == "<=") return left <= right;
        if (op == ">=") return left >= right;
        if (op == "==") return left == right;
        if (op == "!=") return left != right;
        if (op == "!") return !left;
        if (op == "~") return -left;
        return 0;
    }

public:
    db(std::string inputTokens[], int tokenCount) {
        size = tokenCount;
        tokens = inputTokens; 
    }

    int calculate() {
        std::stack<int> st;

        for (int i = size - 1; i >= 0; --i) {
            const std::string& tok = tokens[i];

            if (!isOperator(tok)) {
                st.push(std::stoi(tok));
            } else {
                if (isUnary(tok)) {
                    if (st.empty()) return 0;  
                    int operand = st.top(); st.pop();
                    st.push(applyOperator(tok, operand));
                } else {
                    if (st.size() < 2) return 0; 
                    int left = st.top(); st.pop();
                    int right = st.top(); st.pop();
                    st.push(applyOperator(tok, left, right));
                }
            }
        }

        return st.empty() ? 0 : st.top();
    }
};

#endif
