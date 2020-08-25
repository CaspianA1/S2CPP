#include "list_declarations.hpp"
#include "list_tokenizer.cpp"
#include "print_linked_list.cpp"

#define assignToHead(type) pair.head = getRawType(type, head); break;
#define assignToTail(type) pair.tail = getRawType(type, toknen); break;

bool stringEquals(varied_type elem, std::string comparison) {
	// for some reason, I can't get a string out of this
	try {
	// std::cout << "Elem input and type: " << elem << type(elem) << std::endl;
		return boost::get<std::string>(elem) == comparison;
	}
	catch (boost::bad_get) {
		//std::cout << "Mistake happened!";
		return false;
	}
}



std::ostream& operator<<(std::ostream &out, const Pair &pair) {
	// int tailItem = reinterpret_cast<int*>(pair.tail);

	std::cout << "Type head: " << pair.head.which() << std::endl;
	std::cout << "Type tail: " << pair.tail.which() << std::endl;

	/*
	switch (pair.tail.which()) {
		case 0: print("String"); break;
		case 1: print("Int"); break;
		case 2: print("Long"); break;
		case 3: print("Double"); break;
		case 4: print("Bool"); break;
		default: print("Inaccessible"); break;
		// case 5: print("Pair"); break;
	}
	*/

    out << "|" << pair.head << ", " << "MEMORY: " << pair.tail << "|";
    return out;
}

std::ostream& operator<<(std::ostream &out, const std::vector<varied_type> &pair) {
	for (int i = 0; i < pair.size(); i++) {
		out << pair[i];
		if (i != pair.size() - 1)
			out << ", ";
	}
    return out;
}

varied_type frontPop(std::vector<varied_type>& tokens) {
	varied_type head = tokens[0];
	tokens.erase(tokens.begin());
	return head;
}

void removeRightParen(std::vector<varied_type>& tokens) {
	for (int i = tokens.size(); i >= 0; i--) {
		if (stringEquals(tokens[i], ")")) {
			tokens.erase(tokens.begin() + i);
			return;
		}
	}
}

Pair makePairs(std::vector<varied_type>& tokens, unsigned int levelOfDepth = 0) {
	Pair pair;
	varied_type head = frontPop(tokens);

	std::cout << "The level of depth is: " << levelOfDepth << std::endl;

	// head points to another linked list
	if (stringEquals(head, "(")) { // works now
		std::cout << "\tHead is a left paren, make a head linked list: "<< head << std::endl;
		// tokens.pop_back(); // will this remove a paren or not?
		removeRightParen(tokens);
		Pair newHead = makePairs(tokens, levelOfDepth + 1);
		pair.head = &newHead;
	}

	else {
		// head points to an atom
		std::cout << "\tHead points to an atom, make an un-pointy head: " << head << std::endl;
		switch (head.which()) {
			case 0: print("Assign string"); assignToHead(std::string)
			case 1: print("Assign int"); assignToHead(int)
			case 2: print("Assign double"); assignToHead(double)
			case 3: print("Assign bool"); assignToHead(bool)
		}
	}

	if (tokens.size() == 1) {
		std::cout << "\tThe tail has nothing on it: " << tokens << std::endl;

		varied_type newTail = &tokens[0];

		switch (newTail.which()) {
			case 2:
				double d = getRawType(double, newTail);
				pair.tail = &d;
		}

		/*
		// double newTail = getRawType(double, tokens[0]);
		pair.tail = &tail;


		switch (tail.which()) {
			case 0: assignToTail(std::string); break;
			case 1: assignToTail(int); break;
			case 2: assignToTail(double); break;
			case 3: assignToTail(bool); break;
			default: print("Invalid tail!");
		}
		*/

		// pair.tail = &v;
		// DO SOMETHING HERE
		// varied_type v = tokens[0];
		// return {&v, 0x00};
		// varied_type v = tokens[0];

	}

	// tail points to another linked list
	else if (stringEquals(tokens[0], "(")) {
		std::cout << "\tTail is a parenthesis, make a pointed list tail: " << tokens << std::endl;
		// tokens.pop_back(); // remove paren or something else?
		removeRightParen(tokens);
		Pair newTail = makePairs(tokens, levelOfDepth + 1);
		pair.tail = &newTail;
	}

	else {
		std::cout << "\tThe tail has a series of atoms on it, make a non-struct pointed tail: " << tokens << std::endl;
		Pair newTail = makePairs(tokens, levelOfDepth + 1);
		pair.tail = &newTail;
	}
	std::cout << "Returning pair: " << pair << std::endl;
	return pair;

}

int main() {
	// ((1 (2 3) 2 3) 2 3.122 t rue true 3.01 234532 false bob \" cool  sentence ! \" b );
	// std::string codeSnippet = "      ( ( 1 ( 2 3 ) 2 3 )    2    3.122 t rue true 3.01 234532 false bob \" cool  sentence ! \" b  )";
	std::string codeSnippet = " ( 1.2 2.4 3.6 ) ";
	std::vector<varied_type> tokens = tokenize(codeSnippet);
	Pair consPairs = makePairs(tokens);
	// std::cout << consPairs.tail << std::endl;
	// printLinkedList(consPairs);
	return 0;
}

/* [*/

/*
Returning pair: Type: 0
|b, MEMORY: 0x0|
Returning pair: Type: 4
|" cool  sentence ! ", MEMORY: 0x7ffee19398e0|
Returning pair: Type: 4
|bob, MEMORY: 0x7ffee1939c10|
Returning pair: Type: 4
|0, MEMORY: 0x7ffee1939f40|
Returning pair: Type: 4
|234532, MEMORY: 0x7ffee193a270|
Returning pair: Type: 4
|3.01, MEMORY: 0x7ffee193a5a0|
Returning pair: Type: 4
|1, MEMORY: 0x7ffee193a8d0|
Returning pair: Type: 4
|rue, MEMORY: 0x7ffee193ac00|
Returning pair: Type: 4
|t, MEMORY: 0x7ffee193af30|
Returning pair: Type: 4
|3.122, MEMORY: 0x7ffee193b260|
Returning pair: Type: 4
|2, MEMORY: 0x7ffee193b590|
Returning pair: Type: 4
|), MEMORY: 0x7ffee193b8c0|
Returning pair: Type: 4
|3, MEMORY: 0x7ffee193bbf0|
Returning pair: Type: 4
|2, MEMORY: 0x7ffee193bf20|
Returning pair: Type: 4
|), MEMORY: 0x7ffee193c250|
Returning pair: Type: 4
|3, MEMORY: 0x7ffee193c580|
Returning pair: Type: 4
|2, MEMORY: 0x7ffee193c8b0|
The tail has nothing on it: )
Returning pair: Type: 0
|0x7ffee193cc78, MEMORY: 0x0|
Returning pair: Type: 4
|1, MEMORY: 0x7ffee193cf40|
The tail has nothing on it: )
Returning pair: Type: 0
|0x7ffee193d2d8, MEMORY: 0x0|
The tail has nothing on it: )
Returning pair: Type: 0
|0x7ffee193d608, MEMORY: 0x0|
*/