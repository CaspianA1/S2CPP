#include "../Std_Lib/std_lib.hpp"
#include <file2>
auto x = 5;
template <typename A, typename u>
auto f(A x, u y) {
	return add(3, x, y, 1);
	};
int main() {
	display(8);
	STD_IF(eq_cond(&x, &5), display("five"), display("not five"));
	add(3, 5, 5, mul(2, 3, 7));
	mul_d(4, 8.0, 5.0, 2.0, (double)(div_d(2, 7.0, 3.0)));
	f(add_d(2, 5.5, 7.0));
	auto z = f(8);
	auto y = x(x);
	auto pi = identity(" ( 3 1 4 1 5 ) ");
	identity([](auto x) {return add(x, 1)};);
	return 0;
	}