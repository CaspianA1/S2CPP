// linked_list_2.cpp

#include <variant>
#include <vector>
#include <string>
#include <regex>
#include <iostream> // temporary

#define varied_type std::variant<std::string, int, double, struct Node*>

// integer, double/float, boolean, quotes, variable

struct Node {
	varied_type head;
	struct Node* tail;
};

// \b[0-9]{0,3}[^.]
// "\b[0-9]{1,3}[0-9]{1,3}\b"
std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

// from double:
// ^[-+]?\d+\.\d?$
// \b[0-9]{1,3}.[0-9]{1,3}\b",

/*
#define STRING_REGEX "\"[a-zA-Z]+\""
// do strings later
// string conditon: whitespace allowed between quotes
*/

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

// std::vector<varied_type> yielded in an "Illegal Instruction: 4"
void tokenize(std::string listData) {
	std::vector<varied_type> tokens;
	std::vector<char> tokenBuffer;

	for (int i = 0; i < listData.length(); i++) {
		char currChar = listData[i];

		if (i == listData.length() - 1) {
			tokenBuffer.push_back(currChar);
			std::string strToken(tokenBuffer.begin(), tokenBuffer.end());
			// don't check for string now, it won't work with the tokenBuffer yet
			// could make this checking more elegant

			if (strToken == "(" | strToken == ")") {
				std::cout << "Matched a parenthesis: " << strToken << std::endl;
			}

			else if (matchRegex(INT_REGEX, strToken)) {
				std::cout << "Matched an integer: " << strToken << std::endl;
			}

			else if (matchRegex(DOUBLE_REGEX, strToken)) {
				std::cout << "Matched a double: " << strToken << std::endl;
			}

			else if (matchRegex(DOUBLE_REGEX, strToken)) {
				std::cout << "Matched a boolean: " << strToken << std::endl;
			}

			else {
				std::cout << "Matched a variable: " << strToken << std::endl;
				// treat as variable name for now
			}


			/*
				- integer
				- double/float
				- boolean - true or false (conversion assumed)
				- surrounded by quotes - string
				- else, a variable (how to handle this)
			*/
		}
	}

}

int main() {
	std::string codeSnippet = "( 1 2 3 4 )";
	tokenize(codeSnippet);
	return 0;
}