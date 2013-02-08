#include <iostream>
#include <string>

class listException {
    public:
    listException() : errorString("unknown") {};
    explicit listException(std::string text) : errorString(text) {};
    std::string message();
    private:
    std::string errorString;
};

std::string listException::message() {
    return errorString;
}


template <class T>
struct element {
    T data;
    element* next;
};

template <class T>
element<T>* createElement(T data) {
    if (!data) {
        throw listException("no data");
    }
    element<T>* e = new element<T>;
    e->data = data;
    e->next = 0;
    return e;
}

template <class T>
element<T>* push(element<T>* anchor, element<T>* first) {
    first->next = anchor;
    return first;
}


int main() {
    int data = 6;
    element<int>* anchor;
    element<int>* e;

    anchor = 0;
    e = createElement(data);

    anchor = push(anchor, e);
    std::cout << anchor->data << std::endl;

    try {
        data = 0;
        e = createElement(data);
    } catch(listException e) {
        std::cout << e.message() << std::endl;
    }
}

