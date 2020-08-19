// memory_equality.cpp

#include <iostream>
using namespace std;

template <typename A>
bool eqv(A* a, A* b) {
    return a == b;
}

int main() {
    int a = 5;
    int* b = &a;

    cout << eqv(&a, b) << endl;
    
    return 0;
}