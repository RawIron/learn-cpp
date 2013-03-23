#include <iostream>
#include <list>
#include <assert.h>
using std::cout;
using std::endl;


template <typename TYPE>
class holder {
public:
    explicit holder(TYPE first) : stored(first) {}
    void store(TYPE h) { stored = h; }
    TYPE ref() { return stored; }
private:
    TYPE stored;
};

void refBy(holder<int &> &s) {
    int m = 8;
    s.store(m);
}

void pointBy(holder<int *> &s) {
    int m = 6;
    s.store(&m);
}


void h(void) {
    int *o = new int(3);
    int* &a = o;
    *o=4;
    assert(*a == 4);
}

int f(int &no) {
    return --no;
}


int main() {
    h();

    int n = 4;
    int &nr = n;
    assert(f(nr) == 3);
    assert(nr == 3);
    assert(n == 3);

    holder<int &> stash(++n);
    refBy(stash);
    assert(stash.ref() == 8);

    holder<int *> stack(&++n);
    pointBy(stack);
    cout << "point:" << *(stack.ref()) <<endl;
}

