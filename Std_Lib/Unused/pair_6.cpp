// pair_6.cpp
// singly-typed lists with no nested lists
// only integers for now

#include <stdlib.h>
#include <string>
#include "../stdarg_macros.h"

#define ALLOCATE(typenm) (typenm*) malloc(nargs)
#define ASSIGN(typenm) LOOP *internalList[i] = va_arg(args, typenm)

#define HANDLE_TYPE(typenm)\
		internalList = (typenm*) malloc(sizeof(typenm) * nargs);\
		LOOP internalList[i] = va_arg(args, typenm);\
		break;

typedef enum {INTEGER, FLO, STR} TYPE;

class List {
public:
	void* internalList;
	List(TYPE listType, int nargs, ...) {
		INIT
		switch (listType) {
			case INTEGER:
				HANDLE_TYPE(int)
				// internalList = ALLOCATE(int);
				// ASSIGN(int);
				// break;
			case FLO:
				// internalList = ALLOCATE(float);
				// ASSIGN(float);
				// break;
			case STR:
				// internalList = ALLOCATE(std::string);
				// ASSIGN(std::string);
				// break;
		}
		va_end(args);
	}

	~List() {
		free(internalList);
	}
};

// if this is too hard, then pair_4 could work (never mind, it's too clumsy)
// what to do, what to do

int main() {
	// List l(STR, 4, 1, 2, 3, 4);
	return 0;
}

// https://gist.github.com/ofan/721464/e1893899739abf7f3e4167bbb722b0420799047f