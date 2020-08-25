// variant_equality.cpp

#include <boost/variant.hpp>
#include <string>
#include <iostream>

// doesn't work: #define varied_type boost::variant<std::string, int, double, bool>

// does work: #define varied_type boost::variant<std::string, int>

// make to explicit std::string?

bool variant_equal(varied_type v, std::string normal) {
	return boost::get<std::string>(v) == normal;
	try {
		return boost::get<std::string>(v) == normal;
	}

	catch (boost::bad_get) {
		return false;
	}
}

int main() {
	varied_type bar = "foo";
	std::cout << variant_equal(bar, "foo") << std::endl;
	return 0;
}