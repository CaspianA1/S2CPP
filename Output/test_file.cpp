#include "../Std_Lib/std_lib.hpp"
auto x = 5;
template <typename T, typename X, typename q>
T f(X x, q y) {
return add(3, x, y, 1);
};
int main() {
display(8);
if_(eq_cond_(x, 5), display("five"), display("not five"));
add(3, 5, 5, mul(2, 3, 7));
mul_d(4, 8, 5, 2, div_d(2, 7, 3));
f(add_d(2, 5.5, 7.0));
auto z = f(8);
auto y = identity("x");
auto pi = identity(
				template <typename T>
				vector <T> vect {3, 1, 4, 1, 5}
				);
identity([](auto x) {return add(x, 1)};);
return 0;
}