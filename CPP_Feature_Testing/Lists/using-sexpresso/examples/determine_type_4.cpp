#include <iostream>
#include <ostream>
#include <string>
#include <variant>
#include <regex>
#include "example_3.cpp"

// integer, double, boolean, list, string, variable
typedef enum {I, D, B, L, S, V} Type;
typedef std::variant<int, double, bool, std::string> Value;

struct ListValue {
    Type t; Value v;
};
// make overloaded << for ListValue

typedef struct ListValue ListValue;

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

// make ListValue a class, that will make overloading stuff easier (I think) (or maybe not)
// or, instead of all of this, just do "auto var = list_op(list_str)" and then if it's used, cast it (no that could be hard as well, I don't know)

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

// overload << for std::variant
// and other operators as well

int main() {
    std::string definition = "(define x 5)";
    std::string first = car(definition);
    ListValue l1 = getValueType(first);
    // std::cout << l1.v << std::endl;

    std::string quotedList = "(3 5 2)";
    std::string last = cdr(quotedList);
    ListValue l2 = getValueType(last);
}

/*
to do:
1. make cons
2. overload operators as necessary
3. integrate this type thing into the std lib
4. work it into the transpiler for real
*/
