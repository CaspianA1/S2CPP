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

int main() {
    auto expr = "(a b (c d e))";
    auto parsed = sexpresso::parse(expr);
    auto child = parsed.getChildByPath("a");
    print(child -> toString());

    auto expr2 = "(my-values (sweet baby jesus) (hi mom) just-a-thing)";
    auto parsed2 = sexpresso::parse(expr2);
    auto child2 = parsed2.getChildByPath("my-values/sweet");
    print(child2 -> toString());
}
