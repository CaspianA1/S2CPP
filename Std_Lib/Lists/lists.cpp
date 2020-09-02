#include <string>
#include <variant>
#include <regex>
#include <ostream>
#include <iostream>
#define print(var) std::cout << var << std::endl
#define print2(var, var2) std::cout << var << var2 << std::endl

#define SEXPRESSO_OPT_OUT_PIKESTYLE
#ifdef SEXPRESSO_OPT_OUT_PIKESTYLE
#ifndef SEXPRESSO_HEADER
#define SEXPRESSO_HEADER
#include <vector>
#include <string>
#include <cstdint>
#include "sexpresso/sexpresso/sexpresso.cpp"
#endif
#endif

#define asString(var, type) format(std::to_string(std::get<type>(var)))
#define ComparableType std::variant<const char*, int, double, bool, ListValue>

std::string format(std::string unformatted) {
    sexpresso::Sexp parsedExpr = sexpresso::parse(unformatted);
    return parsedExpr.toString();
}

// integer, double, boolean, list, string, variable
typedef enum {I, D, B, L, S, V} Type;
typedef std::variant<int, double, bool, std::string> Value;

struct ListValue {Type t; Value v;};
typedef struct ListValue ListValue;

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

ListValue getValueType(std::string operationOutp) {
    if (matchRegex(INT_REGEX, operationOutp))
        return {I, std::stoi(operationOutp)};
    else if (matchRegex(DOUBLE_REGEX, operationOutp))
        return {D, std::stod(operationOutp)};
    else if (matchRegex(BOOLEAN_REGEX, operationOutp))
        return {B, (operationOutp == "true")};
    else if (operationOutp[0] == '(' && operationOutp.back() == ')')
        return {L, operationOutp};
    else if (operationOutp[0] == operationOutp.back() && operationOutp.back() == '\"')
        return {S, operationOutp};
    else
        return {V, operationOutp};
}