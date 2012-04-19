#include <boost/thread/thread.hpp>
#include <iostream>

class Callable {
public:
    Callable(int first) : state_(first) {}
    void operator()() {
        state_ += 4;
        std::cout << state();
    }
    int state() { return state_; }
private:
    int state_;
};


int main() {
    Callable c(2);
    boost::thread t(c);
    t.join();
    std::cout << c.state();
}

