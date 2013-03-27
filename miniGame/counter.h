#ifndef COUNTER_H
#define COUNTER_H

class Counter {
    public:
    Counter();
    int increase();
    int increase(int);
    int getCurrent();

    private:
    int current;
    long totalIn;
    long totalOut;
};

Counter counterFactory();

#endif
