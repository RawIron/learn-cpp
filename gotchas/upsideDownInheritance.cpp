/**
 * substitute different base classes
 * ideally it should be a trait
 * dependency does not allow this
 *
 * helpful for refactoring
 */

#include <iostream>
#include <list>

class inventory {
private:
    std::list<int> items = {1,3};
public:
    void print() {
        std::list<int>::iterator i;
        for(i = items.begin(); i != items.end(); ++i)
            std::cout << *i << " ";
        std::cout << std::endl;
    }
};


template <class T>
class monitor {
public:
    void list_items() { static_cast<T*>(this)->print(); }
};


class composed : public inventory, public monitor<composed> {
public:
    composed() {}
    virtual ~composed() {}
};


int main(int argc, char* argv[]) {
    composed cards;
    cards.list_items();
    exit(0);
}
