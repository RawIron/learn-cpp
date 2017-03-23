#pragma once
#include <array>
#include <iostream>


class Recipe {
public:
    Recipe() : total(0) {}
    bool prepare();
    virtual int cost() = 0;
    virtual int getTotal() const;
private:
    int total;
};

bool Recipe::prepare() {
    total += cost();
}

int Recipe::getTotal() const {
    return total;
}


class Step : public Recipe {
public:
    Step() : myCost(10) {}
    explicit Step(int aCost) : myCost(aCost) {}
    virtual int cost();
private:
    int myCost;
};

int Step::cost() {
    return myCost;
}



int main() {
    Step s;
    Recipe& r = s;

    r.prepare();
    std::cout << r.getTotal() << std::endl;
    std::cout << s.getTotal() << std::endl;
}

