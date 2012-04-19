#include <boost/thread/thread.hpp>
#include <iostream>


class Counter {
public:
    Counter() : balance_(0) {}
    void incr() { ++balance_; }
    int balance() const { return balance_; }
private:
    int balance_;
};


class Command {
public:
    virtual void execute() const = 0;
    virtual void undo() const = 0;
    virtual void log() const = 0;
};

class CountCommand : public Command {
public:
    explicit CountCommand(Counter *c) : receiver(c) {}
    void execute() const { receiver->incr(); }
    void undo() const { ; }
    void log() const { ; }
private:
    Counter *receiver;
};


class Runnable {
public:
    explicit Runnable(int first) : state_(first), up_(true), t(0) {}
    void run() {
        t = new boost::thread(boost::ref(*this));
    }
    void stop() {
        up(false);
        t->join();
    }
    void up(bool is) {
        mx.lock();
        up_ = is;
        mx.unlock();
    }
    void operator()() {
        while(up_) {
            state_ += 4;
            boost::this_thread::sleep(boost::posix_time::millisec(80));
            std::cout << state();
        }
    }
    int state() { return state_; }
private:
    boost::thread *t;
    boost::mutex mx;
    bool up_;
    int state_;
};


int main() {
    Runnable c(2);
    c.run();
    boost::this_thread::sleep(boost::posix_time::millisec(680));
    c.stop();
    std::cout << c.state();

    Counter co;
    CountCommand comm(&co);
    comm.execute();
    std::cout << co.balance();
}

