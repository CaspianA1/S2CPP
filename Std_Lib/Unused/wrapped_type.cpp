#include <iostream>

using namespace std;

/*
#define decltype template <typename T>\
				 WrappedType<T>
*/

template <typename Generic>
class WrappedType {
	public:
		Generic internalVar;
		WrappedType(Generic internalVar) { // string typename?
			this -> internalVar = internalVar;
		}
};


int main() {
	WrappedType<float> wrappedFloat(4.4); // figuring out individual types should be fairly easy - this can be done in the parser

	WrappedType<int> wrappedNum(3);

	// template <typename T>
	// WrappedType l[T] = {wrappedInt, wrappedNum};

	return 0;
}