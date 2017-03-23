#pragma once
#include <array>
#include <iostream>


void stdArray() {
    std::array<int,3> a = {3, 4, 7};
    for (auto i: a) {
        std::cout << i;
    }
}


int main() {
    stdArray();
}

