// linked_list_3.cpp

#include "list_declarations.hpp"
#include "list_tokenizer.cpp"

varied_type frontPop(std::vector<varied_type>& tokens) {
	varied_type head = tokens[0];
	tokens.erase(tokens.begin());
	return head;
}

varied_type makeCarOrCdr(std::vector<varied_type>& tokens) {
	// component will be a list

	varied_type element = frontPop(tokens);

	if (type(pairCar) == type(std::string) && getRawType(std::string, head) == "(") {
		tokens.pop_back(); // remove right paren

	}
}

/*
Pair makeLinkedList(std::vector<varied_type> tokens) {
	varied_type car = makeCarOrCdr(tokens);
	varied_type cdr = makeCarOrCdr(tokens);

	Pair pair(car, cdr);

	/*
	Pair currentPair;

	#define castAssignToHead(type) currentPair.head = boost::get<type>(head); break;

	varied_type pairCar = frontPop(tokens);
	varied_type pairCdr = frontPop(tokens);




	// car will be a list
	if (type(pairCar) == type(std::string) && getRawType(std::string, head) == ")") {
		print("Left parenthesis");
		tokens.pop_back();
		print("Removed one right paren");
		Pair theCar = makeLinkedList(tokens);
		print("Made the car");
		currentPair.head = &theCar;
		print("Assigned the head";)
		continue;
	}
	// car will be an atom
	else {
		switch (head.which()) {
			case 0: castAssignToHead(std::string);
			case 1: castAssignToHead(int);
			case 2: castAssignToHead(double);
			case 3: castAssignToHead(bool);
			case 4: castAssignToHead(Pair*);
		}

		Pair pairCdr = makeLinkedList(tokens);
		currentPair.tail = &pairCdr;
	}
	return currentPair;
	*/
}

/*
Pair makeLinkedList(std::vector<varied_type> tokens) {
	Pair currentPair;

	unsigned short leftParenCount = 0, rightParenCount = 0;

	#define assignToHead(type) currentPair.head = boost::get<type>(head);

	while (leftParenCount != rightParenCount) {
		varied_type head = frontPop(tokens);

		if (typeid(head).name() == typeid(std::string).name()) {
			if (getRawType(std::string, head) == "(") {
				print("Left parenthesis");
				leftParenCount++;
				tokens.pop_back(); // remove 1 right paren - increase right paren count here?
				Pair pairAsList = makeLinkedList(tokens); // head is a list
				currentPair.head = &pairAsList;
				continue;
			}
			else if (getRawType(std::string, head) == ")") {
				print("Right parenthesis");
				rightParenCount++; // will never happen?
		}
		else {
			// get raw type of head
			switch (head.which()) {
				case 0: // std::string
					assignToHead(std::string);
					break;
				case 1: // int
					assignToHead(int);
					break;
				case 2: // double
					assignToHead(double);
					break;
				case 3: // boolean
					assignToHead(bool);
					break;
				case 4:
					// assignToHead(Pair*);
					// pair.head = boost::get<struct Pair>(head);
					currentPair.head = 28;
					break;
				default:
					std::cerr << "Invalid raw type of head" << std::endl;
				}

			Pair tail = makeLinkedList(tokens);
			currentPair.tail = &tail;
			}
		}
	
	}
	return currentPair;
}
/*


int main() {
	std::string codeSnippet = "      (     2    3.122 t rue true 3.01 234532 false bob \" cool  sentence ! \" b  )";
	std::vector<varied_type> tokens = tokenize(codeSnippet);
	Pair p = makeLinkedList(tokens);
	print(p.tail);

	return 0;
}
