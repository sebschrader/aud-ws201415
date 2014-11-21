/**
 * Compute an element of the Fibonacci sequence recursively.
 *
 * This solution has horrible performance characteristics of
 * O(2^z).
 */
int fib(int z) {
    if (z == 0) return 0;
    if (z == 1) return 1;
    return fib(z-1) + fib(z-2);
}

