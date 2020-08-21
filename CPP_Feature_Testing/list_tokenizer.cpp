// list_tokenizer.cpp

#include <string>
#include <variant>
#include <vector>
#include <regex>
#include <iostream>

#define print(var) std::cout << var << std::endl
#define varied_type std::variant<std::string, int, double, struct Node*>

struct Node { // node here not needed
	varied_type head;
	struct Node* tail;
};

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}

varied_type changeTokenType(std::string untypedToken) {
	// print("Untyped token: " + untypedToken);
	if (untypedToken == "(" | untypedToken == ")") {
		// print("Parenthesis");
		return untypedToken;
	}

	else if (matchRegex(INT_REGEX, untypedToken)) {
		// print("Integer");
		return std::stoi(untypedToken);
	}
	else if (matchRegex(DOUBLE_REGEX, untypedToken)) {
		// print("Double");
		return std::stod(untypedToken);
	}
	else if (matchRegex(BOOLEAN_REGEX, untypedToken)) {
		// print("Boolean");
		return untypedToken == "true";
	}
	else {
		// print("String or variable");
		return untypedToken;
	}
}

/*
template <typename T>
bool onlyContains(std::vector<T> buffer, T searchFor) {
	for (T item: buffer) {
		if (item != searchFor) return false;
	}
	return true;
}
*/

// a utility
void printVariedTypeVector(std::vector<varied_type> variedVector) {
	#define printWrapped(type) std::cout << std::get<type>(wrappedElem);
	for (int i = 0; i < variedVector.size(); i++) {
		varied_type wrappedElem = variedVector[i];
		try {printWrapped(std::string);}
		catch (std::bad_variant_access&) {
			try {printWrapped(int);}
			catch (std::bad_variant_access&) {
				try {printWrapped(double);}
				catch (std::bad_variant_access&) {
					print("All of the casts failed!");
				}
			}
		}

		if (i == variedVector.size() - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}

std::vector<varied_type> tokenize(std::string listData) {
	std::vector<varied_type> tokenList;

	std::vector<char> tokenBuffer;

	bool tokenizingString = false;
	bool justEncounteredSpace = true;

	#define addToToken(currChar) tokenBuffer.push_back(currChar);
	#define castAndSubmitToken()std::string untypedToken(tokenBuffer.begin(), tokenBuffer.end());\
								tokenBuffer.clear();\
								auto newToken = changeTokenType(untypedToken);\
								tokenList.push_back(newToken);

	for (int i = 0; i < listData.length(); i++) {
		char currChar = listData[i];
		// std::cout << "Current character: " << currChar << std::endl;

		if (currChar == '\"') {
			if (tokenizingString) { // stop tokenizing string
				// print("Ending string tokenization");
				addToToken(currChar);
				castAndSubmitToken();
				tokenizingString = false;
			}
			else { // start tokenizing string
				// print("Starting string tokenization");
				addToToken(currChar);
				tokenizingString = true;
				continue;
			}
		}

		else {
			if (tokenizingString) {
				// print("In the middle of string tokenization");
				addToToken(currChar);
				continue; 
			}
		}

		if (currChar == ' ') {
			if (!justEncounteredSpace) {
				// print("Found a space, submit variable");
				castAndSubmitToken();
				justEncounteredSpace = true;
			}
		}
		else {
			// print("Normal token, add it");
			addToToken(currChar);
			justEncounteredSpace = false;
		}

	}
	return tokenList;
}

/*
int main() {
	std::string codeSnippet = "      (     2    3.0 t rue true 3. 234532 false bob \" cool  sentence ! \"   )  ";
	std::vector<varied_type> tokens = tokenize(codeSnippet);
	printVariedTypeVector(tokens);
	return 0;
}
*/