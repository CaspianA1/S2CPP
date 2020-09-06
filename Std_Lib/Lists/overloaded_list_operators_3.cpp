#define oper(operator, orig, compareTo)\
	float internalOrig;\
	if (std::holds_alternative<ListValue>(orig)) {\
		\
	}\
		\
	else {\
		\
	}\

#define convertType(var, type) std::get<type>(var)


float internalOrig;
if (std::holds_alternative<ListValue>(orig)) {
	ListValue wrapped;

	// base work on assumption that with an operator, the ListValue var will be a number
	// but give it a rest for now, and work on something else
}

// frustrating