#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <cstddef>

typedef std::string state_t;
typedef std::string event_t;


class cleaner_interface {
    virtual state_t clean(event_t event) = 0;
};


class cleaner : public cleaner_interface {
public:
    cleaner() : state_("idle") {};
    virtual ~cleaner() {};
    virtual state_t clean(event_t event);
private:
    static const std::string name_;
    state_t state_;
};

const std::string cleaner::name_ = "cleaner";

state_t cleaner::clean(event_t event) {
    state_ = event;
    return state_;
}


class cleaner_buy : public cleaner {
public:
    cleaner_buy() : event_history(), state("idle_buyer") {};
    virtual ~cleaner_buy() {};
    virtual state_t clean(event_t event);
    virtual state_t replay(state_t using_state, std::size_t from_pos);
    std::string to_str() const;
private:
    std::vector<event_t> event_history;
    std::vector<event_t>::const_iterator c_it;
    state_t state;
};

state_t cleaner_buy::clean(event_t event) {
    event_history.push_back(event);
    return state;
}

state_t cleaner_buy::replay(state_t using_state, std::size_t from_pos) {
    c_it = event_history.cbegin() + from_pos;
    return using_state;
}

std::string cleaner_buy::to_str() const {
    return state;
}


BOOST_AUTO_TEST_SUITE(inheritance)

BOOST_AUTO_TEST_CASE(call_virtual_override) {
    const event_t event = R"<<({"name": "buy"})<<";
    cleaner_buy cb;
    BOOST_TEST("idle_buyer" == cb.clean(event));
}

BOOST_AUTO_TEST_CASE(call_virtual_override_on_base) {
    const event_t event = R"<<({"name": "sell"})<<";
    cleaner_buy cb;
    cleaner* cp = &cb;
    BOOST_TEST("idle_buyer" == cp->clean(event));
}

BOOST_AUTO_TEST_SUITE_END()
