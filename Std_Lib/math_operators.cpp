// #include <stdio.h>
// #include <stdbool.h>
#include "stdarg_macros.h"

int add(int nargs, ...) {INIT int r = 0; LOOP r += va_arg(args, int); DEINIT}
double add_d(int nargs, ...) { INIT double r = 0; LOOP r += va_arg(args, double); DEINIT}
int sub(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, int); else r -= va_arg(args, int);} DEINIT}
double sub_d(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, double); else r *= va_arg(args, double);} DEINIT}
int mul(int nargs, ...) {INIT int r = 1; LOOP r *= va_arg(args, int); DEINIT}
double mul_d(int nargs, ...) {INIT double r = 1; LOOP r *= va_arg(args, double); DEINIT}
double div_d(int nargs, ...) {INIT double r; LOOP {if (i == 0) r = va_arg(args, double); else r /= va_arg(args, double);} DEINIT}

template <typename T>
bool eq(T stmt1, T stmt2) { // val
	return stmt1 == stmt2;
}


template <typename T>
bool eqv(T* stmt1, T* stmt2) { // mem
	// make this work
	return stmt1 == stmt2;
}


template <typename T>
bool equal(T stmt1, T stmt2) { // val
	return eq(stmt1, stmt2);
}


// add equality and general boolean stuff

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