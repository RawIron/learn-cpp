#include <iostream>

void pp(const int before, const int y, const int r) {
    std::cout << std::endl;
    std::cout << before << " -> ";
    std::cout << "(" << y << "," << r << ")" << std::endl;
}

int f(int a) {
    std::cout << "f(int)";
    a += 5;
    return a;
}

int f(int* a) {
    std::cout << "f(int*)";
    *a += 3;
    return *a;
}

int gc(const int& a) {
    std::cout << "gc(const int&)";
    return a;
}

int g(int& a) {
    std::cout << "g(int&)";
    a += 5;
    return a;
}


int main() {
    int r;
    int before;
    int x = 1;
    int y = 2;
    int* py = &y;
    int& ry = y;

    std::cout << "int -> ";
    before = y;
    r = f(x);
    pp(before, y, r);

    std::cout << "int* -> ";
    before = y;
    r = f(py);
    pp(before, y, r);

    std::cout << "int& -> ";
    before = y;
    r = f(ry);
    pp(before, y, r);

    std::cout << "int& -> ";
    before = y;
    r = gc(ry);
    pp(before, y, r);

    std::cout << "int -> ";
    before = y;
    r = gc(y);
    pp(before, y, r);

    std::cout << "int -> ";
    before = y;
    r = g(y);
    pp(before, y, r);

    std::cout << "int& -> ";
    before = y;
    r = g(ry);
    pp(before, y, r);
}

