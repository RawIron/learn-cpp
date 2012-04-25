#include <boost/thread/thread.hpp>
#include <iostream>


class CallableClass {
public:
    explicit CallableClass(int first) : state_(first) {}
    void operator()() {
        state_ += 4;
        std::cout << state();
    }
    int state() { return state_; }
private:
    int state_;
};

struct callable {
    callable(int previous) : counter(previous) {}
    void operator()() {
        std::cout << "callable";
    }
    int counter;
};

void threadFunction () {
    std::cout << "nothing";
    boost::this_thread::yield();
}

void hello() {
  std::cout <<
    "Hello world, I'm a thread!"
    << std::endl;
}


void callClass() {
    CallableClass c(2);
    boost::thread t(c);
    t.join();
    std::cout << c.state();
}


int main() {
    boost::thread thrd(&hello);
    boost::thread t(&threadFunction);
    boost::thread c(callable(1));
    std::cout << "main";
    thrd.join();
    t.join();
    c.join();

    callClass();
}

