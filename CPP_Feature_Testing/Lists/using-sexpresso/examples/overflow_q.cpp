#include "example_3.cpp"
#include <regex>

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

#define determineType(var)\
	if (matchRegex(INT_REGEX, val))\
		#define USING_INTEGER\
	else if (matchRegex(DOUBLE_REGEX, val))\
		#define USING_DOUBLE\
	else if (matchRegex(BOOLEAN_REGEX, val))\
		#define USING_BOOL\
	else\
		#define USING_RAW