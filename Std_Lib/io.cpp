#include <iostream>

template <typename T>
void display(T var) {
	std::cout << var;
}

void newline() {
	std::cout << std::endl;
}

std::string read() {
	std::string val;
	std::cin >> val;
	return val;
	
}