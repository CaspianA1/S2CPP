// determine_type.cpp

#include <regex>
#include "example_3.cpp"

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

#define convertVarType(var)\
    if (var[0] == '(' && var.back() == ')')

/*
template <typename T>
T convertVarType(std::string var) {
    T returnVal;

    if (var[0] == '(' && var.back() == ')')
        returnVal = var; // list
    else if (matchRegex(INT_REGEX, var))
        returnVal = std::stoi(var);
    else if (matchRegex(DOUBLE_REGEX, var))
        returnVal = std::stod(var);
    else if (matchRegex(BOOLEAN_REGEX, var))
        returnVal = (var == "true");
    else
        returnVal = var; // string or variable

    return returnVal;
}
*/

// idea: nested ternary assignment statement

/*
int a = 5;

auto b = a > 5 ? "bob" : 2.5; // doesn't work
*/

int main() {
int a = 5;

if (a == 5)
    int b = 25;
else if (a > 5)
    int b = 35;
else
    int b = 26;

std::cout << b << std::endl;
/* this works */
    
    std::string expression = "(define x (+ 5 3 (* 2 2)))";
   // std::string firstElement = car(expression); // yields "define", from another file
    convertVarType(firstVal, car(expression)); // this will be a var name
    // std::string firstVar = convertVarType(firstElement); // doesn't work either
}