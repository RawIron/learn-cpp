#include <iostream>

int f(int * const a) {
    for (int *p = a; p < &a[3]; ++p) {
        std::cout << *p << std::endl;
    }
}

int f2(const int a[]) {
    for (int *p = a; p < &a[3]; ++p) {
        std::cout << *p << std::endl;
    }
}

int g(const int *a) {
    for (int i = 0; i < 3; ++i, ++a) {
        std::cout << *a << std::endl;
    }
}

int g2(int *const a) {
    for (int i = 0; i < 3; ++i, ++a) {
        std::cout << *a << std::endl;
    }
}


int main() {
    int a[] = {1,2,3};
    int b;

    b = f(a);
    b = g(a);
}
