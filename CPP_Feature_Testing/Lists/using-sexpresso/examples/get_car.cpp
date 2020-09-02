// get_car.cpp

// not needed now
// use other library

#define SEXPRESSO_OPT_OUT_PIKESTYLE
#ifdef SEXPRESSO_OPT_OUT_PIKESTYLE
#ifndef SEXPRESSO_HEADER
#define SEXPRESSO_HEADER
#include <vector>
#include <string>
#include <cstdint>
#include "../sexpresso/sexpresso/sexpresso.cpp"
#endif
#endif

#include "../../list_declarations.hpp"
#include "../../list_tokenizer.cpp"
#include <iostream>

template <typename T>
std::string getCar(T sexp) {
	std::vector<varied_type> tokens = tokenize(sexp.toString());

	std::string car = "";

	std::string tokens = sexp.toString();
	for (int i = 0; i < tokens.size(); i++) {
		char t = tokens[i];
	}

	return "";
}

int main() {
	// expr will already be spaced properly by python
	auto expression = " ( my-values bob ( sweet baby jesus ) ( hi  mom )     just-a-thing )";
    auto parsetree = sexpresso::parse(expression);
    getCar(parsetree);
}