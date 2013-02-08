#include <iostream>
#include <list>
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


void h(void) {
    int *o = new int(3);
    int* &a = o;
    *o=4;
    cout << *a <<endl;
}

int f(int &no) {
    return --no;
}


void refBy(holder<int &> &s) {
    int m = 8;
    s.store(m);
}

void pointBy(holder<int *> &s) {
    int m = 6;
    s.store(&m);
}


int main() {
    h();

    int n = 4;
    int &nr = n;
    cout << f(nr);
    cout << nr << n << endl;

    holder<int &> stash(++n);
    refBy(stash);
    cout << "ref:" << stash.ref() << endl;

    holder<int *> stack(&++n);
    pointBy(stack);
    cout << "point:" << *(stack.ref()) <<endl;
}

