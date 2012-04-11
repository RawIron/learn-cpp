#include <iostream>
#include <assert.h>


int defineInForTest() {
    int i = -1;
    for (int i = 0; i < 2; ++i) {
    }
    return i;
}

double defineInIfTest() {
    double d = 0.5;
    if (int d = 5) {
        d = 0;
    }
    return d;
}

int fallThroughDefaultTest() {
    int d = 2;
    switch (int a = 2) {
    case 0: case 1:
        d = 1;
    break;
    case 2:
        d = 0;
    case 3:
        d = -1;
    break;
    default:
        d = 10;
    }
    return d;
}

int fallThroughDefaultTest(int a) {
    int d = 2;
    switch (a) {
    case 0: case 1:
        d = 1;
    break;
    case 2: case 3:
        d = -1;
    break;
    default:
        d = 10;
    }
    return d;
}


int main() {
    double resultIf = defineInIfTest();
    assert(resultIf == 0.5);

    int resultFor = defineInForTest();
    assert(resultFor == -1);

    int resultFall = fallThroughDefaultTest();
    assert(resultFall == -1);
    resultFall = fallThroughDefaultTest(0);
    assert(resultFall == 1);
    resultFall = fallThroughDefaultTest(1);
    assert(resultFall == 1);
}

