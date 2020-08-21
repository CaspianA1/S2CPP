#include <string>
#include <iostream>
#include <boost/any.hpp>

#define cast_var(tn) return boost::any_cast<tn>(internalVar);
#define cast_stream(tn) stream << boost::any_cast<tn>(WT.internalVar);

// string, boolean, integer, float;
typedef enum {S, B, I, F} Datatype;

// won't work with arrays
class Generic {
	public:
		boost::any internalVar;
		Datatype storedType;
		Generic (Datatype datatype, std::string varVal) {
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

		template <typename T>
		T get() {
			switch (storedType) {
				case S: cast_var(std::string);
				case B: cast_var(bool);
				case I: cast_var(int);
				case F: cast_var(float);
			}
		}

		// WT, as in WrappedType
		friend std::ostream& operator<<(std::ostream& stream, const Generic& WT) {
			switch (WT.storedType) {
				case S: cast_stream(std::string);
				case B: cast_stream(bool);
				case I: cast_stream(int);
				case F: cast_stream(float);
			}
			return stream;
		}

		// make a getter function that just gets the variable normally

		static Generic make(Datatype datatype, std::string varVal) {
			Generic newWrapped(datatype, varVal);
			return newWrapped;
		}
};

/*
// could make friend function
std::ostream& operator<<(std::ostream& stream, const Generic& WT) {
	switch (WT.storedType) {
		case S: cast_stream(std::string);
		case B: cast_stream(bool);
		case I: cast_stream(int);
		case F: cast_stream(float);
	}
	return stream;
}
*/

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

/*
int main() {

}
*/