// list_tokenizer.cpp

#include <regex>
#include "list_declarations.hpp" // this file cannot be used on its own without this

std::string INT_REGEX = "^[-+]?\\d+$",
			DOUBLE_REGEX = "^[-+]?\\d+\\.\\d?$",
			BOOLEAN_REGEX = "^(true|false)$";

bool matchRegex(std::string pattern, std::string inputString) {
	std::regex expression(pattern);
	return std::regex_match(inputString, expression);
}


bool stringEquals(varied_type elem, std::string comparison) {
	try {
		return boost::get<std::string>(elem) == comparison;
	}
	catch (boost::bad_get) {
		return false;
	}
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
		// std::cout << "String or variable: " << untypedToken << std::endl;
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

/*
void printVariedTypeVector(std::vector<varied_type> variedVector) {
	// #define hasType(type) std::holds_alternative<type>(wrappedElem) // not working for some reason
	// #define printWrapped(type) std::cout << std::get<type>(wrappedElem)
	#define wrappedPrintWrapped(type) printWrapped(type, wrappedElem)
	for (int i = 0; i < variedVector.size(); i++) {
		varied_type wrappedElem = variedVector[i];

		///// not working???
		// this can probably be shortened
		if (hasType(std::string))
			printWrapped(std::string);
		else if (hasType(int))
			printWrapped(int);
		else if (hasType(double))
			printWrapped(double);
		else if (hasType(bool))
			printWrapped(bool);
		else
			print("All of the casts failed!");
		///////

		// use the defined macro here (modify it a bit?)
		try {wrappedPrintWrapped(std::string);}
		catch (std::bad_variant_access&) {
			try {wrappedPrintWrapped(int);}
			catch (std::bad_variant_access&) {
				try {wrappedPrintWrapped(double);}
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
*/

void printVariedTypeVector(std::vector<varied_type> variedVector) {
	// size of vector is zero
	// print("Printing the vector!");
	// print("Varied vector size: " + std::to_string(variedVector.size()));
	for (int i = 0; i < variedVector.size(); i++) {
		// print("Iteration " + std::to_string(i));
		// std::cout << variedVector[i];
		varied_type element = variedVector[i];
		// std::cout << "ELement which: " << element.which() << std::endl;
		switch (element.which()) {
			case 0: // std::string
				std::cout << boost::get<std::string>(element);
				break;
			case 1: // int
				std::cout << boost::get<int>(element);
				break;
			case 2: // double
				std::cout << boost::get<double>(element);
				break;
			case 3: // bool
				std::cout << boost::get<bool>(element);
				break;
			case 4:
				std::cout << "Inaccessible struct element";
				break; // probably will not occur
		}

		if (i == variedVector.size() - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

}

/*
void unspaceParentheses(std::vector<varied_type>& tokens) {
	for (int i = 0; i < tokens.size(); i++) {
		varied_type v = tokens[i];
		std::string origType, asStr;
		switch (v.which()) {
			case 0: {
				asStr = getRawType(std::string, v);
				if (asStr[0] == '"' && asStr.back() == '"') {
					print("String literal");
				}
				origType = "string";
				break;
			}
			case 1: {
				asStr = std::to_string(getRawType(int, v));
				origType = "int";
				break;
			}
			case 2: {
				asStr = std::to_string(getRawType(double, v));
				origType = "double";
				break;
			}
			case 3: {
				asStr = std::to_string(getRawType(bool, v));
				origType = "bool";
				break;
			}
		}
		if (asStr[0] == '(') {}
	}
}
*/

std::vector<varied_type> tokenize(std::string listData) {
	std::vector<varied_type> tokenList;

	std::vector<char> tokenBuffer;

	bool tokenizingString = false;
	bool justEncounteredSpace = true;

	#define addToToken(currChar) tokenBuffer.push_back(currChar);

	/*
	#define castAndSubmitToken()std::string untypedToken(tokenBuffer.begin(), tokenBuffer.end());\
								tokenBuffer.clear();\
								auto newToken = changeTokenType(untypedToken);\
								tokenList.push_back(newToken);
	*/

	#define castAndSubmitToken()\
	std::string untypedToken(tokenBuffer.begin(), tokenBuffer.end());\
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
				continue;
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
			justEncounteredSpace = false;
			addToToken(currChar);
			if (i == listData.length() - 1) {
				castAndSubmitToken();
			}
		}
	}
	// unspaceParentheses(tokenList);
	return tokenList;
}


int main() {
	// spaces for parens will already be done by python
	std::string codeSnippet = " ( 2 ( 3.122 ) t rue true 3.01 234532 false bob \" cool  sentence ! \" b  )";
	std::vector<varied_type> tokens = tokenize(codeSnippet);
	printVariedTypeVector(tokens); // get the tokenizer to work with boost::variant
	return 0;
}
