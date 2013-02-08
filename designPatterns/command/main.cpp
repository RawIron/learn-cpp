#include <iostream>

#include "CountCommand.h"
#include "Counter.h"
#include "Invoker.h"

int main() {
    Counter co;
    CountCommand comm(&co);
    Invoker runner;

    runner.give(&comm);
    runner.run();
    std::cout << co.balance();
}

