// class_namespace.cpp

#include <iostream>
#define print(var) std::cout << var << std::endl

namespace ClassInstance {
	int internalVal;

class ClassExample {
public:
	ClassExample(int r) {
		std::cout << "Initialized with " << r << "." << std::endl;
		ClassInstance::internalVal = r;
	}

};

};

int main() {
	ClassInstance::ClassExample c(5);
	// does not make a new namespace
	print(ClassInstance::internalVal);
	return 0;
}