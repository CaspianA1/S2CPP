#include "../Std_Lib/std_lib.hpp"
int main() {
auto x = add(4, 5, 3, 2, mul(2, 2, 3));
auto m = mul_d(3, 8, 2, div_d(2, 5, 3));
std::cout << std::endl;
display(x);
display(m);
display("This worked!");
return 0;
}