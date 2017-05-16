#include <stdlib.h>

double *ones(int m, int n) {
    double *a = (double *) malloc(m*n*sizeof(double));

    for (int k=0; k<m*n; ++k) {
        a[k] = 1.0;
    }

    return a;
}


int main(void) {
    double *matrix = ones(10,10);
    return 0;
}
