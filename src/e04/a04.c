#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ELEMENTS(array) (sizeof(array)/sizeof(array[0]))

int bills[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

/**
 * Greedy algorithm for solving the change-making problem.
 * This algorithm is only correct for specific bill values.
 * Consider adding a bill with value 16. This algorithm would produce
 * 1x10,1x5,1x1, although 2x8 is the correct solutions.
 */
int main(int argc, char *argv[]) {
    unsigned int value;
    printf("Enter amount: ");
    if (scanf("%u", &value) != 1) {
        printf("Bad input.\n");
        return 1;
    }
    printf("Denominations for %u:\n", value);
    int picked[ELEMENTS(bills)];
    memset(picked, 0, sizeof(picked));
    for (int i = 0; i < ELEMENTS(bills); i++) {
        // div combines division (/) and module (%)
        div_t q = div(value, bills[i]);
        picked[i] = q.quot;
        value = q.rem;
        printf("%d: %d\n", bills[i], picked[i]);
    }
    return 0;
}

