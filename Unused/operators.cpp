// operators.cpp

#include <iostream>
#include <stdarg.h>

/*
using namespace std;

// adds a variable amount of numbers that are either floats or ints
template <typename Number>
Number add(int numArgs,...) {
	va_list args;
    va_start(args, numArgs);

    Number result = 0;
	
	for (int i = 0; i < numArgs; i++)
		result += va_arg(args, Number);

	va_end(args);

	return result;

}

/*
template <typename T>
int wrappedAdd(T num,...) {
	// determine if int add or float add needed
	// or will the templates take care of it?
}
*/



int main() {
	cout << add(5, 3, 2.5) << endl;
	return 0;
}