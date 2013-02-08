#ifndef INVOKER_H
#define INVOKER_H

#include <queue>
#include "CommandInterface.h"


class Invoker {
public:
    void give(const Command *comm);
    void run();
private:
    std::queue<const Command *> comms;
};

#endif
