// oper_overload.cpp

#include <string>
#include <iostream>

struct Vector {
    float x, y;
    Vector(float x, float y): x(x), y(y) {}
};

std::ostream& operator<<(std::ostream& stream, const Vector v) {
    stream << v.x << ", " << v.y;
    return stream;
}

int main() {
    Vector v(3.2f, 3.3f);
	std::cout << v << std::endl;
    return 0;
}