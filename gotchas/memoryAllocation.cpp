#include <math.h>
#include <assert.h>


int localArrayTest() {
    const int size = 100;
    long a[size];

    assert(sizeof(a) == size * sizeof(long));

    for (int i = 0; i < size; ++i) {
        a[i] = sqrt(i+1);
    }
}

int main() {
    localArrayTest();
}
