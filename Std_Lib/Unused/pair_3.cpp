// pair_3.cpp

#include <stdlib.h>
#include <vector>

// use vector
// or normal linked list?
// or struct as usual?

template <typename SubType>
struct PolyElem {
	bool atomic;
	SubType atom;
	std::vector<SubType> lat;
};

template <typename SubType>
PolyElement<SubType> cons(SubType head, struct PolyElem<SubType> tail) {
	// join head and tail

	// get size1 and size2, add them together, get a new one


	struct PolyElement<SubType> item = {false, __ NULL};
}

template <typename SubType>
PolyElem<SubType> car(struct PolyElem<SubType> list) {
	return list.lat[0];
}

template <typename SubType>
PolyElem<SubType> cdr(struct PolyElem<SubType> list) {

}

// car: return element, with template subtype

// cdr: return element, with template subtype

// https://www.geeksforgeeks.org/vector-in-cpp-stl/
int main() {
	return 0;
}