#include <stdio.h>

int fib(int);

int main(void) {
    int z;
    printf("z=");
    if (scanf("%d", &z) != 1) {
        printf("Invalid input!");
        return 1;
    }
    printf("fib(%d)=%d\n", z, fib(z));
    return 0;
}

