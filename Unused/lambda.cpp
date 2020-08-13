// lambda.cpp

#include <boost>
#include <string>
#include <unistd.h>

// actually, just use native c++ lambda functions
class Lambda {
public:
	boost::any inputs;
	std::string body;

	Lambda(boost::any inputs, std::string body) {
		this.inputs = inputs;
		this.body = body;
	}

	template <typename ReturnType>
	ReturnType call() { // params here
		exec(body);
	}

	std::string to_string() {

	}

	~Lambda() {
		// destructor
		// not sure how to use this yet
	}
}