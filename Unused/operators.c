#include <stdarg.h>

int add(int nargs, ...) {
	va_list args; va_start(args, nargs); int r = 0;
	for (int i = 0; i < nargs; i++) r += va_arg(args, int);
	va_end(args); return r;
}

float addf(int nargs, ...) {
	va_list args; va_start(args, nargs); float r = 0;
	for (int i = 0; i < nargs; i++) r += va_arg(args, double);
	va_end(args); return r;
}

int sub(int nargs, ...) {
	va_list args; va_start(args, nargs); int r = 0;
	for (int i = 0; i < nargs; i++) r -= va_arg(args, int);
	va_end(args); return r;
}

float subf(int nargs, ...) {
	va_list args; va_start(args, nargs); float r = 0;
	for (int i = 0; i < nargs; i++) r -= va_arg(args, double);
	va_end(args); return r;
}

int mul(int nargs, ...) {
	va_list args; va_start(args, nargs); int r = 0;
	for (int i = 0; i < nargs; i++) r *= va_arg(args, int);
	va_end(args); return r;
}

float mulf(int nargs, ...) {
	va_list args; va_start(args, nargs); float r = 0;
	for (int i = 0; i < nargs; i++) r *= va_arg(args, double);
	va_end(args); return r;
}

int div(int nargs, ...) {
	va_list args; va_start(args, nargs); int r = 0;
	for (int i = 0; i < nargs; i++) r /= va_arg(args, int);
	va_end(args); return r;
}

float divf(int nargs, ...) {
	va_list args; va_start(args, nargs); float r = 0;
	for (int i = 0; i < nargs; i++) r /= va_arg(args, double);
	va_end(args); return r;
}