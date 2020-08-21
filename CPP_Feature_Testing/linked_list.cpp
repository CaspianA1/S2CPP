// linked_list.cpp

// #include <any>
#include <variant>
#include <vector>
#include <regex>
#include <string>
#include <iostream>
#include "../Std_Lib/generic_wrapped_type.cpp"

#define print(var) std::cout << var << std::endl;
// #define cast(var, to) std::any_cast<to>(var);
// #define bad_cast const std::bad_any_cast& e
#define variant_type std::variant<std::string, int, double, struct Node*>

struct Node {std::variant<variant_type> head; struct Node* tail;};

template <typename T>
T handleTokenType(std::string tokenAsStr) {

}

std::vector<std::string> tokenize(std::string stringCastList) {
	std::vector<variant_type> tokenList;
	std::vector<variant_type> tokenBuffer;

	#define pushToBuffer() 		tokenBuffer.push_back(currChar)
	#define pushToTokenList()	std::string tokenAsStr(tokenBuffer.begin(), tokenBuffer.end());\
								tokenList.push_back(handleTokenType(tokenAsStr)); tokenBuffer.clear();

	for (int i = 0; i < stringCastList.length(); i++) {
		char currChar = stringCastList[i];

		if (i == stringCastList.length() - 1) {
			pushToBuffer();
			pushToTokenList();
			continue; // maybe not needed?
		}

		if (currChar != ' ')
			pushToBuffer();
		
		else {
			pushToTokenList();
		}
	}
	return tokenList;
}

std::string frontPop(std::vector<variant_type>& tokens) {
	std::string currToken = tokens[0]; // not sure of type
	tokens.erase(tokens.begin());
	return currToken;
}

struct Node constructLinkedList(std::vector<variant_type> tokens, struct Node node = {0, 0}) {
	std::vector<variant_type>& tokenRef = tokens;

	int leftParenCount = 0, rightParenCount = 0;

	variant_type currToken = frontPop(tokenRef);

	while (leftParenCount != rightParenCount) {
		if (currToken == "(") {
			leftParenCount++;
			tokens.pop_back();  // remove one right paren
			node.head = constructLinkedList(tokens, node);
		}

		else if (currToken == ")") {
			rightParenCount++;
		}

		else {
			node.head = currToken;
		}
		struct Node refNode = constructLinkedList(tokens, node);
		node.tail = &refNode;
	}
	return node;
}

// could be an atom or a list
template <typename T>
T car(struct Node n) {
	return n.head;
}

struct Node cdr(struct Node n) {
	return *n.tail;
}

struct Node cons(const std::string var, std::vector<variant_type> tokenizedList) {
	variant_type newVar = handleTokenType(var);
	tokenizedList.insert(tokenizedList.begin() + 1, std::any_cast<std::string>(var));
	struct Node tree = constructLinkedList(tokenizedList);
	return tree;
}

template <typename T>
void displayVector(std::vector<T> const vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::string s = "( 1 2 3 4 )";
	std::vector<std::string> v = tokenize(s);
}