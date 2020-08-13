// auto.cpp

// for c++ 14

#include <iostream>

using namespace std;

template <typename T>
auto add(T a, T b) {
	return a + b;
}

int main() {

	cout << add(5, 5) << endl;

}