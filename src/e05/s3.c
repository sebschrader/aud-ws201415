#include <stdio.h>

void probe(int cx, int cy) {
    int x = 0;
    int y = 0;
    for (int i = 0; i <= 1000; i++) {
        if (x * x + y * y >= 4) {
            printf("i=%d", i);
            return;
        }
        int next_y = cx + x*x - y*y;
        int next_x = cy + 2*x*y;
        x = next_x;
        y = next_y;
    }
    printf(">1000");
}

int main(void) {
    int cx, cy;
    printf("cx=");
    if (scanf("%d", &cx) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    printf("cy=");
    if (scanf("%d", &cy) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    probe(cx, cy);
    return 0;
}

