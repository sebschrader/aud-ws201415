#include <stdlib.h>
#include <stdio.h>

/**
 * Compute the binomial coefficient.
 *
 * The return type is long long int, which is 64-bits wide on common
 * architectures and thus allows bigger numbers to be represented.
 */
long long int binom(int n, int k);

/**
 * This program computes the binomial coefficient using parameters given
 * as arguments instead of input on stdin. First to show how this can be done
 * and second to ease benchmarking.
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s N K\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    printf("binom(%d, %d) = %lld\n", n, k, binom(n, k));
    return 0;
}

