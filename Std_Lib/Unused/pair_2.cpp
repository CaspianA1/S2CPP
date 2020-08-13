// pair_2.cpp

// hm, needs template arguments
template <typename T>
struct ListElement {
	T atom, lat[]; // can be a list of in itself - but is a polymorphic type
	// made of ListElements? not sure
};

template <typename Atom, typename Lat>
ListElement<Atom> cons(Atom a, Lat b) {
	struct ListElement<Atom> l = {a, b};
	return l;
}

template <typename Atom>
ListElement<Atom> car(struct ListElement<Atom> list) {
	return list.atom == NULL ? list.lat : list.atom;
}

template <typename Lat>
ListElement<Lat> cdr(struct ListElement<Lat> list) {
	struct ListElement tail = {NULL, {}}
	// use malloc
	// when to free?
	// use vectors?

	// for (int i = 1; i < )
	// get tail elements
}

/*
#include <vector>

#define typename tn

cons: atom, list
car: atom
cdr: list
nested lists will be implemented later

template <tn T, tn Atom, tn Lat>
T cons(Atom a, Lat b) {

}
*/

// void pointer?