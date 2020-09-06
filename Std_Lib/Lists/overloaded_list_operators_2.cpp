// overloaded_list_operators_2.cpp

#define convertType(var, type) std::get<type>(var)

#define compare(oper, convertTo1, convertTo2)\
 convertTo1 internalOrig;\
    if (std::holds_alternative<const char*>(orig)) {\
        std::string s(std::get<const char*>(orig));\
        internalOrig = s;\
    }\
    else if (std::holds_alternative<int>(orig))\
        internalOrig = convertType(orig, int);\
    else if (std::holds_alternative<double>(orig))\
        internalOrig = convertType(orig, double);\
    else if (std::holds_alternative<bool>(orig))\
        internalOrig = convertType(orig, bool);\
    else if (std::holds_alternative<ListValue>(orig)) {\
        ListValue wrapped = std::get<ListValue>(orig);\
        switch (wrapped.t) {\
            case I: {\
                internalOrig = convertType(wrapped.v, int);\
                break;\
            }\
            case D: {\
                internalOrig = convertType(wrapped.v, double);\
                break;\
            }\
            case B: {\
                internalOrig = convertType(wrapped.v, bool);\
                break;\
            }\
            case L: case S: case V: {\
                internalOrig = format(std::get<std::string>(wrapped.v));\
                break;\
            }\
        }\
    }\
    convertTo2 internalCompareTo;\
    if (std::holds_alternative<const char*>(compareTo)) {\
        std::string s(std::get<const char*>(compareTo));\
        internalCompareTo = s;\
    }\
    else if (std::holds_alternative<int>(compareTo))\
        internalCompareTo = convertType(compareTo, int);\
    else if (std::holds_alternative<double>(compareTo))\
        internalCompareTo = convertType(compareTo, double);\
    else if (std::holds_alternative<bool>(compareTo))\
        internalCompareTo = convertType(compareTo, bool);\
    else if (std::holds_alternative<ListValue>(compareTo)) {\
        ListValue wrapped = std::get<ListValue>(compareTo);\
        switch (wrapped.t) {\
            case I: {\
                internalCompareTo = convertType(wrapped.v, int);\
                break;\
            }\
            case D: {\
                internalCompareTo = convertType(wrapped.v, double);\
                break;\
            }\
            case B: {\
                internalCompareTo = convertType(wrapped.v, bool);\
                break;\
            }\
            case L: case S: case V: {\
                internalCompareTo = format(std::get<std::string>(wrapped.v));\
                break;\
            }\
        }\
    }\
    if (typeid(internalOrig) == typeid(std::string) && typeid(internalCompareTo) == typeid(std::string))\
    	return format(internalOrig) oper format(internalCompareTo);\
    else\
    	return internalOrig oper internalCompareTo;\

// make types templates sometime?

#define operDef(oper, typeOne, typeTwo, returnValue)\
    returnValue operator oper (typeOne orig, typeTwo compareTo) {\
    	compare(oper, typeOne, typeTwo);\
    }\

// operDef(>, ListValue, int, bool)


bool operator + (ListValue orig, ListValue compareTo) {
    	compare(oper, orig, compareTo);
    	// return true;
    }
