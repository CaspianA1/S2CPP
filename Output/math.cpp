#include "../Std_Lib/std_lib.hpp"
auto top_level = 245;
int main() {
	auto my_favorite_num = add(2, 5, 3);
	auto x = add(4, 5, 3, 2, (int)(mul(2, 2, 3)));
	auto m = mul_d(3, 8.0, 2.0, (double)(div_d(2, 5.0, 3.0)));
	auto y = div_d(3, 5.0, (double)x, (double)(mul_d(3, 2.0, 3.0, (double)(sub_d(2, 2.0, 1.0)))));
	auto j = div_d(1, 2.0);
	display(top_level);
	display(my_favorite_num);
	display(x);
	display(m);
	display(y);
	display(j);
	return 0;
	}