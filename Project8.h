#ifndef PA8
#define PA8

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "database.h"
#include "Parse.h"

void run();  

bool isKeyword(const std::string& word);
bool isNumeric(const std::string& token);
bool isValidOperator(const std::string& op);

int evaluateExpression(std::map<std::string, int>& vars);
void debugPrintTokens(const std::vector<std::string>& tokens); 
void handleTextCommand();
void handleOutputCommand(std::map<std::string, int>& vars);
void handleVarDeclaration(std::map<std::string, int>& vars);
void handleSetCommand(std::map<std::string, int>& vars);

#endif