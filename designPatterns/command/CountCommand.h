#ifndef COUNTCOMMAND_H
#define COUNTCOMMAND_H
#include "CommandInterface.h"
#include "Counter.h"


class CountCommand : public Command {
public:
    explicit CountCommand(Counter *c) : receiver(c) {}
    void execute() const { receiver->incr(); }
    void undo() const { ; }
    void log() const { ; }
private:
    Counter *receiver;
};

#endif
