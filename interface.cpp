#include <string>
#include <iostream>

class Mystery {
    public:
    virtual std::string draw() const = 0;
};

class MysteryBox : public Mystery {
    public:
    MysteryBox() : content("shirt") {};
    virtual std::string draw() const;
    private:
    std::string content;
};

std::string MysteryBox::draw() const {
    return content;
}


void print(const Mystery &m) {
    std::cout << m.draw();
}

int main() {
    MysteryBox mbox;
    print(mbox);
}
