// generic_lists.cpp

#include <iostream>
#include <string>

/*
template <typename Atom>
union ListComponent {
	Atom atomElem;
	Atom pair[];
};

template <typename T>
ListComponent<T> l = {5, {3, 4}};
*/

template <typename Atom>
struct Val {Atom atomicVal, listVal[];};

class ListComponent {
public:
	bool isAnAtom;

	template <typename T>
	ListComponent(bool atomicStatus, T value) {
		isAnAtom = atomicStatus;
		var = value;
	}

	std::string to_string() {
		return "";
	}

	~ListComponent() {

	}
};

int main() {

	return 0;
}