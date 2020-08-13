// lambda_example.cpp

#include <iostream>

using namespace std;

int main() {

	int y = 4;

	auto add1 = [](auto x) {return x + 4;};

	cout << add1(5) << endl;
}