#include <stdio.h>
#include <string>

// hm, it didn't work as expected

using namespace std;

#define w <algorithm>

#include w

/*
void incl(string FILENAME) {
	// #include <algorithm>
	#include "%s", FILENAME
}
*/

int main() {
	// incl("generic.cpp");

	#include <vector>
	// inline #include <vector>
	return 0;
}