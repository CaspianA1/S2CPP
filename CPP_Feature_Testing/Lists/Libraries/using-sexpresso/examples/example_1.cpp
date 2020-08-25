#define SEXPRESSO_OPT_OUT_PIKESTYLE
#ifdef SEXPRESSO_OPT_OUT_PIKESTYLE
#ifndef SEXPRESSO_HEADER
#define SEXPRESSO_HEADER
#include <vector>
#include <string>
#include <cstdint>
#include "../sexpresso/sexpresso/sexpresso.cpp"
#endif
#endif

#include <iostream>
#define print(var) std::cout << var << std::endl;

/*
auto car(auto tree) {

}

auto cdr(auto tree) {
    
}
*/

// find the executable from the other library - maybe

int main() {
    // std::string expression = " (define x (* 5 3 (+ 2 2)))";
    auto expression = "(my-values bob (sweet baby jesus) (hi mom) just-a-thing)";
    auto parsetree = sexpresso::parse(expression);
    print(parsetree.childCount());
}