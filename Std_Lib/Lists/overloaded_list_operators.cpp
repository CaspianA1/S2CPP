#define asString(var, type) format(std::to_string(std::get<type>(var)))

#define compare()\
   std::string internalOrig;\
    if (std::holds_alternative<const char*>(orig)) {\
        std::string s(std::get<const char*>(orig));\
        internalOrig = s;\
    }\
    else if (std::holds_alternative<int>(orig))\
        internalOrig = asString(orig, int);\
    else if (std::holds_alternative<double>(orig))\
        internalOrig = asString(orig, double);\
    else if (std::holds_alternative<bool>(orig))\
        internalOrig = asString(orig, bool);\
    else if (std::holds_alternative<ListValue>(orig)) {\
        ListValue wrapped = std::get<ListValue>(orig);\
        switch (wrapped.t) {\
            case I: {\
                internalOrig = asString(wrapped.v, int);\
                break;\
            }\
            case D: {\
                internalOrig = asString(wrapped.v, double);\
                break;\
            }\
            case B: {\
                internalOrig = asString(wrapped.v, bool);\
                break;\
            }\
            case L: case S: case V: {\
                internalOrig = format(std::get<std::string>(wrapped.v));\
                break;\
            }\
        }\
    }\
    std::string internalCompareTo;\
    if (std::holds_alternative<const char*>(compareTo)) {\
        std::string s(std::get<const char*>(compareTo));\
        internalCompareTo = s;\
    }\
    else if (std::holds_alternative<int>(compareTo))\
        internalCompareTo = asString(compareTo, int);\
    else if (std::holds_alternative<double>(compareTo))\
        internalCompareTo = asString(compareTo, double);\
    else if (std::holds_alternative<bool>(compareTo))\
        internalCompareTo = asString(compareTo, bool);\
    else if (std::holds_alternative<ListValue>(compareTo)) {\
        ListValue wrapped = std::get<ListValue>(compareTo);\
        switch (wrapped.t) {\
            case I: {\
                internalCompareTo = asString(wrapped.v, int);\
                break;\
            }\
            case D: {\
                internalCompareTo = asString(wrapped.v, double);\
                break;\
            }\
            case B: {\
                internalCompareTo = asString(wrapped.v, bool);\
                break;\
            }\
            case L: case S: case V: {\
                internalCompareTo = format(std::get<std::string>(wrapped.v));\
                break;\
            }\
        }\
    }\
    return format(internalOrig) == format(internalCompareTo);\

std::ostream& operator<<(std::ostream& os, const ListValue& lv) {
    #define getType_Stream(type) os << std::get<type>(lv.v)
    switch (lv.t) {
        case I:
            getType_Stream(int);
            break;
        case D:
            getType_Stream(double);
            break;
        case B:
            getType_Stream(bool);
            break;
        case L: case S: case V:
            getType_Stream(std::string);
            break;
    }
    return os;
}

// + - * / % ++ -- += -= *= /= == != ! && || &, |, ^, ~

bool n() {
    // equal(==);
    return true;
}
// operDefB(>=);
// operDefB(<);
// operDefB(<=);


/*
operDef(-);
operDef(*);
operDef(/);
*/



/*
operDef(%);
operDef(++);
operDef(--);
operDef(+=);
operDef(-=);
operDef(*=);
operDef(/=);
operDef(==);
operDef(!=);
operDef(!);
operDef(&&);
operDef(||);
operDef(&,);
operDef(|,);
operDef(^,);
operDef(~);
*/



/*
// this is terribly boring and boilerplate code, but I'm not sure if there's a way around it
bool operator==(ComparableType orig, ComparableType compareTo) {
    std::string internalOrig;

    if (std::holds_alternative<const char*>(orig)) {
        std::string s(std::get<const char*>(orig));
        internalOrig = s;
    }
    else if (std::holds_alternative<int>(orig))
        internalOrig = asString(orig, int);
    else if (std::holds_alternative<double>(orig))
        internalOrig = asString(orig, double);
    else if (std::holds_alternative<bool>(orig))
        internalOrig = asString(orig, bool);
    else if (std::holds_alternative<ListValue>(orig)) {
        ListValue wrapped = std::get<ListValue>(orig);
        switch (wrapped.t) {
            case I: {
                internalOrig = asString(wrapped.v, int);
                break;
            }
            case D: {
                internalOrig = asString(wrapped.v, double);
                break;
            }
            case B: {
                internalOrig = asString(wrapped.v, bool);
                break;
            }
            case L: case S: case V: {
                internalOrig = format(std::get<std::string>(wrapped.v));
                break;
            }
        }
    }
    std::string internalCompareTo;

    if (std::holds_alternative<const char*>(compareTo)) {
        std::string s(std::get<const char*>(compareTo));
        internalCompareTo = s;
    }
    else if (std::holds_alternative<int>(compareTo))
        internalCompareTo = asString(compareTo, int);
    else if (std::holds_alternative<double>(compareTo))
        internalCompareTo = asString(compareTo, double);
    else if (std::holds_alternative<bool>(compareTo))
        internalCompareTo = asString(compareTo, bool);
    else if (std::holds_alternative<ListValue>(compareTo)) {
        ListValue wrapped = std::get<ListValue>(compareTo);
        switch (wrapped.t) {
            case I: {
                internalCompareTo = asString(wrapped.v, int);
                break;
            }
            case D: {
                internalCompareTo = asString(wrapped.v, double);
                break;
            }
            case B: {
                internalCompareTo = asString(wrapped.v, bool);
                break;
            }
            case L: case S: case V: {
                internalCompareTo = format(std::get<std::string>(wrapped.v));
                break;
            }
        }
    }
    return format(internalOrig) == format(internalCompareTo);
}

bool operator>(ComparableType orig, ComparableType compareTo) {
    manipulateInputTypes(>);
}
*/