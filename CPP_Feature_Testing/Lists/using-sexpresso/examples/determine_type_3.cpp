// determine_type_3.cpp

#include "example_3.cpp"
#include <regex>

bool usingInteger = false, usingDouble = false, usingBool = false;

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

namespace everythingGlobal {

};

// remember to #undef after

int main() {
	// type determination macro, like #define TYPE_IS_INT
	std::string head_orig = car("(define x 5)"); // append _orig at transpile time

	std::cout << "Car: " << head_orig << std::endl;

	// no macro, only normal code

	if (matchRegex(INT_REGEX, head_orig)) {
		usingInteger = true;
	}
	else if (matchRegex(DOUBLE_REGEX, head_orig)) {
		usingDouble = true;
	}
	else if (matchRegex(BOOLEAN_REGEX, head_orig)) {
		usingBool = true;
	}

	if (usingInteger) {
		everythingGlobal::int head = std::stoi(head_orig);
		// in some way, insert head into that namespace
		// for the main program, say "using namespace everythingGlobal;"
	}

	/*
	#if USING_INTEGER == 1
	print("Making to integer!");
	int head = std::stoi(head_orig);
	#undef USING_INTEGER

	#elif USING_DOUBLE == 1
	print("Making to double!");
	double head = std::stof(head_orig);
	#undef USING_DOUBLE

	#elif USING_BOOL == 1
	print("Making to bool!");
	bool head = (head_orig == "true");
	#undef USING_BOOL

	#else
	std::string head = head_orig;

	#endif
	*/

	return 0;
}