// print_ll.cpp

  std::visit([](const auto &elem) { std::cout << elem << '\n'; }, value);

  /*
void printLinkedList(varied_type pair) {
	std::cout << "|";
	switch (pair.head.which()) {
		case 0:
			std::cout << getRawType(std::string, pair.head) << ", "; break;
		case 1:
			std::cout << getRawType(int, pair.head) << ", "; break;
		case 2:
			std::cout << getRawType(double, pair.head) << ", "; break;
		case 3:
			std::cout << getRawType(bool, pair.head) << ", "; break;
		case 4:
			printLinkedList(pair.head); break;
	}
	switch (pair.tail.which()) {
		case 0:
			std::cout << getRawType(std::string, pair.tail) << ", "; break;
		case 1:
			std::cout << getRawType(int, pair.tail) << ", "; break;
		case 2:
			std::cout << getRawType(double, pair.tail) << ", "; break;
		case 3:
			std::cout << getRawType(bool, pair.tail) << ", "; break;
		case 4:
			std::cout << "| ->";
			printLinkedList(getRawType(Pair*, pair.tail));
	}
}
*/

  /*
void printVariedType(std::string message, const varied_type& v) {
	std::cout << message;
	switch (v.which()) {
		case 0: print(getRawType(std::string, v)); break;
		case 1: print(getRawType(int, v)); break;
		case 2: print(getRawType(double, v)); break;
		case 3: print(getRawType(bool, v)); break;
	}
}
*/

/*
void printVector(std::string message, const std::vector<varied_type>& v) {
	std::cout << message;
	for (int i = 0; i < v.size(); i++)
		switch (v[i].which()) {
		case 0: std::cout << getRawType(std::string, v[i]) << ", "; break;
		case 1: std::cout << getRawType(int, v[i]) << ", "; break;
		case 2: std::cout << getRawType(double, v[i]) << ", "; break;
		case 3: std::cout << getRawType(bool, v[i]) << ", "; break;
	}
	std::cout << std::endl;
}
*/