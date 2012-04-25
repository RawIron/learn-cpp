#include <vector>
#include <iostream>


struct stlVector {
    std::vector<int> v;
    std::vector<int>::iterator it;

    explicit stlVector(int initValue) : v(5,initValue) {}
    stlVector() : v() {}

    void expectMedium() {
        v.reserve(10);
    }
    void insert(int id) {
        std::cout << v.capacity() << std::endl;
        it = v.begin();
        v.push_back(id);
        std::cout << v.capacity() << std::endl;
        printCurrent();
    }

    void printCurrent() const {
        std::cout << *it << std::endl;
    }
    void print() {
        for (it = v.begin(); it != v.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
};


int main() {
    stlVector s;
    s.expectMedium();
    s.insert(4);
    s.print();
}

