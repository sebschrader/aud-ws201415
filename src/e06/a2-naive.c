long long int fac(int n) {
    long long int p = 1;
    for (int i = 1; i <= n; i++) {
        p *= i;
    }
    return p;
}

/**
 * Compute the binomial coefficient naively by computing its components.
 */
long long int binom(int n, int k) {
    return fac(n)/(fac(k) * fac(n-k));
}

