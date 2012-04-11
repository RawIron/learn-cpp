#include <iostream>
#include <boost/thread/thread.hpp>

void threadFunction () {
    std::cout << "nothing";
    boost::this_thread::yield();
}

int main() {
    boost::thread t(&threadFunction);

    std::cout << "main";
}
