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
double sub_d(int nargs, ...) {INIT double r; LOOP {if (i == 0) r = va_arg(args, double); else r -= va_arg(args, double);} DEINIT}
int mul(int nargs, ...) {INIT int r = 1; LOOP r *= va_arg(args, int); DEINIT}
double mul_d(int nargs, ...) {INIT double r = 1; LOOP r *= va_arg(args, double); DEINIT}

#include <iostream>
using namespace std;
double div_d(int nargs, ...) { // use WrappedType
	INIT double r;
	LOOP {
		if (i == 0) r = va_arg(args, double);
		else r /= va_arg(args, double);
		// cout << "Input: " << va_arg(args, double) << endl;
	}
	DEINIT
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

// not exactly an operator, but still related
// may not be needed
template <typename T>
double toDouble(T var) {
	return (double) var;
}