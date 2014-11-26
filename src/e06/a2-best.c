/**
 * Compute the binomial coefficient by computing the faculties in the numerator
 * and denominator together and dividing during each step.
 */
long long int binom(int n, int k) {
    long long int b = 1;
    // Use symmetry again
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 1; i <= k; i++) {
        // Multiply and divide in succession to keep b small
        b *= (n - i + 1);
        b /= i;
    }
    return b;
}

