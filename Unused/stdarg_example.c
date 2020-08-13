#include <stdio.h>
#include <stdarg.h>

void printNums(int num, ...) {
	va_list args;
	va_start(args, num);

	for (int i = 0; i < num; i++) {
		int value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}

	va_end(args);
}

int main() {
	printNums(3, 2, 3, 4);
	return 0;
}

/*
Output:
0: 2
1: 3
2: 4
3: 0
4: 0
*/