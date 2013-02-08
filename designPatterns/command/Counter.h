#ifndef COUNTER_H
#define COUNTER_H


class Counter {
public:
    Counter() : balance_(0) {}
    void incr() { ++balance_; }
    int balance() const { return balance_; }
private:
    int balance_;
};

#endif
