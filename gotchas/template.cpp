#include <iostream>

template <typename DuckLike>
class Ducktype {
    private:
        DuckLike duck;
    public:
    explicit Ducktype(const DuckLike& myDuck) : duck(myDuck) {}
    void quack() {
        duck.letsHearYourSound();
    }
};


class MyInstrument {
    public:
    void letsHearYourSound() {
        std::cout << "an instrument quacks";
    }
};

int main(int argc, char** argv) {
    MyInstrument violin;
    Ducktype<MyInstrument> ducklike(violin);
    ducklike.quack();
}
