#include <iostream>

namespace Variables {}

// a macro that goes like #define def(var, type) type var = ___
// and get the type in some way
// this stuff is not working

int main() {
		using namespace Variables;
		int x = 5;
		using namespace std;
		std::cout << Variables::x << std::endl;
}
