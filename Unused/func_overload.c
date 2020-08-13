#include <stdio.h>
#include <stdarg.h>

/*
float add(void * num1, void * num2, int typeIndicator) {
	switch (typeIndicator) {
		case 0: // one is a float
			num1 = (float*) num1;
			num2 = (float*) num2;
		case 1: // both are ints
			num1 = (int*) num1;
			num2 = (int*) num2;
	}

	return 0.5;
}
*/


/*
typedef enum {INT, FLOAT} NumType;

float add(NumType argType, void * nums,...) {
	if (argType == INT) nums = (int*) nums;
	else nums = (float*) nums;

	float sum = 0; // sum will always be float

	va_list args;
	va_start(args, nums);

	for (int i = 0; i < nums; i++)
		sum += va_arg(args, int);

	va_end(args);

	return sum;

}
*/

int main() {
	float nums[] = {3.5, 4.2, 2.3};
	float res = add(FLOAT, nums);

}