/**
 * operators
 *
 * are first sorted according to precedence
 * with same precedence are sorted according to associativity
 */
#include <iostream>
#include <assert.h>


void incrementTest() {
    int a[] = {1,2,3};
    int i = 0;

    a[i] = i++;
    assert(a[0] == 0);
}

void arrayLeftRightTest() {
    int a[4][2] = {{1,2},{3,4},{5,6},{7,8}};
    int index = 0, b = 0;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2; ++j)
            std::cout << i << j << ':' << a[i][j] << std::endl;

    b = a[index][++index];
    assert(b == 4);
}

void drefClassMemberTest() {
    class t {public: int* a;} d;
    t* pd;
    int* t::* pd_a = &t::a;
    int i = 2;
    int* b = &i;

    d.a = b;
    pd = &d;
    assert(pd->a == b);
    assert(*(pd->a) == 2);
    assert(*(pd->*pd_a) == 2);
}


int main() {
    incrementTest();
    arrayLeftRightTest();
    drefClassMemberTest();
}

