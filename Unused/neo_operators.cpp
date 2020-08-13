#include <tuple>
#include <iostream>

/*
auto add() {
	va_list args;
	va_start(args, num);
	float sum = 0;

	for (int i = 0; i < num; i++)
		sum += va_arg(args, float);

	va_end(args);

	return sum;
}
*/

template<class T>
auto add(int num,...) {
	va_list args; va_start(args, num);
	T sum = 0;

	for (int i = 0; i < num; i++) {
		sum += va_arg(args, T);
	}
	va_end(args);
	return sum;
}

int main() {
	int a = add(5, 2, 3);
	std::cout<<a<<std::endl;
	return 0;

}