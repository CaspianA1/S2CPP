// rvalue_array.cpp

#include <iostream>

using namespace std;

int f(int ray[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += ray[i];
	}
	return sum;
}

int main() {
	int ray[] = {1, 2, 3, 4, 5};
	int sum = f(ray);

	int sum2 = f([int] {3, 4, 5, 6, 7});

	cout << sum << ", " << sum2 << endl;

	return 0;
}