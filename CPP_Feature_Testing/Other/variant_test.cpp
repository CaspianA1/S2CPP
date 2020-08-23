// variant_test.cpp

#include <boost/variant.hpp>

typedef struct {int foo, bar;} Example;

int main() {
	boost::variant<int, Example*> var;

	var = 5;

	Example ex;
	var = ex;
}