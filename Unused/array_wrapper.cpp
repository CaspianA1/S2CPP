// array_wrapper.cpp

/*
#define SIZE 5

template <typename T>
struct Ray 
{ 
    T arr[]; 
};

typedef struct Ray Array;
*/

#include <vector>
#include "stdarg_macros.h"

// make it a class

#define Vec std::vector<T>

template <typename T>
class List {
	public:
		Vec vals;

		List(int nargs, ...) {
			INIT
			LOOP vals.push_back(va_arg(args, T));
			va_end(args);
		}


		Vec car() { // could return vector or single element
					// hm, nested lists???
			return vals[0];
		}

		Vec cdr() {
			std::vector<T> newVals;
			for (int i = 1; i < vals.size(); i++) {
				newVals.push_back(vals[i]);
			}
			return newVals;
		}

		T cons() {

		}

		~List() {

		}

};

int main() {
	
}