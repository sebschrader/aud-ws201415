/**
 * Compute an element of the Fibonacci sequence tail-recursively.
 *
 * This solution is much more efficient and has the same time-complexity
 * as the iterative solution of O(z).
 */
int fib2(int i, int a, int b) {
    if (i == 0) return a;
    if (i == 1) return b;
    return fib2(i-1, b, a+b);
}

int fib(int z) {
    return fib2(z, 0, 1);
}

