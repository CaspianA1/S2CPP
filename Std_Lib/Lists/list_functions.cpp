#include "lists.cpp"

/*
NOTE:
Strings are not supported as of now.
*/

#include "overloaded_list_operators_3.cpp"

ListValue car(std::variant<std::string, ListValue> expr) {
	std::string internalExpr;

	if (std::holds_alternative<ListValue>(expr)) {
		ListValue wrapped = std::get<ListValue>(expr);

		switch (wrapped.t) {
			case I: {
				internalExpr = asString(wrapped.v, int);
				break;
			}
			case D: {
				internalExpr = asString(wrapped.v, double);
				break;
			}
			case B: {
				internalExpr = asString(wrapped.v, bool);
				break;
			}
			case L: case S: case V: {
				internalExpr = format(std::get<std::string>(wrapped.v));
				break;
			}
		}
	}
	else
		internalExpr = format(std::get<std::string>(expr));

	std::string charBuf;
	bool inString = false;

	if (internalExpr[1] == '(') {
		unsigned int lParens = 0, rParens = 0;

		for (int i = 1; i < internalExpr.size(); i++) {
			char currChar = internalExpr[i];

			if (currChar == '\"') {
				if (!inString) {
					inString = true;
					charBuf += currChar;
				}
				else {
					inString = false;
					charBuf += currChar;
					return getValueType(charBuf);
				}
			}
			else if (!inString) {
				if (currChar == '(')
					lParens++;
				else if (currChar == ')')
					rParens++;

				charBuf += currChar;

				if (lParens == rParens)
					return getValueType(format(charBuf));
			}
		}
	}

	for (int i = 1; i < internalExpr.size(); i++) {
		char currChar = internalExpr[i];

		if (currChar == '\"') {
			if (!inString) {
				inString = true;
				charBuf += currChar;
			}
			else {
			inString = false;
				charBuf += currChar;
			}
		}
		else if (!inString) {
			if (currChar == ' ')
				break;
			else
				charBuf += currChar;
		}
	}
	return getValueType(format(charBuf));
}


ListValue cdr(std::variant<std::string, ListValue> expr) {
	print("In cdr");
	std::string internalExpr;

	if (std::holds_alternative<ListValue>(expr)) {
		ListValue wrapped = std::get<ListValue>(expr);

		switch (wrapped.t) {
			case I: {
				internalExpr = asString(wrapped.v, int);
				break;
			}
			case D: {
				internalExpr = asString(wrapped.v, double);
				break;
			}
			case B: {
				internalExpr = asString(wrapped.v, bool);
				break;
			}
			case L: case S: case V: {
				internalExpr = format(std::get<std::string>(wrapped.v));
				break;
			}
		}
	}
	else
		internalExpr = format(std::get<std::string>(expr));

	ListValue head = car(internalExpr);

	std::string internalHead;
		
	switch (head.t) {
		case I: {
			internalHead = asString(head.v, int);
			break;
		}
		case D: {
			internalHead = asString(head.v, double);
			break;
		}
		case B: {
			internalHead = asString(head.v, bool);
			break;
		}
		case L: case S: case V: {
			internalHead = format(std::get<std::string>(head.v));
			break;
		}
	}

	std::string tail = "(";

	for (int i = internalExpr.find(internalHead) + internalHead.size(); i < internalExpr.size(); i++) {
		tail += internalExpr[i];
	}

	tail = format(tail);

	std::cout << tail << std::endl;

	ListValue wrappedTail = getValueType(tail);

	

	if (wrappedTail.t == L) {
		std::string tailWithoutParens;

		for (int i = 1; i < tail.length() - 1; i++)
			tailWithoutParens += tail[i];


		if (tailWithoutParens[0] != '\"' && tailWithoutParens.back() != '\"'
			&& tail.find(' ') == std::string::npos)
			return getValueType(tailWithoutParens);	
	}
	return wrappedTail;
}


ListValue cons(std::variant<std::string, ListValue> head, std::variant<std::string, ListValue> tail) {
	std::string internalHead, internalTail;

	if (std::holds_alternative<ListValue>(head)) {
		print("Head is a ListValue");
		ListValue wrapped = std::get<ListValue>(head);

		switch (wrapped.t) {
			case I: {
				internalHead = asString(wrapped.v, int);
				break;
			}
			case D: {
				internalHead = asString(wrapped.v, double);
				break;
			}
			case B: {
				internalHead = asString(wrapped.v, bool);
				break;
			}
			case L: case S: case V: {
				internalHead = format(std::get<std::string>(wrapped.v));
				break;
			}
		}
	}
	else {
		print("Head is a string");
		internalHead = format(std::get<std::string>(head));
	}

	if (std::holds_alternative<ListValue>(tail)) {
		print("Tail is a ListValue");
		ListValue wrapped = std::get<ListValue>(tail);

		switch (wrapped.t) {
			case I: {
				internalTail = asString(wrapped.v, int);
				break;
			}
			case D: {
				internalTail = asString(wrapped.v, double);
				break;
			}
			case B: {
				internalHead = asString(wrapped.v, bool);
				break;
			}
			case L: case S: case V: {
				print("Internal tail assigned to varied type");
				internalTail = format(std::get<std::string>(wrapped.v));
				print2("Internal tail: ", internalTail);
				break;
			}
		}
	}
	else {
		print("Tail is a string");
		internalTail = format(std::get<std::string>(tail));
	}

	std::string pair = "(" + internalHead + " ";

	print2("Internal tail: ", internalTail);

	print2("Pre-pair: ", pair);

	if (internalTail[0] == '(') {
		for (int i = 1; i < internalTail.size(); i++)
		pair += internalTail[i];
	}

	else {
		for (int i = 0; i < internalTail.size(); i++)
			pair += internalTail[i];
		pair += ")";
	}
	
	print2("Post pair: ", pair);

	return getValueType(format(pair));

}

// theoretical makeListValue function = getValueType


int main() {
	ListValue head = car(getValueType("(1.2 2 3)"));

	double pi = 3.1415926535;

	// double r = pi + head;

	// bool result = pi > head;
	// print(result);

	// doesn't work:
	// double result = head + pi;

	/*
	overload math and boolean operators
	+ - * / // % ++ -- += -= != > < >= <= && || 
	*/

	// After that, integrate this code with the Python side of things
}
