// template_experiment.cpp

#include <iostream>

#define tn typename

using namespace std;

template<tn T, tn Z>
T add(T x, Z y, T z) {
	return x + y + z;
}

int main() {
	cout << add(5, 3.2, 2) << endl;
	return 0;
}