#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <vector>
#include <iostream>


struct stlVector {
private:
    std::vector<int> v_;
    std::vector<int>::iterator it_;

public:
    explicit stlVector(int initValue) : v_(5,initValue) {}
    stlVector() {}
    virtual ~stlVector() {}

    int reserveMedium() {
        v_.reserve(10);
        return v_.capacity();
    }

    void insert(int id) {
        v_.push_back(id);
        it_ = v_.begin();
    }

    int current() const {
        return *it_;
    }

    int capacity() const {
        return v_.capacity();
    }

    void printCurrent() const {
        std::cout << *it_ << std::endl;
    }
    void print() {
        for (it_ = v_.begin(); it_ != v_.end(); ++it_) {
            std::cout << *it_ << std::endl;
        }
    }
};


BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_CASE(insert) {
    std::vector<int> s;
    s.push_back(4);
    BOOST_TEST(4 == *(s.begin()));
}

BOOST_AUTO_TEST_CASE(inserted_is_current) {
    stlVector s;
    s.insert(4);
    BOOST_TEST(4 == s.current());
}

BOOST_AUTO_TEST_CASE(capacity_is_updated) {
    stlVector s;
    BOOST_TEST(0 == s.capacity());
}

BOOST_AUTO_TEST_SUITE_END()
