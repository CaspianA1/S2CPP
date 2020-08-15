#include "../Std_Lib/std_lib.hpp"
template <typename T, typename Z, typename n, typename x>
T f(Z a, n b, x c) {
return mul_d(3, a, b, div_d(2, 3.0, c));
};
int main() {
auto m = mul_d(3, 8.0, 2.0, div_d(2, 5.0, 3.0));
display(m);
display(f(1, 2, 3));
return 0;
}