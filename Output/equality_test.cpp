#include "../Std_Lib/std_lib.hpp"
auto x = 5;
auto y = 5;
int main() {
display((int)(eq_cond(&x, &y)));
newline();
display((int)(eqv_cond(x, y)));
return 0;
}