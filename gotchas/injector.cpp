#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <iostream>
#include "injectee.h"


BOOST_AUTO_TEST_SUITE(inject)

BOOST_AUTO_TEST_CASE(func_assigns_static) {
	injectee::configure({{"max_count", "23"}});
    BOOST_TEST("23" == injectee::max_count());
}

BOOST_AUTO_TEST_SUITE_END()
