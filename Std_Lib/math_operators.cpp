// #include <stdio.h>
// #include <stdbool.h>
#include "stdarg_macros.h"

#define OPERATOR(func_name, operator)\
				template <typename T>\
				bool func_name(T t1, T t2) {\
					return t1 operator t2;\
				}\

int add(int nargs, ...) {INIT int r = 0; LOOP r += va_arg(args, int); DEINIT}
double add_d(int nargs, ...) { INIT double r = 0; LOOP r += va_arg(args, double); DEINIT}
int sub(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, int); else r -= va_arg(args, int);} DEINIT}
double sub_d(int nargs, ...) {INIT double r; LOOP {if (i == 0) r = va_arg(args, double); else r -= va_arg(args, double);} DEINIT}
int mul(int nargs, ...) {INIT int r = 1; LOOP r *= va_arg(args, int); DEINIT}
double mul_d(int nargs, ...) {INIT double r = 1; LOOP r *= va_arg(args, double); DEINIT}
double div_d(int nargs, ...) {INIT double r; LOOP {if (i == 0) r = va_arg(args, double); else r /= va_arg(args, double);} DEINIT}

// https://stackoverflow.com/questions/16299246/what-is-the-difference-between-eq-eqv-equal-and-in-scheme
// equal (object structure) is not implemented for now
OPERATOR(eqv_cond, ==)
OPERATOR(gt, >)
OPERATOR(gte, >=)
OPERATOR(lt, <)
OPERATOR(lte, <=)

// #define eq_cond(a, b) &a == &b

// add support for this
template <typename A, typename B>
bool eq_cond(A* a, B* b) {
	return a == b;
}