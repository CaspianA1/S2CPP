#include <stdlib.h>

// https://stackoverflow.com/questions/27852062/why-does-static-initialization-of-flexible-array-member-work

typedef struct {int possibleAtom, possibleLAT[];} Item;
typedef struct {struct Item* car;struct Item* cdr;} Pair;

Pair makePair(int possAtom1, int possAtom2, int possLat1[], int possLat2[]) {
	Item item1 = {possAtom1, possLat1};
	Item item2 = {possAtom2, possLat2};
	Pair pair = {item1, item2};
	return pair;
}

int main() {
	Pair p = makePair(1, 1, NULL, NULL);
}