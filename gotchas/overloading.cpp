#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <iostream>

int f(int);
double f(double);

int f(int p) {
    return p+1;
}

double f(double p) {
    return p+1.3;
}


BOOST_AUTO_TEST_SUITE(overloading)

BOOST_AUTO_TEST_CASE(is_double) {
    double x = 100.5;
    BOOST_TEST(101.8 == f(x));
}

BOOST_AUTO_TEST_CASE(is_int) {
    int x = 100;
    BOOST_TEST(101 == f(x));
}

BOOST_AUTO_TEST_CASE(is_null) {
    // compiler error
    // BOOST_TEST(100 == f(NULL));
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(is_nullptr) {
    // compiler error
    // BOOST_TEST(100 == f(nullptr));
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END()
