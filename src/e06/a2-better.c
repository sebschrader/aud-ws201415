/**
 * Compute the binomial coefficient slightly more efficient by computing
 * the faculty in the numerator only up to n-k.
 */
long long int binom(int n, int k) {
    long long int num = 1, denom = 1;
    // Use the symmetry property of the binomial coefficient
    if (k > n - k) {
        k = n - k;
    }
    for (int i = n - k + 1; i <= n; i++) {
        num *= i;
    }
    for (int i = 1; i <= k; i++) {
        denom *= i;
    }
    return num/denom;
}

