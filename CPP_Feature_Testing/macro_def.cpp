#include <iostream>

#define define(type, name, val) type name = val
#define display(var) std::cout << var
#define newline() std::cout << std::endl

int main() {
	define(auto, x, 5);
	display(x);
	newline();
	return 0;
}
