// list_declarations.hpp

#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>

// std::variant can't hold references

struct Pair {
	boost::variant<std::string, int, double, bool, struct Pair*> head;
	boost::variant<std::string, int, double, bool, struct Pair*> tail;
};

typedef struct Pair Pair;

// remove some of these macros later - it's too messy
#define varied_type boost::variant<std::string, int, double, bool, Pair>
#define print(var) std::cout << var << std::endl
// #define hasType(type, var) std::holds_alternative<type>(var) // fix
// #define hasType(type, var) typeid(var).name() == typeid(type).name()
#define getRawType(type, var) boost::get<type>(var)
#define printWrapped(type, var) std::cout << getRawType(type, var) // fix
// #define wrappedEqual(type, wrappedVar, unwrappedVar) getRawType(type, wrappedVar) == unwrappedVar // fix
#define NO_CAST std::bad_variant_access& // fix
#define type(var) typeid(var).name()