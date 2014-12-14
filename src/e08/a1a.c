#include <stdlib.h>

typedef struct listElement *list;
typedef struct listElement {
    int value;
    list next;
} listElement;

int f(list l) {
    if (l == NULL) {
        return 1;
    }
    for (int last = l->value - 1; l != NULL; last = l->value, l = l->next) {
        if (abs(last - l->value) != 1) {
            return 0;
        }
    }
    return 1;
}

