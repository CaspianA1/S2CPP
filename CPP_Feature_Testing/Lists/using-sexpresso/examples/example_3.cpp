// example_3.cpp

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

#include <iostream>
#define print(var) std::cout << var << std::endl;

std::string format(std::string unformatted) {
	sexpresso::Sexp parsedExpr = sexpresso::parse(unformatted);
	return parsedExpr.toString();
}

std::string car(std::string expr) {
	expr = format(expr);
	std::cout << "Formatted: " << expr << std::endl;
	// list
	if (expr[1] == '(') {
		std::string charBuf;
		unsigned int lParens = 0, rParens = 0;

		for (int i = 1; i < expr.size(); i++) {
			char currChar = expr[i];
			if (currChar == '(') {
				lParens++;
			}
			else if (currChar == ')') {
				rParens++;
			}

			charBuf += currChar;

			if (lParens == rParens)
				return charBuf;
		}
	}

	// symbol
	std::string charBuf;
	for (int i = 1; i < expr.size(); i++) {
		char currChar = expr[i];
		if (currChar == ' ')
			break;
		else
			charBuf += currChar;
		}
	return charBuf;
}

std::string cdr(std::string expr) {
	// get car, strip it off

	std::string head = car(expr);

	std::string tail = "(";

	for (int i = expr.find(head) + head.size(); i < expr.size(); i++) {
		tail += expr[i];
	}

	return format(tail);
}

/*
int main() {
	// (a b (c d e))
	// ((a b) c d e)
	// ((a ( j c) b) c)
	// std::string expr = "((a ( j c) b) c)";
	std::string expr = "(a  ab(a b c) c c  b (c d e))";
	// std::string head = car(expr);
	// after each call to car, convert back to the ints as needed

	std::string tail = cdr(expr);
	print(tail);
}
*/

// after calling car or cdr, call another function that typechecks the output type
// this will then return different types depending on the structure of the data

/*

std::string s_expr = makeSExpr("(define x (+ 2 5))")

*/