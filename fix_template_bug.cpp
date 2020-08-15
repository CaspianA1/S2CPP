#include <stdarg.h>
#define INIT va_list args; va_start(args, nargs);
#define LOOP for (int i = 0; i < nargs; i++)
#define DEINIT va_end(args); return r;

#include <iostream>
template <typename T>
void display(T var) {
	std::cout << var << std::endl;
}

int add(int nargs, ...) {INIT int r = 0; LOOP r += va_arg(args, int); DEINIT}
double add_d(int nargs, ...) { INIT double r = 0; LOOP r += va_arg(args, double); DEINIT}
int sub(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, int); else r -= va_arg(args, int);} DEINIT}
double sub_d(int nargs, ...) {INIT int r; LOOP {if (i == 0) r = va_arg(args, double); else r *= va_arg(args, double);} DEINIT}
int mul(int nargs, ...) {INIT int r = 1; LOOP r *= va_arg(args, int); DEINIT}
double mul_d(int nargs, ...) {INIT double r = 1; LOOP r *= va_arg(args, double); DEINIT}
double div_d(int nargs, ...) {INIT double r; LOOP {if (i == 0) r = va_arg(args, double); else r /= va_arg(args, double);} DEINIT}

template <typename T, typename S, typename M, typename x>
T f(S a, M b, x c) {
return mul_d(3, a, b, div_d(2, 3.0, c));
};

int main() {
	auto m = mul_d(3, 8.0, 2.0, div_d(2, 5.0, 3.0));
	display(m);
	display(f(1, 2, 3));
	return 0;
}
