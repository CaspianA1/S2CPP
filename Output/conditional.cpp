#include "../Std_Lib/std_lib.hpp"
auto x = 5;
int main() {
STD_IF(gte(x, 5), display("It is bigger!"), display("It is not bigger!"));
return 0;
}