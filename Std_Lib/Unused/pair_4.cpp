// pair_4.cpp
// with vector

#include <vector>

// macro for template?

// t is another WrappedVector
template <typename T>
struct WrappedVector {
	std::vector<T> internal;
};

template <typename T>
WrappedVector<T> cons(T atom, WrappedVector<T> lat) {
	struct WrappedVector<T> wrappedAtom = {atom};
	std::vector<T> composed = lat.internal.insert(0, wrappedAtom); // need copy of vector
	return composed; // return function call;
}

template <typename T>
WrappedVector<T> car(WrappedVector<T> lat) {
	return lat.internal[0];
}

template <typename T>
WrappedVector<T> cdr(WrappedVector<T> lat) {
	// WrappedVector<T> copiedVec = std::vector<T>(lat.internal.begin() + 1, lat.internal.end());
	return std::vector<T>(lat.internal.begin() + 1, lat.internal.end());
}

// nested pairs would be ideal

int main() {
	// this is clumsy
	struct WrappedVector<WrappedVector<int> > v;
	return 0;
}