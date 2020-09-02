#include <string>
#include <iostream>

using namespace std;

class Dog {
	public:
		string name;

		Dog(string inName) {
			name = inName;
		}

		bool operator==(Dog otherDog) {
			return name == otherDog.name;
		}
};

int main() {
	Dog dog1("bob");
	Dog dog2("bob");
	cout << (dog1 == dog2) << endl;
}