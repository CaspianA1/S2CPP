// equivalence.cpp

#include <iostream>

using namespace std;

// generalize these
bool eq(int a, int b) {
	return a == b;
}

bool eqv(int* a, int* b) {
	return &a == &b;
}

int main() {
	int a = 5;
	int b = 6;

	// make eqv work
	cout << eq(a, b) << endl << eqv(&a, &a) << endl;

	return 0;
}