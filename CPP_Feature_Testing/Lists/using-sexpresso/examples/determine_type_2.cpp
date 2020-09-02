// determine_type_2.cpp

#include <regex>
#include "example_3.cpp"

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}
// teach out to ben, cc cory

#define convertVarType(varname, val)\
    if (matchRegex(INT_REGEX, val))\
        int varname = std::stoi(val);\
    else if (matchRegex(DOUBLE_REGEX, val))\
        double varname = std::stod(val);\
    else if (matchRegex(BOOLEAN_REGEX, val))\
        bool varname = (val == "true");\
    else\
        std::string varname = val;\

int main() {
     convertVarType(head, car("(define x 5)"))

     std::cout << head << std::endl;
}