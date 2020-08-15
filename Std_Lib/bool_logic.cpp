#include "stdarg_macros.h"

// check for if function within main, and append an underscore to it
// and add the number of arguments to the functions (and for the math ones as well)

// must change

/*
template <typename RetType>
RetType if_(bool cond, RetType varA, RetType varB) {
	return cond ? varA : varB;
}
*/

#define _COND_CHECK(cond, res1, res2) cond ? res1 : res2
#define STD_IF _COND_CHECK
#define FUNCTION_IF return _COND_CHECK

bool and_(int nargs, ...) {
	INIT
	bool r = true;
	LOOP {if (!va_arg(args, int)) r = false;}
	DEINIT
}

bool or_(int nargs, ...) {
	INIT
	bool r = false;
	LOOP {if (va_arg(args, int)) r = true;}
	DEINIT
}

bool not_(bool cond) {
	return !cond;
}