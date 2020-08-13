// pair.cpp

template <typename A, typename B>
struct Pair {
	A head;
	B tail;
};

template <typename T, typename A, typename B>
T car(struct Pair<A, B> pair) {
	return pair.head;
}

template <typename T, typename A, typename B>
T cdr (struct Pair<A, B> pair) {
	return pair.tail;
}

template <typename A, typename B>
struct Pair<A, B> cons(A head, B tail) {
	struct Pair<A, B> pair = {head, tail};
	return pair;
}

// lists must be defined at a top-level (b/c of templates)
template <typename A, typename B>
struct Pair<A, B> link = {5, false};

// make a macro for this
template <typename A, typename B>
// struct Pair<A, B> furtherLink = {link, "hello!"};
auto furtherLink = {link, "hello!"};
// infer template arguments?
// make a helper function to generate a template

// http://programminggenin.blogspot.com/2012/10/cons-lists-in-c.html
// lists should be typed to begin with
// try this out? https://www.boost.org/doc/libs/1_60_0/libs/fusion/doc/html/fusion/container/cons.html
// one last one that can maybe help: http://sandbox.mc.edu/~bennet/cs404/doc/tomslsp/code/builtinDESC.html

int main() {
	return 0;
}
