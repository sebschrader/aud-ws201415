#include <stdio.h>

// Forward declaration of faculty as it is used in main, but defined after it
int faculty(int);

int main(void) {
    int n;
    printf("n=");
    if (scanf("%d", &n) != 1) {
        printf("Bad input.\n");
        return 1;
    }
    if (n < 0) {
        printf("n must be greater than or equal to 0.\n");
        return 1;
    }
    printf("n!=%d\n", faculty(n));
    return 0;
}

int faculty(int n) {
    int p = 1;
    for (int i = 1; i <= n; i++) {
        p *= i;
    }
    return p;
}

