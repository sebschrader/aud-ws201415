#include <stdio.h>

int ack(int x, int y) {
    if (x == 0) return y + 1;
    if (y == 0) return ack(x - 1, 1);
    return ack(x - 1, ack(x, y - 1));
}

int main(void) {
    int x, y;
    printf("x=");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input!");
        return 1;
    }
    printf("y=");
    if (scanf("%d", &y) != 1) {
        printf("Invalid input!");
        return 1;
    }
    printf("ack(%d, %d) = %d\n", x, y, ack(x, y));
    return 0;
}

