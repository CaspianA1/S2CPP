// auto_array.cpp

#include <iostream>
#include <initializer_list>

using namespace std;

int main() {
	auto pi = {3, 1, 4, 1, 5};

	for (int num: pi)
		cout << num;
	return 0;
}