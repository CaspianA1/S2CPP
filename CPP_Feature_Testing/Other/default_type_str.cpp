#include <string>
#include <iostream>

using namespace std;

auto x = "bob";

int main() {
	cout << (typeid(x) == typeid(const char*)) << endl;
}
