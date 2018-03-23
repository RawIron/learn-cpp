#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

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

    int current() const {
        return *it;
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


BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_CASE(insert_is_current) {
    stlVector s;
    s.expectMedium();
    s.insert(4);
    BOOST_TEST(4 == s.current());
}

BOOST_AUTO_TEST_SUITE_END()
