// quoting.cpp

#include <iostream> // remove later
#include <vector> // not used right now
#include <string> // may not be needed
#include "../Std_Lib/stdarg_macros.h"
#include "../Std_Lib/generic_wrapped_type.cpp"

// not directly related
#define define(var, val) auto var = val
#define quote(val) #val
#define display(var) std::cout << var
#define newline() std::cout << std::endl
#define car(lat) lat[0]
#define cons(head, tail) {head, tail}

// make a list tree class

// this didn't work  out as I thought it would
class List {
	public:
		Atom r[]; // use vector?
		unsigned int length;
		Datatype subtype;

		template <typename T>
		static List make(int nargs, ...) {
			length = nargs;
			r = new Atom[nargs];
			INIT

			LOOP {
				if (i == 0) {
					T firstVal = va_arg(args, T);

					switch (firstVal) {
						case "#t": case "#f":
							subtype = B;
							break;  // do something here
						default:
							switch (typeid(firstVal).name()) {
							case "int": // actual type names will not be descriptive
								subtype = I;
								break;
							case "float":
								subtype = F;
								break;
							case "string":
								subtype = S;
								break;
							default:
								std::cerr << "Invalid type provided to List::Make";
						}
					}
					r[0] = Atom::make(subtype, (std::string) firstVal);
				}
				else {
					r[i] = Atom::make(subtype, (std::string) va_arg(args, T));
				}
			}
		}

		friend std::ostream& operator<<(std::ostream& stream, const List& lat) {
			stream << "(";
			for (int i = 0; i < lat.length; i++)
				stream << lat.r[i] << i != lat.length - 1 ? " " : ")";

			return stream;
		}		

		~List() {
			delete r;
		}

};


int main() {
	// define(x, 5);
	// display(quote(x));
	// display(quote({1, 2, 3, 4, 5})) // does not work
	return 0;
}