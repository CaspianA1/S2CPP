// list_primitives.cpp

// hm, soo messy

template <typename Var>
Var car(Var lst) {
	return lst[0];
}

template <typename Var>
Var cdr(Var lst) {
	const int length = sizeof(lst) / sizeof(lst[0]);

	Var* tailOfLst = malloc(sizeof(lst) * sizeof(lst[0]) - sizeof(lst[0]));

	for (int i = 1; i < length; i++) {
		tailOfLst[i - 1] = lst[i];
	}
	return *tailOfLst;
}

template <typename Var>
Var cons() {
	// 2 params
}


int main() {

	return 0;
}