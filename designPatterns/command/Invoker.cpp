#include "Invoker.h"


void Invoker::give(const Command *comm) {
    comms.push(comm);
}

void Invoker::run() {
    const Command *comm;
    while(!comms.empty()) {
        comm = comms.front();
        comm->execute();
        comms.pop();
    }
}

