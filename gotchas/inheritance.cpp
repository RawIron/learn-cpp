#include <string>
#include <iostream>


class cleaner_interface {
    virtual bool clean(std::string event) = 0;
};


class cleaner : public cleaner_interface {
    public:
    virtual bool clean(std::string event);
    std::string print();
};

bool cleaner::clean(std::string data) {
    return "cleaned";
}

std::string cleaner::print() {
    return "base class";
}


class cleaner_buy : public cleaner {
    public:
    virtual bool clean(std::string event);
    std::string print();
    private:
    std::string event;
};

bool cleaner_buy::clean(std::string event) {
    (*this).event = event;
}

std::string cleaner_buy::print() {
    return event;
}


int main() {
    cleaner_buy cb;
    cleaner* cp = &cb;
    cleaner_buy cleaner;

    cleaner.clean("{\"name\": \"buy\"}");
    std::cout << cleaner.print();
    cp->clean("{\"name\": \"sell\"}");
    std::cout << cp->print();
}

