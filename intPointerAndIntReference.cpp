#include <iostream>

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

int g(const int &a) {
    std::cout << "g(const int&)";
    return a;
}


int main() {
    int r;
    int x = 1;
    int y = 2;
    int* py = &y;
    int& ry = y;

    r = f(x);
    std::cout << r << std::endl;
    std::cout << x << std::endl;
    r = f(py);
    std::cout << r << std::endl;
    std::cout << y << std::endl;
    r = f(ry);
    std::cout << r << std::endl;
    std::cout << y << std::endl;

    r = g(ry);
    std::cout << r << std::endl;
    std::cout << y << std::endl;

    r = g(y);
    std::cout << r << std::endl;
    std::cout << y << std::endl;
}

