// pair_5.cpp

#include <boost/any.hpp>

using namespace boost;

any pair = {1, 2};

any cons(any a, any b) {
	return {a, b};
}

int main() {
	return 0;
}