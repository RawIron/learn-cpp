#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include <iostream>

typedef std::string state_t;
typedef std::string event_t;


class cleaner_interface {
    virtual state_t clean(event_t event) = 0;
};


class cleaner : public cleaner_interface {
public:
    cleaner() : state_("idle") {};
    virtual state_t clean(std::string event);
    std::string print() const;
private:
    static const std::string name_;
    state_t state_;
};

const std::string cleaner::name_ = "cleaner";

state_t cleaner::clean(std::string event) {
    state_ = event;
    return state_;
}

std::string cleaner::print() const {
    return "base class";
}


class cleaner_buy : public cleaner {
public:
    cleaner_buy() : event("{}"), state("idle") {};
    virtual state_t clean(event_t event);
    std::string print() const;
private:
    std::string event;
    state_t state;
};

state_t cleaner_buy::clean(event_t event) {
    (*this).event = event;
    return state;
}

event_t cleaner_buy::print() const {
    return event;
}


BOOST_AUTO_TEST_SUITE(inheritance)

BOOST_AUTO_TEST_CASE(virtual_override) {
    const event_t event = R"<<<({"name": "buy"})<<<";
    cleaner_buy cb;
    BOOST_TEST("idle" == cb.clean(event));
}

BOOST_AUTO_TEST_CASE(virtual_override_on_base) {
    const event_t event = R"<<<({"name": "sell"})<<<";
    cleaner_buy cb;
    cleaner* cp = &cb;
    BOOST_TEST("idle" == cp->clean(event));
}

BOOST_AUTO_TEST_SUITE_END()
