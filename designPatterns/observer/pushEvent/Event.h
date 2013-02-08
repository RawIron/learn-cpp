#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>

class Event {
    public:
    Event() : name("testEvent") {};
    void print() const { std::cout << name; };
    private:
    std::string name;
};

#endif
