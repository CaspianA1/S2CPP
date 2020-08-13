// make_array.cpp

// call this function when creating an array from quoting

#include <vector>
#include <stdarg.h>
#include "stdarg_macros.h"

// make this work
// continue on this later
template <typename T>
std::vector<T> createList(int nargs, ...) {
	INIT // std::vector<T> args;
	LOOP args.push_back({va_arg(args, T)});
	DEINIT
}

#include <iostream>
using namespace std;

int main() {
	cout << createList(5, 1, 2, 3, 4, 5) << endl;

	return 0;
}