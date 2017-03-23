#include <iostream>

int f(int);
double f(double);
double add_f(double);

int f(int p) {
    return p+1;
}

double f(double p) {
    return p+1.3;
}

double add_f(double p) {
    return p+(f(1)+f(1.0));
}


int main() {
    double a;
    a = add_f(100.5);
    std::cout << a << std::endl;
}

