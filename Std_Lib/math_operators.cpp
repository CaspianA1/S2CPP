// #include <stdio.h>
// #include <stdbool.h>
#include "stdarg_macros.h"

#define OPERATOR(func_name, operator)\
				template <typename T>\
				bool func_name(T t1, T t2) {\
					return t1 operator t2;\
				}

int add(int nargs, ...) {INIT int r = 0; LOOP r += va_arg(args, int); DEINIT}
double add_d(int nargs, ...) { INIT double r = 0; LOOP r += va_arg(args, double); DEINIT}
int sub(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, int); else r -= va_arg(args, int);} DEINIT}
double sub_d(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, double); else r *= va_arg(args, double);} DEINIT}
int mul(int nargs, ...) {INIT int r = 1; LOOP r *= va_arg(args, int); DEINIT}
double mul_d(int nargs, ...) {INIT double r = 1; LOOP r *= va_arg(args, double); DEINIT}

#include <iostream>
using namespace std;
double div_d(int nargs, ...) { // use WrappedType
	va_list args; va_start(args, nargs);
	for (int i = 0; i < nargs; i++) {
		cout << "Input: " << va_arg(args, double) << endl;
	}
	va_end(args);
	return 3.5;

	// INIT
	// double r = 0;
	/*
	LOOP {
		std::cout << "Result is this: " << r << std::endl;
		double num_to_add = va_arg(args, double);
		std::cout << "Input number is " << num_to_add << "." << std::endl;
		if (i == 0)
			r = num_to_add;
		else
			r /= num_to_add;
			}
	*/
	// std::cout << "Just finished division, with this as the result: " << r << "." << std::endl;
	// DEINIT
}

OPERATOR(eq_cond_, ==)
OPERATOR(gt, >)
OPERATOR(gte, >=)
OPERATOR(lt, <)
OPERATOR(lte, <=)

// make this work
template <typename T>
bool eqv(T* stmt1, T* stmt2) { // mem
	// make this work
	return stmt1 == stmt2;
}

/*
template <typename T>
bool eq(T stmt1, T stmt2) { // val
	return stmt1 == stmt2;
}
*/

/*
template <typename T>
bool equal(T stmt1, T stmt2) { // val
	return eq(stmt1, stmt2);
}
*/

/*
template <typename Number>
bool gt(Number num1, Number num2) {
	return num1 > num2;
}
*/

/*
template <typename Number>
bool gte(Number num1, Number num2) {
	return num1 >= num2;
}

template <typename Number>
bool lt(Number num1, Number num2) {
	return num1 < num2;
}

template <typename Number>
bool lte(Number num1, Number num2) {
	return num1 <= num2;
}
*/

/*
int main() {
	int result = add(2, 5, 3);
	printf("%d, %f, %d, %f, %d, %f, %f\n", add(2, 5, 3), add_d(3, 3.5, 4.5, 5.2),
		sub(3, 3, 5, 2), sub_d(3, 3.2, 5.5, 2.2), mul(3, 3, 5, 2), mul_d(3, 3.5, 5.5, 2.2), div_d(3, 2.5, 5.5, 3.6));
	return 0;
}
*/

/*
To do:
convert +-* and div to long names - done
make long name only to div - and don't add 'f' onto divf - done
*/