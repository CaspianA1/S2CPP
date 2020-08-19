#include "../Std_Lib/std_lib.hpp"
auto add1 = identity([](auto x, auto y) {return add(x, 1)};);
template <typename S, typename U>
auto multiply(S x, U y) {
return mul(2, x, y);
};
int main() {
identity([](auto f) {return f()};);
return 0;
}