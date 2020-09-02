// linked_list_from_list.cpp

#include <vector>
#include <iostream>

// hm, not working

using namespace std;

template <typename T>
struct LinkedList {
	T data; LinkedList<T>* next;
};

template <typename T>
LinkedList<T> linked_list_from_list(vector<T> list) {
	LinkedList<T> ll;
	T car = list[0];
	list.erase(list.begin());
	ll.data = car;
	if (list.size() > 0) {
		LinkedList<T> cdr = linked_list_from_list(list);
		ll.next = &cdr;
	}
	else
		ll.next = nullptr;
	return ll;
}

template <typename T>
void printLinkedList(LinkedList<T> linkedL) {
	std::cout << linkedL.data << ", ";

	LinkedList<T> next = *linkedL.next;
	if (next != nullptr)
		printLinkedList(next);

}

int main() {
	vector<int> pi {1, 2, 3, 4, 5};
	LinkedList<int> linkedPi = linked_list_from_list(pi);
	printLinkedList(linkedPi);
}