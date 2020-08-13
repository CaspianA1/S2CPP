#include <string>
#include <iostream>
#include <boost/any.hpp>

#define cast(tn) stream << boost::any_cast<tn>(WT.internalVar);\
				 return stream

// string, boolean, integer, float;
typedef enum {S, B, I, F} Datatype;

// won't work with arrays
class Atom {
	public:
		boost::any internalVar;
		Datatype storedType;
		Atom (Datatype datatype, std::string varVal) {
			storedType = datatype;
			switch (datatype) {
				case S:
					internalVar = varVal;
					break;
				case B:
					if (varVal == "#t")
						internalVar = true;
					else if (varVal == "#t")
						internalVar = false;	
					break;
				case I:
					internalVar = std::stoi(varVal);
					break;
				case F:
					internalVar = std::stof(varVal);
					break;
				default:
					std::cerr << "Bad datatype provided: " << varVal << std::endl;
			}
		}

		// make a getter function that just gets the variable normally

		static Atom make(Datatype datatype, std::string varVal) {
			Atom newWrapped(datatype, varVal);
			return newWrapped;
		}
};

std::ostream& operator<<(std::ostream& stream, const Atom& WT) {
	switch (WT.storedType) {
		case S: cast(std::string);
		case B: cast(bool);
		case I: cast(int);
		case F: cast(float);
	}
	std::cerr << "Bad Atom provided to stream operator" << std::endl;
}

/*
int main() {
	WrappedType listOfWrapped[] = {WrappedType::make(S, "a string"), WrappedType::make(B, "#t")};

	WrappedType bob(S, "I am Bob");
	WrappedType iLikePancakes(B, "#t");
	WrappedType myAge(I, "17");
	WrappedType pi(F, "3.1415926535");

	std::cout << bob << ", " << iLikePancakes << ", " << myAge << ", " << pi << std::endl;k

	return 0;
}
*/