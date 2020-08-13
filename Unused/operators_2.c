#include <stdarg.h>

#define numOp (nargs resultType operator) (va_list args; va_start(args, nargs); int r = 0; for (int i = 0; i < nargs; i++) r += va_arg(args, resultType); va_end(args); return r;)

#define INT int
#define PLUS +

int add(int nums, ...) {
	numOp(nums, INT, PLUS);
}

int main() {

}