#include <iostream>
using namespace std;

class driver {
    public:
    explicit driver() : value(3) {};
    int show() {return value;};
    private:
    int value;
};

class san {
    public:
    explicit san(driver ds) : installed(ds), sector(9) {};
    int read() {return sector;};
    int show() {return installed.show();};
    private:
    driver installed;
    int sector;
};

class storage : public san {
    public:
    explicit storage(driver ds) : san(ds), id(1) {};
    private:
    int id;
};


int main() {
    driver d;
    storage s(d);

    cout << s.read() << s.show();
}

