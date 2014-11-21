/**
 * Compute an element of the Fibonacci sequence iteratively.
 *
 * This solution has an time complexity of O(z).
 */
int fib(int z) {
    int a = 0, b = 1;
    for (int i = 0; i < z; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

