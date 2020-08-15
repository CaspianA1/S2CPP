#include <iostream>

template <typename T>
void display(T var) {
	std::cout << var << std::endl;
}

std::string read() {
	std::string val;
	std::cin >> val;
	return val;
	
}