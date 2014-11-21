#include <stdio.h>
#include <math.h>
#include <string.h>

void table(int n) {
    // Calculate digits of the biggest value
    int width = floor(log10(n*n)) + 1;

    // Print header row
    printf("%*c |", width, '*');
    for (int j = 1; j <= n; j++) {
        printf(" %*d", width, j);
    }

    // Print a separating horizontal line
    size_t line_length = (n + 1) * (width + 1) + 1;
    char hline[line_length + 1];
    memset(hline, '-', line_length);
    hline[width + 1] = '+';
    // Terminate string
    hline[line_length] = '\0';
    printf("\n%s\n", hline);

    // This is the actual mandatory part of the assignment
    // Print table contents
    for (int i = 1; i <= n; i++) {
        // Print row description
        printf("%*d |", width, i);

        // Print row contents
        for(int j = 1; j <= n; j++) {
            printf(" %*d", width, i*j);
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    printf("n=");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    table(n);
    return 0;
}

