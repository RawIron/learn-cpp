#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

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

BOOST_AUTO_TEST_SUITE(overloading)

BOOST_AUTO_TEST_CASE( test_is_double )
{
    double a = 104.8;
    BOOST_TEST(a == add_f(100.5));
}

BOOST_AUTO_TEST_SUITE_END()
